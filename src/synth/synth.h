// -*- C++ -*-
#ifndef _synth_synth_h_
#define _synth_synth_h_

#include "nli.h"

namespace dfg {
class DGraph;
class DModule;
}  // namespace dfg
using namespace dfg;

namespace vm {
class Object;
class VM;
}  // namespace vm

namespace synth {

class Synth {
public:
  static void WriteHdl(const string &fn, vm::Object *obj);
  static int RunIroha(vm::Object *obj, const string &args);
  static int RunIrohaOpt(const string &pass, vm::Object *obj);
  static string IrPath(vm::Object *obj);
  static string GetIrohaCommand(vm::Object *obj);
};

}  // namespace synth

#endif  // _synth_synth_h_
