#include "synth/thread_synth.h"

#include "base/annotation.h"
#include "base/status.h"
#include "compiler/compiler.h"
#include "fe/method.h"
#include "iroha/iroha.h"
#include "synth/design_synth.h"
#include "synth/method_expander.h"
#include "synth/method_scanner.h"
#include "synth/method_synth.h"
#include "synth/object_synth.h"
#include "synth/shared_resource_set.h"
#include "synth/resource_set.h"
#include "synth/resource_synth.h"
#include "synth/tool.h"
#include "vm/array_wrapper.h"
#include "vm/object.h"
#include "vm/method.h"

namespace synth {

ThreadSynth::ThreadSynth(ObjectSynth *obj_synth,
			 const string &thread_name,
			 const string &entry_method_name,
			 vm::Object *thread_obj)
  : obj_synth_(obj_synth),
    thread_name_(thread_name), entry_method_name_(entry_method_name),
    is_primary_thread_(false),
    thread_obj_(thread_obj),
    tab_(nullptr),
    is_task_(false),
    reg_name_index_(0) {
}

ThreadSynth::~ThreadSynth() {
}

bool ThreadSynth::Scan() {
  tab_ = new ITable(obj_synth_->GetIModule());
  tab_->SetName(thread_name_);
  resource_.reset(new ResourceSet(tab_));
  rsynth_.reset(new ResourceSynth(resource_.get(), this));
  // Entry method of this thread.
  RequestMethod(obj_synth_->GetObject(), entry_method_name_);
  int num_scan;
  map<vm::Object *, set<string>> scanned;
  do {
    num_scan = 0;
    // Every object in this thread.
    for (auto &it : obj_methods_) {
      vm::Object *obj = it.first;
      map<string, MethodSynth *> &methods = it.second.methods_;
      for (auto jt : methods) {
	auto &name = jt.first;
	auto &m = scanned[obj];
	if (m.find(name) != m.end()) {
	  continue;
	}
	++num_scan;
	MethodScanner ms(this, obj, name);
	if (!ms.Scan()) {
	  Status::os(Status::USER) << "Failed to scan thread: "
				   << thread_name_ << "." << entry_method_name_;
	  MessageFlush::Get(Status::USER);
	  return false;
	}
	scanned[obj].insert(name);
      }
    }
  } while (num_scan > 0);

  return true;
}

bool ThreadSynth::Synth() {
  // Prepares MethodSynth objects for all methods.
  for (auto &it : obj_methods_) {
    vm::Object *obj = it.first;
    for (auto jt : it.second.methods_) {
      auto &name = jt.first;
      auto *ms = new MethodSynth(this, obj, name,
				 tab_, rsynth_.get(), resource_.get());
      obj_methods_[obj].methods_[name] = ms;
    }
  }
  MethodSynth *root_method =
    obj_methods_[obj_synth_->GetObject()].methods_[entry_method_name_];
  if (is_task_) {
    root_method->SetTaskEntry();
  }
  if (root_method->IsDataFlowEntry()) {
    root_method->SetRoot();
  }
  // Actually synthesize all.
  for (auto &it : obj_methods_) {
    for (auto jt : it.second.methods_) {
      if (!jt.second->Synth()) {
	Status::os(Status::USER) << "Failed to synthesize thread: "
				 << thread_name_ << "." << entry_method_name_;
	MessageFlush::Get(Status::USER);
	return false;
      }
    }
  }

  MethodExpander expander(root_method->GetContext(), this,
			  &sub_obj_calls_, &data_flow_calls_);
  expander.Expand();

  obj_synth_->GetIModule()->tables_.push_back(tab_);
  return true;
}

void ThreadSynth::SetPrimary() {
  is_primary_thread_ = true;
}

bool ThreadSynth::IsPrimary() {
  return is_primary_thread_;
}

void ThreadSynth::CollectUnclaimedMembers() {
  DesignSynth *ds = obj_synth_->GetDesignSynth();
  SharedResourceSet *sres = ds->GetSharedResourceSet();
  vm::Object *obj = obj_synth_->GetObject();
  map<sym_t, vm::Object *> member_objs;
  obj->GetAllMemberObjs(&member_objs);
  for (auto it : member_objs) {
    vm::Object *member_obj = it.second;
    if (vm::ArrayWrapper::IsIntArray(member_obj)) {
      if (sres->HasAccessor(member_obj)) {
	continue;
      }
      rsynth_->MayAddAxiMasterPort(obj_synth_->GetObject(), member_obj);
      rsynth_->MayAddAxiSlavePort(obj_synth_->GetObject(), member_obj);
    }
  }
  map<sym_t, vm::Method *> member_methods;
  obj->GetAllMemberMethods(&member_methods);
  for (auto it : member_methods) {
    vm::Method *method = it.second;
    if (method->parse_tree_ != nullptr &&
	method->parse_tree_->annotation_ != nullptr) {
      if (method->parse_tree_->annotation_->IsExtIO()) {
	compiler::Compiler::CompileMethod(obj_synth_->GetVM(),
					  obj, method->parse_tree_,
					  method);
	if (method->parse_tree_->annotation_->IsExtInput()) {
	  MayGenerateExtIOMethod(method, false);
	}
	if (method->parse_tree_->annotation_->IsExtOutput()) {
	  MayGenerateExtIOMethod(method, true);
	}
      }
    }
  }
}

void ThreadSynth::MayGenerateExtIOMethod(vm::Method *method, bool is_output) {
  rsynth_->MayAddExtIO(method, is_output);
}

void ThreadSynth::SetIsTask(bool is_task) {
  is_task_ = is_task;
}

void ThreadSynth::RequestMethod(vm::Object *obj, const string &m) {
  obj_methods_[obj].methods_[m] = nullptr;
}

MethodContext *ThreadSynth::GetMethodContext(vm::Object *obj,
					     const string &m) {
  return obj_methods_[obj].methods_[m]->GetContext();
}

ResourceSet *ThreadSynth::GetResourceSet() {
  return resource_.get();
}

ObjectSynth *ThreadSynth::GetObjectSynth() {
  return obj_synth_;
}

ITable *ThreadSynth::GetITable() {
  return tab_;
}

vm::Object *ThreadSynth::GetThreadObject() {
  return thread_obj_;
}

void ThreadSynth::AddName(const string &n) {
  used_reg_names_.insert(n);
}

IRegister *ThreadSynth::AllocRegister(const string &prefix) {
  string n;
  do {
    char buf[10];
    sprintf(buf, "_%d", reg_name_index_);
    n = prefix + string(buf);
    ++reg_name_index_;
  } while (used_reg_names_.find(n) != used_reg_names_.end());
  used_reg_names_.insert(n);
  IRegister *reg = new IRegister(tab_, n);
  return reg;
}

vector<TableCall> &ThreadSynth::GetSubObjCalls() {
  return sub_obj_calls_;
}

vector<TableCall> &ThreadSynth::GetDataFlowCalls() {
  return data_flow_calls_;
}

const string &ThreadSynth::GetEntryMethodName() {
  return entry_method_name_;
}

void ThreadSynth::InjectSubModuleCall(IState *st, IInsn *pseudo_call_insn,
				      ITable *callee_tab) {
  ITable *caller_tab = st->GetTable();
  IResource *call_res = Tool::FindOrCreateTaskCallResource(caller_tab,
							   callee_tab);
  // Argument values.
  IInsn *iinsn = new IInsn(call_res);
  st->insns_.push_back(iinsn);
  for (IRegister *reg : pseudo_call_insn->inputs_) {
    iinsn->inputs_.push_back(reg);
  }
  // Return values.
  if (pseudo_call_insn->outputs_.size() == 0) {
    return;
  }
  // State allocated for funcall_done to inject return.
  IState *next_st = Tool::GetNextState(st);
  CHECK(next_st);
  IResource *ret =
    Tool::FindOrCreateTaskReturnValueResource(caller_tab, callee_tab);
  if (ret == nullptr) {
    // TODO: This shouldn't happen. Put CHECK(false) here.
    // outputs_.size() == 1 in case of void return due to the default
    // return reg.
    return;
  }
  IInsn *ret_insn = new IInsn(ret);
  ret_insn->SetOperand(iroha::operand::kWaitNotify);
  next_st->insns_.push_back(ret_insn);
  for (IRegister *reg : pseudo_call_insn->outputs_) {
    ret_insn->outputs_.push_back(reg);
  }
}

void ThreadSynth::InjectDataFlowCall(ThreadSynth *thr,
				     IState *st, IInsn *pseudo_call_insn,
				     ITable *callee_tab) {
  vector<IResource *> df;
  DesignUtil::FindResourceByClassName(callee_tab, resource::kDataFlowIn,
				      &df);
  CHECK(df.size() == 1);
  IResource *sreg = df[0]->GetParentResource();
  ITable *caller_tab = st->GetTable();
  IResource *w = Tool::FindOrCreateDataFlowCaller(caller_tab, sreg);
  IInsn *iinsn = new IInsn(w);
  iinsn->SetOperand(iroha::operand::kNotify);
  st->insns_.push_back(iinsn);
  for (IRegister *reg : pseudo_call_insn->inputs_) {
    iinsn->inputs_.push_back(reg);
  }
  if (pseudo_call_insn->inputs_.size() == 0) {
    // Adds a dummy argument.
    IRegister *reg = thr->AllocRegister("df_arg");
    reg->value_type_.SetWidth(1);
    iroha::Numeric iv;
    iv.SetValue(0);
    reg->SetInitialValue(iv);
    iinsn->inputs_.push_back(reg);
    thr->GetITable()->registers_.push_back(reg);
  }
}

}  // namespace synth
