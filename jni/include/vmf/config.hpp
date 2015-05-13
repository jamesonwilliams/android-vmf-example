// Copyright (C) 2012, Intel Corporation, all rights reserved.

#pragma once

#define VMF_VERSION_MAJOR 2
#define VMF_VERSION_MINOR 0

#ifdef VMF_API_EXPORT
  #define VMF_EXPORT __declspec(dllexport)
#else
  #define VMF_EXPORT
#endif
