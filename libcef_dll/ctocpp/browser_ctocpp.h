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

#ifndef CEF_LIBCEF_DLL_CTOCPP_BROWSER_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_BROWSER_CTOCPP_H_
#pragma once

#ifndef USING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed wrapper-side only")
#else  // USING_CEF_SHARED

#include <vector>
#include "include/cef_browser.h"
#include "include/capi/cef_browser_capi.h"
#include "include/cef_client.h"
#include "include/capi/cef_client_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefBrowserCToCpp
    : public CefCToCpp<CefBrowserCToCpp, CefBrowser, cef_browser_t> {
 public:
  CefBrowserCToCpp();

  // CefBrowser methods.
  CefRefPtr<CefBrowserHost> GetHost() OVERRIDE;
  bool CanGoBack() OVERRIDE;
  void GoBack() OVERRIDE;
  bool CanGoForward() OVERRIDE;
  void GoForward() OVERRIDE;
  bool IsLoading() OVERRIDE;
  void Reload() OVERRIDE;
  void ReloadIgnoreCache() OVERRIDE;
  void StopLoad() OVERRIDE;
  int GetIdentifier() OVERRIDE;
  bool IsSame(CefRefPtr<CefBrowser> that) OVERRIDE;
  bool IsPopup() OVERRIDE;
  bool HasDocument() OVERRIDE;
  CefRefPtr<CefFrame> GetMainFrame() OVERRIDE;
  CefRefPtr<CefFrame> GetFocusedFrame() OVERRIDE;
  CefRefPtr<CefFrame> GetFrame(int64 identifier) OVERRIDE;
  CefRefPtr<CefFrame> GetFrame(const CefString& name) OVERRIDE;
  size_t GetFrameCount() OVERRIDE;
  void GetFrameIdentifiers(std::vector<int64>& identifiers) OVERRIDE;
  void GetFrameNames(std::vector<CefString>& names) OVERRIDE;
  bool SendProcessMessage(CefProcessId target_process,
      CefRefPtr<CefProcessMessage> message) OVERRIDE;
};

#endif  // USING_CEF_SHARED
#endif  // CEF_LIBCEF_DLL_CTOCPP_BROWSER_CTOCPP_H_
