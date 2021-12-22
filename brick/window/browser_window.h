// Copyright (c) 2015 The Brick Authors.

#ifndef BRICK_WINDOW_BROWSER_WINDOW_H_
#define BRICK_WINDOW_BROWSER_WINDOW_H_
#pragma once


#include <string>
#if defined(__linux__)
// The Linux client uses GTK instead of the underlying platform type (X11).
#include <gdk/gdkx.h>
#undef Status   // Definition conflicts with cef_urlrequest.h
#define BrowserWindowHandle GdkWindow*
#define BrowserWindowNativeEvent GdkEvent*
#else

#endif

#define BROWSER_WINDOW_PADDING 20;

#include "include/cef_base.h"
#include "include/base/cef_lock.h"
#include "include/internal/cef_linux.h"

#include "include/base/cef_logging.h"

class BrowserWindow : public CefBaseRefCounted {

 public:
  BrowserWindow();
  BrowserWindowHandle GetHandler();

  typedef enum {
    NORTH_WEST = 0,
    NORTH,
    NORTH_EAST,
    WEST,
    CENTER,
    EAST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EAST
  } Position;

  // Platform specific methods
  virtual void OnNativeEvent(BrowserWindowNativeEvent event);
  virtual bool WrapNative(CefWindowHandle window);
  virtual void Show();
  virtual void Hide();
  virtual bool GetHided();
  virtual void Close();
  virtual void SetMinSize(int width, int height);
  virtual void Resize(int width, int height);
  virtual void SetTitle(std::string title);
  virtual void Popupping();
  virtual void FrozeSize(int width, int height);
  virtual void ToggleVisibility();
  virtual void Present();
  virtual void SetActive();
  virtual bool IsActive();
  virtual void FlushChanges();
  virtual void MoveResize(Position position, int width, int height);
  virtual void Stick();
  virtual void UnStick();
  virtual void Fullscreen();
  virtual void UnFullscreen();
  virtual bool IsInFullscreen();
  CefRect GetScreenRect();

  // Event handlers
  virtual bool OnHide();
  virtual bool OnShow();

  // Shared methods
  virtual void SetClosable(bool closable);
  virtual bool IsClosable();
//  virtual bool SetFocus(bool focused);
//  virtual bool HasFocus();

 protected:
  void SaveRestorePosition(bool save = false);
  BrowserWindowHandle window_handler_;
  bool hided_;
  bool focused_;
  bool visible_;
  bool in_fullscreen_;
  bool resizable_;
  bool closable_;
  bool sticked_;
  bool restore_last_position_;
  int last_x_;
  int last_y_;
#if defined(__linux__)
  bool on_kde_;
  bool on_unity_;
#endif

IMPLEMENT_REFCOUNTING(BrowserWindow);
};

#endif  // BRICK_WINDOW_BROWSER_WINDOW_H_
