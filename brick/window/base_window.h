// Copyright (c) 2015 The Brick Authors.

#ifndef BRICK_WINDOW_BASE_WINDOW_H_
#define BRICK_WINDOW_BASE_WINDOW_H_
#pragma once


#if defined(__linux__)
// The Linux client uses GTK instead of the underlying platform type (X11).
#include <gtk/gtk.h>
#define ClientWindowHandle GtkWidget*
#else
#define ClientWindowHandle CefWindowHandle
#endif

#include "include/cef_base.h"
#include "include/base/cef_lock.h"


class BaseWindow : public CefBaseRefCounted {

 public:
  enum STATE {
    STATE_NORMAL = 0,
    STATE_MINIMIZED,
    STATE_MAXIMIZED,
    STATE_FULLSCREEN,
    N_STATES
  };


  BaseWindow() : window_handler_(NULL),
                 hided_(true),
                 focused_(false) {
  }

  ClientWindowHandle GetHandler();

  // Platform specific methods
  virtual void Init() = 0;
  virtual void Minimize();
  virtual void Maximize();
  virtual void Restore();
  virtual void Show();
  virtual void Hide();
  virtual void Close();
  virtual bool GetHided();
  virtual void Focus();
  virtual void Destroy();
  virtual void Move(int left, int top, int width, int height);
  virtual void Move(int left, int top);
  virtual void Resize(int width, int height);
  virtual const char* GetTitle();
  virtual void SetTitle(const char* title);
  virtual void Fullscreen();
  virtual STATE GetState();
  virtual void SetTopmost(bool ontop);
  virtual void SetResizable(bool resizable);
  virtual bool GetResizable();
  virtual void SetShowChrome(bool showChrome);
  virtual bool GetShowChrome();
  virtual void SetOpacity(double opacity);
  virtual double GetOpacity();
  virtual void Centralize();
  virtual void Present();
  // Event handlers


  // Shared methods
  virtual bool SetFocus(bool focused);
  virtual bool HasFocus();

 protected:
  ClientWindowHandle window_handler_;
  bool hided_;
  bool focused_;

IMPLEMENT_REFCOUNTING(BaseWindow);
};

#endif  // BRICK_WINDOW_BASE_WINDOW_H_
