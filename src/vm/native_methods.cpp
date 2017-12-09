#include "vm/native_methods.h"

#include <stdlib.h>

#include "base/annotation.h"
#include "base/annotation_builder.h"
#include "base/pool.h"
#include "base/status.h"
#include "numeric/numeric_op.h"  // from iroha
#include "synth/synth.h"
#include "synth/object_method_names.h"
#include "vm/method.h"
#include "vm/object.h"
#include "vm/string_wrapper.h"
#include "vm/thread.h"
#include "vm/thread_wrapper.h"
#include "vm/value.h"
#include "vm/vm.h"

namespace vm {

void NativeMethods::Assert(Thread *thr, Object *obj,
			   const vector<Value> &args) {
  CHECK(args.size() == 1) << "Assert got " << args.size() << "args.";
  const Value &arg = args[0];
  VM *vm = thr->GetVM();
  CHECK(arg.type_ == Value::ENUM_ITEM) << "Assert argument is not an enum item";
  CHECK(arg.enum_val_.enum_type == vm->bool_type_);
  if (arg.enum_val_.val == 0) {
    cout << "ASSERTION FAILURE\n";
  }
}

void NativeMethods::Clone(Thread *thr, Object *obj,
			  const vector<Value> &args) {
  Value value;
  value.type_ = Value::OBJECT;
  value.object_ = obj->Clone(thr->GetVM());
  SetReturnValue(thr, value);
}

void NativeMethods::Dump(Thread *thr, Object *obj,
			 const vector<Value> &args) {
  obj->Dump();
}

void NativeMethods::Exit(Thread *thr, Object *obj,
			 const vector<Value> &args) {
  thr->Exit();
}

void NativeMethods::Main(Thread *thr, Object *obj,
			 const vector<Value> &args) {
  // do nothing.
}

void NativeMethods::Print(Thread *thr, Object *obj,
			  const vector<Value> &args) {
  cout << "print: ";
  for (size_t i = 0; i < args.size(); ++i) {
    args[i].Dump(cout);
    cout << "\n";
  }
}


void NativeMethods::Run(Thread *thr, Object *obj,
			const vector<Value> &args) {
  ThreadWrapper::Run(thr->GetVM(), obj);
}

void NativeMethods::SetAddressWidth(Thread *thr, Object *obj,
				    const vector<Value> &args) {
  if (args.size() != 1 || args[0].type_ != Value::NUM) {
    Status::os(Status::USER_ERROR) << "Only 1 int argument is allowed";
    thr->UserError();
    return;
  }
  int w = args[0].num_.GetValue0();
  if (w == 32 || w == 64) {
    obj->address_width_ = w;
  } else {
    Status::os(Status::USER_ERROR) << w << " is invalid address width.";
    thr->UserError();
  }
}

void NativeMethods::SetDump(Thread *thr, Object *obj,
			    const vector<Value> &args) {
  SetMemberString(thr, "$dump_file_name", obj, args);
}

void NativeMethods::SetIROutput(Thread *thr, Object *obj,
				const vector<Value> &args) {
  SetMemberString(thr, "$ir_file_name", obj, args);
}

void NativeMethods::SetIrohaPath(Thread *thr, Object *obj,
				 const vector<Value> &args) {
  if (Env::IsSandboxMode()) {
    Status::os(Status::USER_ERROR)
      << "SetIrohaPath() is not allowed on sandbox mode";
    thr->UserError();
    return;
  }
  SetMemberString(thr, "$iroha_path", obj, args);
}

void NativeMethods::RunIroha(Thread *thr, Object *obj,
			     const vector<Value> &args) {
  if (Env::IsSandboxMode()) {
    Status::os(Status::USER_ERROR)
      << "RunIroha() is not allowed on sandbox mode";
    thr->UserError();
    return;
  }
  if (args.size() != 1 || args[0].type_ != Value::OBJECT ||
      !StringWrapper::IsString(args[0].object_)) {
    Status::os(Status::USER_ERROR) << "Missing argument for runIroha()";
    thr->UserError();
    return;
  }
  int res =
    synth::Synth::RunIroha(obj, StringWrapper::String(args[0].object_));
  if (res != 0) {
    Status::os(Status::USER_ERROR) << "runIroha() failed: " << res;
    thr->UserError();
  }
}

void NativeMethods::Synth(Thread *thr, Object *obj,
			   const vector<Value> &args) {
  if (args.size() != 1 || args[0].type_ != Value::OBJECT ||
      !StringWrapper::IsString(args[0].object_)) {
  }
  synth::Synth::Synthesize(thr->GetVM(), obj,
			   StringWrapper::String(args[0].object_));
}

void NativeMethods::SetMemberString(Thread *thr, const char *name,
				    Object *obj,
				    const vector<Value> &args) {
  if (args.size() == 1 && args[0].type_ == Value::OBJECT &&
      StringWrapper::IsString(args[0].object_)) {
    const string &fn = StringWrapper::String(args[0].object_);
    Value value;
    value.object_ = StringWrapper::NewStringWrapper(thr->GetVM(), fn);
    value.type_ = Value::OBJECT;
    obj->InstallValue(sym_lookup(name), value);
  }
}

void NativeMethods::Compile(Thread *thr, Object *obj,
			    const vector<Value> &args) {
  string phase;
  if (args.size() == 1) {
    CHECK(StringWrapper::IsString(args[0].object_));
    phase = StringWrapper::String(args[0].object_);
  }
  if (phase.empty()) {
    bool ok = synth::Synth::Synthesize(thr->GetVM(), obj,
				       synth::Synth::IrPath(obj));
    if (!ok) {
      Status::os(Status::USER_ERROR) << "Failed to synthesize the design.";
      thr->UserError();
    }
  } else {
    int res = synth::Synth::RunIrohaOpt(phase, obj);
    if (res > 0) {
      Status::os(Status::USER_ERROR) << "compile(" << phase << ") failed.";
      thr->UserError();
    }
  }
}

void NativeMethods::SetSynthParam(Thread *thr, Object *obj,
				  const vector<Value> &args) {
  if (args.size() != 2 ||
      (args[0].type_ != Value::OBJECT ||
       !StringWrapper::IsString(args[0].object_))) {
    Status::os(Status::USER_ERROR)
      << "setSynthParam() requires 2 arguments and 1st argument should be a string.";
    thr->UserError();
    return;
  }
  if ((args[1].type_ != Value::OBJECT ||
       !StringWrapper::IsString(args[1].object_)) &&
      args[1].type_ != Value::NUM) {
    Status::os(Status::USER_ERROR) << "setSynthParam() requires a string or integer value.";
    thr->UserError();
    return;
  }
  sym_t synth_params = sym_lookup("$synth_params");
  Value *value = obj->LookupValue(synth_params, true);
  if (value->type_ == Value::NONE) {
    value->type_ = Value::ANNOTATION;
    value->annotation_ = AnnotationBuilder::Build(synth_params, nullptr);
  }
  string key = StringWrapper::String(args[0].object_);
  if (args[1].type_ == Value::NUM) {
    value->annotation_->AddIntParam(key, args[1].num_.GetValue0());
  } else {
    value->annotation_->AddStrParam(key,
				    StringWrapper::String(args[1].object_));
  }
}

void NativeMethods::WidthOf(Thread *thr, Object *obj,
			    const vector<Value> &args) {
  if (args.size() != 1 || args[0].type_ != Value::NUM) {
    Status::os(Status::USER_ERROR) << "Invalid argument to widthof()";
    MessageFlush::Get(Status::USER_ERROR);
    thr->UserError();
    return;
  }
  Value value;
  value.type_ = Value::NUM;
  iroha::Op::MakeConst(args[0].num_.type_.GetWidth(),
		       &value.num_);
  SetReturnValue(thr, value);
}

void NativeMethods::Wait(Thread *thr, Object *obj,
			 const vector<Value> &args) {
}

void NativeMethods::WriteHdl(Thread *thr, Object *obj,
			     const vector<Value> &args) {
  CHECK(args.size() == 1);
  const Value& arg = args[0];
  CHECK(StringWrapper::IsString(arg.object_));
  synth::Synth::WriteHdl(StringWrapper::String(arg.object_), obj);
}

void NativeMethods::IsMain(Thread *thr, Object *obj,
			   const vector<Value> &args) {
  Value value;
  value.type_ = Value::ENUM_ITEM;
  value.enum_val_.enum_type = thr->GetVM()->bool_type_;
  value.enum_val_.val = thr->IsRootThread() ? 1 : 0;
  SetReturnValue(thr, value);
}

void NativeMethods::GC(Thread *thr, Object *obj,
		       const vector<Value> &args) {
  thr->GetVM()->GC();
}

void NativeMethods::SetReturnValue(Thread *thr, const Value &value) {
  thr->SetReturnValueFromNativeMethod(value);
}

void Method::InstallNativeRootObjectMethods(VM *vm, Object *obj) {
  vector<RegisterType> rets;
  rets.push_back(ObjectType());
  InstallNativeMethod(vm, obj, "clone", &NativeMethods::Clone, rets);
  rets.clear();
  InstallNativeMethod(vm, obj, "dump", &NativeMethods::Dump, rets);
  InstallNativeMethod(vm, obj, "run", &NativeMethods::Run, rets);
}

void Method::InstallNativeKernelObjectMethods(VM *vm, Object *obj) {
  vector<RegisterType> rets;
  InstallNativeMethodWithAltImpl(vm, obj, "wait", &NativeMethods::Wait, rets, "__wait");
  Method *m;
  m = InstallNativeMethod(vm, obj, "print", &NativeMethods::Print, rets);
  m->SetSynthName(synth::kPrint);
  m = InstallNativeMethod(vm, obj, "assert", &NativeMethods::Assert, rets);
  m->SetSynthName(synth::kAssert);
  InstallNativeMethod(vm, obj, "compile", &NativeMethods::Compile, rets);
  InstallNativeMethod(vm, obj, "__compile", &NativeMethods::Compile, rets);
  InstallNativeMethodWithAltImpl(vm, obj, "exit", &NativeMethods::Exit, rets, "__exit");
  m = InstallNativeMethod(vm, obj, "main", &NativeMethods::Main, rets);
  m->SetSynthName(synth::kMain);
  InstallNativeMethod(vm, obj, "setAddressWidth", &NativeMethods::SetAddressWidth, rets);
  InstallNativeMethod(vm, obj, "setDump", &NativeMethods::SetDump, rets);
  InstallNativeMethod(vm, obj, "setIROutput", &NativeMethods::SetIROutput, rets);
  InstallNativeMethod(vm, obj, "setIrohaPath", &NativeMethods::SetIrohaPath, rets);
  InstallNativeMethod(vm, obj, "runIroha", &NativeMethods::RunIroha, rets);
  InstallNativeMethod(vm, obj, "synth", &NativeMethods::Synth, rets);
  InstallNativeMethod(vm, obj, "setSynthParam",
		      &NativeMethods::SetSynthParam, rets);
  InstallNativeMethod(vm, obj, "widthof", &NativeMethods::WidthOf, rets);
  InstallNativeMethod(vm, obj, "writeHdl", &NativeMethods::WriteHdl, rets);
}

Method *Method::InstallNativeMethodWithAltImpl(VM *vm, Object *obj,
					       const char *name,
					       method_func func,
					       const vector<RegisterType> &ret_types,
					       const char *alt) {
  Method *method = vm->NewMethod(false /* not toplevel */);
  method->SetMethodFunc(func);
  method->SetAlternativeImplementation(alt);
  method->return_types_ = ret_types;
  Value value;
  value.type_ = Value::METHOD;
  value.method_ = method;
  obj->InstallValue(sym_lookup(name), value);
  return method;
}

Method *Method::InstallNativeMethod(VM *vm, Object *obj, const char *name,
				    method_func func,
				    const vector<RegisterType> &ret_types) {
  return InstallNativeMethodWithAltImpl(vm, obj, name, func, ret_types,
					nullptr);
}

void Method::InstallEnvNativeMethods(VM *vm, Object *env) {
  vector<RegisterType> rets;
  InstallNativeMethod(vm, env, "gc", &NativeMethods::GC, rets);
  rets.push_back(BoolType(vm));
  InstallNativeMethod(vm, env, "isMain", &NativeMethods::IsMain, rets);
}

RegisterType Method::ObjectType() {
  iroha::NumericWidth dw;
  return RegisterType(Value::OBJECT, nullptr, dw, sym_null, false);
}

RegisterType Method::BoolType(VM *vm) {
  iroha::NumericWidth dw;
  return RegisterType(Value::ENUM_ITEM, vm->bool_type_, dw,
		      sym_null, false);
}

RegisterType Method::IntType(int w) {
  return RegisterType(Value::NUM, nullptr,
		      iroha::NumericWidth(false, w), sym_null,
		      false);
}

}  // namespace vm
