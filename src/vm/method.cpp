#include "vm/method.h"

#include "base/annotation.h"
#include "base/dump_stream.h"
#include "fe/method.h"
#include "fe/var_decl.h"
#include "vm/insn.h"

namespace vm {

Method::Method(bool is_toplevel) :
  method_fn_(nullptr), alt_impl_(nullptr),
  parse_tree_(nullptr), is_toplevel_(is_toplevel) {
}

Method::~Method() {
  STLDeleteValues(&insns_);
  STLDeleteValues(&method_regs_);
}

int Method::GetNumArgRegisters() const {
  if (parse_tree_ != nullptr &&
      parse_tree_->args_) {
    return parse_tree_->args_->decls.size();
  }
  return 0;
}

int Method::GetNumReturnRegisters() const {
  // return_types_ is 0 before compilation, so use the parse tree instead.
  if (parse_tree_ != nullptr &&
      parse_tree_->returns_ != nullptr) {
    return parse_tree_->returns_->decls.size();
  }
  // Use the value for a non native method.
  return return_types_.size();
}

const iroha::NumericWidth &Method::GetNthArgWidth(int i) {
  return parse_tree_->args_->decls[i]->GetWidth();
}

const char *Method::AlternativeImplementation() {
  return alt_impl_;
}

const string &Method::GetSynthName() const {
  return synth_name_;
}

void Method::SetSynthName(const string &s) {
  synth_name_ = s;
}

bool Method::IsTopLevel() const {
  return is_toplevel_;
}

Annotation *Method::GetAnnotation() const {
  if (parse_tree_ != nullptr &&
      parse_tree_->annotation_ != nullptr) {
    return parse_tree_->annotation_;
  }
  return Annotation::EmptyAnnotation();
}

void Method::Dump() {
  DumpStream ds(cout);
  Dump(ds);
}

void Method::Dump(DumpStream &ds) {
  ds.os << "method insns\n";
  for (size_t i = 0; i < insns_.size(); ++i) {
    Insn *insn = insns_[i];
    ds.push_indent();
    ds.indent();
    ds.os << i << ":";
    insn->Dump(ds);
    ds.os << "\n";
    ds.pop_indent();
  }

  int num_args = GetNumArgRegisters();
  int num_rets = GetNumReturnRegisters();
  for (size_t i = 0; i < method_regs_.size(); ++i) {
    Register *reg = method_regs_[i];
    ds.push_indent();
    ds.indent();
    ds.os << "r" << reg->id_;
    if (i < num_args) {
      ds.os << "a";
    } else if (i < num_args + num_rets) {
      ds.os << "r";
    }
    ds.os << ":";
    reg->Dump(ds);
    ds.os << "\n";
    ds.pop_indent();
  }
}

}  // namespace vm
