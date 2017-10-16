//===--- LEG.cpp - Implement LEG target feature support -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements LEG TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "LEG.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void LEGTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {}

ArrayRef<Builtin::Info> LEGTargetInfo::getTargetBuiltins() const {
  return None;
}

bool LEGTargetInfo::hasFeature(StringRef Feature) const {
  return Feature == "leg";
}

ArrayRef<TargetInfo::GCCRegAlias> LEGTargetInfo::getGCCRegAliases() const {
  // No aliases.
  return None;
}

bool LEGTargetInfo::validateAsmConstraint(
    const char *&Name, TargetInfo::ConstraintInfo &info) const {
  // FIXME: implement
  switch (*Name) {
  case 'K': // the constant 1
  case 'L': // constant -1^20 .. 1^19
  case 'M': // constant 1-4:
    return true;
  }
  // No target constraints for now.
  return false;
}

const char *LEGTargetInfo::getClobbers() const { return ""; }

clang::TargetInfo::BuiltinVaListKind
LEGTargetInfo::getBuiltinVaListKind() const {
  return TargetInfo::VoidPtrBuiltinVaList;
}

ArrayRef<const char *> LEGTargetInfo::getGCCRegNames() const { return None; }

int LEGTargetInfo::getEHDataRegisterNumber(unsigned RegNo) const {
  // R0=ExceptionPointerRegister R1=ExceptionSelectorRegister
  return -1;
}
