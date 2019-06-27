// -*- C++ -*-
#ifndef _vm_executor_h_
#define _vm_executor_h_

// Mostly for inline methods.
#include "vm/common.h"
#include "vm/insn.h"
#include "vm/method.h"
#include "vm/method_frame.h"
#include "vm/opcode.h"
#include "vm/value.h"

namespace vm {

class Executor {
public:
  Executor(Thread *thread, MethodFrame *frame) : thr_(thread), frame_(frame) {
  }

  bool ExecInsn(Insn *insn);

private:
  void ExecMemberAccess();
  bool ExecFuncall();
  void ExecFuncallDone();
  Method *LookupMethod(Object **obj);
  Method *LookupCompiledMethod(Object **obj);
  void ExecLoadObj();
  void SetupCalleeFrame(Object *obj, Method *callee_method,
			const vector<Value> &args);
  void ExecStr();
  void ExecNum();
  void ExecBinop();
  void ExecIncDec();
  void ExecArrayRead();
  void ExecArrayWrite();
  void ExecNumUniop();
  void ExecLogicInv();
  void ExecNonNumResultBinop();
  void ExecIf();
  bool ExecGoto();
  void ExecBitRange();

  // for toplevel
  void ExecVardecl();
  void ExecThreadDecl();
  void ExecChannelDecl();
  void ExecMailboxDecl();
  
  void ExecImport();
  void ExecFuncdecl();
  void ExecMemberReadWithCheck();
  bool ExecFuncallWithCheck();
  void ExecFuncallDoneWithCheck();
  void ExecArrayWriteWithCheck();
  void ExecSetTypeObject();
  bool MayExecuteCustomOp();
  void ExecMayWithTypeDone();
  bool ExecCustomOp();
  void RetryBinopWithType();

  void AddThreadEntry(const string &name, int num, bool is_soft);
  void ClearThreadEntry();
  bool IsCustomOpCall(const Method *method);
  Object *CreateMemoryObject(const iroha::NumericWidth &width,
			     fe::ArrayShape *shape,
			     fe::ArrayInitializer *array_initializer,
			     Annotation *an);
  Object *CreateObjectArray(fe::ArrayShape *shape);
  void InitializeArray(IntArray *array,
		       fe::ArrayInitializer *array_initializer);
  void PopulateArrayIndexes(int start, vector<uint64_t> *indexes);

  bool IsTopLevel() const {
    return frame_->method_->IsTopLevel();
  }
  Method *m() const {
    return frame_->method_;
  }
  enum OpCode op() const {
    return insn_->op_;
  }
  Register *mreg(int id) const {
    return frame_->method_->method_regs_[id];
  }
  Value &VAL(int v) const {
    return frame_->reg_values_[v];
  }
  Value &VAL(Register *reg) const {
    return frame_->reg_values_[reg->id_];
  }
  Register *sreg(int idx) {
    return insn_->src_regs_[idx];
  }
  Register *dreg(int idx) {
    return insn_->dst_regs_[idx];
  }
  Register *oreg() {
    return insn_->obj_reg_;
  }

  // Set in ExecInsn().
  Insn *insn_;
  // Given from the constructor.
  Thread *thr_;
  MethodFrame *frame_;
};

}  // namespace vm

#endif  // _vm_executor_h_
