// Copyright (c) 2015 The Brick Authors.

#ifndef BRICK_EVENT_ACCOUNT_SWITCH_EVENT_H_
#define BRICK_EVENT_ACCOUNT_SWITCH_EVENT_H_
#pragma once

#include <string>

#include "brick/event/event.h"
#include "brick/account.h"

class AccountSwitchEvent : public Event {
 public:
  AccountSwitchEvent(const EventSender* sender, CefRefPtr<Account> account/*const Account *account*/) :
     Event (sender),
     account_ (account) {
  }

  explicit AccountSwitchEvent(CefRefPtr<Account> account/*const Account *account*/) :
      Event (nullptr),
      account_ (account) {
  }

  virtual ~AccountSwitchEvent() { }

  CefRefPtr<Account>/*const Account **/getAccount() {
    return account_;
  }

 private:
  CefRefPtr<Account>/*const Account **/account_;

IMPLEMENT_REFCOUNTING(AccountSwitchEvent);
};

#endif  // BRICK_EVENT_ACCOUNT_SWITCH_EVENT_H_
