// Copyright (c) 2015 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/completion_callback_cpptoc.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK completion_callback_on_complete(
    struct _cef_completion_callback_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefCompletionCallbackCppToC::Get(self)->OnComplete();
}


// CONSTRUCTOR - Do not edit by hand.

CefCompletionCallbackCppToC::CefCompletionCallbackCppToC(
    CefCompletionCallback* cls)
    : CefCppToC<CefCompletionCallbackCppToC, CefCompletionCallback,
        cef_completion_callback_t>(cls) {
  struct_.struct_.on_complete = completion_callback_on_complete;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefCompletionCallbackCppToC,
    CefCompletionCallback, cef_completion_callback_t>::DebugObjCt = 0;
#endif

