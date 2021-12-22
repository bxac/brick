// Copyright (c) 2015 The Brick Authors.

#ifndef BRICK_RESOURCE_LAST_RESOURCE_PROVIDER_H_
#define BRICK_RESOURCE_LAST_RESOURCE_PROVIDER_H_


#include "include/wrapper/cef_resource_manager.h"

#define OVERRIDE override

class LastResourceProvider : public CefResourceManager::Provider {
 public:
  LastResourceProvider() {}

  bool OnRequest(scoped_refptr<CefResourceManager::Request> request) OVERRIDE;
 private:
  DISALLOW_COPY_AND_ASSIGN(LastResourceProvider);
};

#endif  // BRICK_RESOURCE_LAST_RESOURCE_PROVIDER_H_
