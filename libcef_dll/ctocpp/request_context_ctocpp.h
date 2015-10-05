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

#ifndef CEF_LIBCEF_DLL_CTOCPP_REQUEST_CONTEXT_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_REQUEST_CONTEXT_CTOCPP_H_
#pragma once

#ifndef USING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed wrapper-side only")
#else  // USING_CEF_SHARED

#include "include/cef_request_context.h"
#include "include/capi/cef_request_context_capi.h"
#include "include/cef_scheme.h"
#include "include/capi/cef_scheme_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefRequestContextCToCpp
    : public CefCToCpp<CefRequestContextCToCpp, CefRequestContext,
        cef_request_context_t> {
 public:
  CefRequestContextCToCpp();

  // CefRequestContext methods.
  bool IsSame(CefRefPtr<CefRequestContext> other) OVERRIDE;
  bool IsSharingWith(CefRefPtr<CefRequestContext> other) OVERRIDE;
  bool IsGlobal() OVERRIDE;
  CefRefPtr<CefRequestContextHandler> GetHandler() OVERRIDE;
  CefString GetCachePath() OVERRIDE;
  CefRefPtr<CefCookieManager> GetDefaultCookieManager(
      CefRefPtr<CefCompletionCallback> callback) OVERRIDE;
  bool RegisterSchemeHandlerFactory(const CefString& scheme_name,
      const CefString& domain_name,
      CefRefPtr<CefSchemeHandlerFactory> factory) OVERRIDE;
  bool ClearSchemeHandlerFactories() OVERRIDE;
  void PurgePluginListCache(bool reload_pages) OVERRIDE;
};

#endif  // USING_CEF_SHARED
#endif  // CEF_LIBCEF_DLL_CTOCPP_REQUEST_CONTEXT_CTOCPP_H_
