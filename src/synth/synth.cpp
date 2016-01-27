// Front end of the synthesizer.
//
//  Synth
//  -> ObjectSynth DModule
//     -> ThreadSynth DModule, DGraph, DResource
//         -> MethodSynth
//
#include "synth/synth.h"

#include "dfg/dfg.h"
#include "dfg/resource_params.h"
#include "opt/opt.h"
#include "opt/opt_context.h"
#include "pool.h"
#include "synth/channel_synth.h"
#include "synth/iroha_dumper.h"
#include "synth/object_synth.h"
#include "vm/dmodule_wrapper.h"
#include "vm/object.h"
#include "writer/writer.h"

static Pool<DModule> dmodule_pool_;

namespace synth {

static const char *kCompiledModule = "_compiled_module";

Synth::Synth(vm::VM *vm, vm::Object *obj) : vm_(vm), obj_(obj) {
}

bool Synth::Compile(const string &phase) {
  vm::Value *value =
    obj_->LookupValue(sym_lookup(kCompiledModule), false);
  if (!value || value->type_ != vm::Value::DMODULE) {
    // Runs the first phase.
    DModule *dmod = SynthModule();
    if (!dmod) {
      return false;
    }

    value = obj_->LookupValue(sym_lookup(kCompiledModule), true);
    value->type_ = vm::Value::DMODULE;
    value->object_ = vm::DModuleWrapper::NewDModuleWrapper(vm_, dmod);
  }

  if (!phase.empty()) {
    DModule *mod = vm::DModuleWrapper::GetDModule(value->object_);
    opt::ModuleOptimizeStat::Optimize(mod, phase, "");
    mod->GetOptimizeContext()->WriteDumpIndex();
  }
  return true;
}

DModule *Synth::SynthModule() {
  LOG(DEBUG) << "Synth start";
  set<sym_t> entry_methods;
  ObjectSynth obj_synth(vm_, obj_, "main", entry_methods,
			/* parent_module */ nullptr);
  DModule *module = obj_synth.GetDModule();
  dmodule_pool_.Add(module);
  SetDumpFileName(module);
  SetSynthParams(module);
  if (!obj_synth.Synth()) {
    return NULL;
  }

  ChannelSynth::ResolveChannels(module);

  module->GetOptimizeContext()->DumpIntermediateModule(NULL, "raw");
  obj_synth.ExpandFunctions();
  module->GetOptimizeContext()->DumpIntermediateModule(NULL, "expanded");

  vm::Value *value = obj_->LookupValue(sym_lookup("$ir_file_name"), false);
  if (value && value->type_ == vm::Value::OBJECT) {
    const string &fn = value->object_->ToString();
    string path;
    if (Env::GetOutputPath(fn.c_str(), &path)) {
      IrohaDumper::Dump(module, path);
    }
  }
  // Let obj_synth be deleted.

  return module;
}

void Synth::SetDumpFileName(DModule *module) {
  vm::Value *value = obj_->LookupValue(sym_lookup("$dump_file_name"), false);
  if (value && value->type_ == vm::Value::OBJECT) {
    const string &fn = value->object_->ToString();
    string path;
    if (Env::GetOutputPath(fn.c_str(), &path)) {
      module->GetOptimizeContext()->SetDumpFn(path.c_str());
    }
  }
}

void Synth::SetSynthParams(DModule *module) {
  vm::Value *value = obj_->LookupValue(sym_lookup("$synth_params"), false);
  if (!value) {
    return;
  }
  module->synth_params_ = new ResourceParams(*value->resource_params_);
}

bool Synth::Synthesize(vm::VM *vm, const string &phase, vm::Object *obj) {
  Synth synth(vm, obj);
  return synth.Compile(phase);
}

void Synth::WriteHdl(const string &fn, vm::Object *obj) {
  vm::Value *value =
    obj->LookupValue(sym_lookup(kCompiledModule), false);
  CHECK(value);
  writer::Writer::WriteModule(vm::DModuleWrapper::GetDModule(value->object_),
			      fn);
}

}  // namespace synth
