// -*- C++ -*-
#ifndef _synth_shared_resource_set_h_
#define _synth_shared_resource_set_h_

#include "synth/common.h"

#include <set>
#include <map>

using std::map;
using std::set;

namespace synth {

class SharedResource {
public:
  SharedResource();
  ~SharedResource();

  void AddOwnerResource(IResource *res);
  void AddAccessorResource(IResource *res);

  set<ThreadSynth *> readers_;
  set<ThreadSynth *> writers_;
  set<ThreadSynth *> axi_ctrl_thrs_;
  vector<ThreadSynth *> ordered_accessors_;
  set<ThreadSynth *> accessors_;
  ThreadSynth *owner_thr_;
  IResource *owner_res_;
  set<IResource *> accessor_resources_;
};

class SharedResourceSet {
public:
  ~SharedResourceSet();

  // Called between pass 1 and 2.
  // Determines an owner thread (ThreadSynth).
  void DetermineOwnerThreadAll();
  // Called after pass 2. Sets the foreign resource for IResource.
  void ResolveResourceAccessors();

  // Declares @thr accesses this.name/obj.
  // NUM
  void AddMemberAccessor(ThreadSynth *thr, sym_t name, vm::Insn *insn);
  // OBJECT, INT_ARRAY, OBJECT_ARRAY
  void AddObjectAccessor(ThreadSynth *thr, vm::Object *obj, vm::Insn *insn,
			 const string &synth_name);
  // ExtIO is not shareable, so this keeps track of the accessor thread.
  bool AddExtIOMethodAccessor(ThreadSynth *thr, vm::Method *method);

  SharedResource *GetBySlotName(vm::Object *obj, sym_t name);
  SharedResource *GetByObj(vm::Object *obj);
  bool HasAccessor(vm::Object *obj);
  bool HasExtIOAccessor(vm::Method *method);

private:
  void DetermineOwnerThread(SharedResource *res);
  void ResolveSharedResourceAccessor(SharedResource *sres);

  map<vm::Object *, SharedResource *> obj_resources_;
  map<vm::Object *, map<sym_t, SharedResource *> > value_resources_;
  map<vm::Method *, ThreadSynth *> ext_io_methods_;
};

}  // namespace synth

#endif  // _synth_shared_resource_set_h_
