// Front end of the synthesizer.
//
//  Synth
//    DesignSynth IDesign
//    -> ObjectSynth IModule
//       -> ThreadSynth ITable, IResource
//         -> MethodSynth
//
#include "synth/synth.h"

#include <sys/types.h>
#include <unistd.h>

#include "base/util.h"
#include "iroha/iroha.h"
#include "synth/design_synth.h"
#include "vm/object.h"
#include "vm/string_wrapper.h"

namespace synth {

bool Synth::Synthesize(vm::VM *vm, vm::Object *obj, const string &ofn) {
  DesignSynth design_synth(vm, obj);
  LOG(INFO) << "Synthesize start";
  if (!design_synth.Synth()) {
    return false;
  }
  LOG(INFO) << "Synthesize done";

  WriterAPI *writer = Iroha::CreateWriter(design_synth.GetIDesign());
  writer->SetLanguage("");
  writer->Write(ofn);
  return true;
}

string Synth::IrPath(vm::Object *obj) {
  vm::Value *value = obj->LookupValue(sym_lookup("$ir_file_name"), false);
  if (value && value->type_ == vm::Value::OBJECT) {
    const string &fn = value->object_->ToString();
    string path;
    if (Env::GetOutputPath(fn.c_str(), &path)) {
      return path;
    }
  }
  char buf[128];
  sprintf(buf, "/tmp/karuta-%d-%ld.iroha", getpid(), (long)obj);
  return string(buf);
}

string Synth::GetIrohaCommand(vm::Object *obj) {
  vm::Value *cmd = obj->LookupValue(sym_lookup("$iroha_path"), false);
  if (!cmd || cmd->type_ != vm::Value::OBJECT ||
      !vm::StringWrapper::IsString(cmd->object_)) {
    const string &bin = Env::GetIrohaBinPath();
    if (!bin.empty()) {
      return bin;
    }
    return Env::GetArgv0();
  }
  return vm::StringWrapper::String(cmd->object_);
}

int Synth::RunIroha(vm::Object *obj, const string &args) {
  string cmd = GetIrohaCommand(obj);
  if (cmd.empty()) {
    return -1;
  }
  string path = IrPath(obj);
  string iopt = "--iroha";
  auto dirs = Env::SearchDirList();
  for (auto &d : dirs) {
    iopt += " -I " + d;
  }
  string e = cmd + " " + iopt + " " +
    path + " " + args;
  cout << "command=" << e << "\n";
  LOG(INFO) << "Executing iroha";
  int r = system(e.c_str());
  LOG(INFO) << "Done";
  return r;
}

void Synth::WriteHdl(const string &fn, vm::Object *obj) {
  string lang = "-v";
  if (::Util::IsHtmlFileName(fn)) {
    lang = "-h";
  } else if (::Util::IsCCFileName(fn)) {
    lang = "-c";
  } else if (::Util::IsIrFileName(fn)) {
    lang = "";
  }
  string ofn;
  Env::GetOutputPath(fn.c_str(), &ofn);
  string arg = lang + " -s -o " + ofn;
  RunIroha(obj, arg);
  const string &marker = Env::GetOutputMarker();
  if (!marker.empty()) {
    cout << marker << fn << "\n";
  }
}

int Synth::RunIrohaOpt(const string &pass, vm::Object *obj) {
  LOG(DEBUG) << "pass: " << pass;
  string tmp = IrPath(obj) + "~";
  string arg = "-opt " + pass + " -o " + tmp;
  int res = RunIroha(obj, arg);
  if (res) {
    return res;
  }
  return rename(tmp.c_str(), IrPath(obj).c_str());
}

}  // namespace synth
