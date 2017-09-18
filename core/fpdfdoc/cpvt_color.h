// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FPDFDOC_CPVT_COLOR_H_
#define CORE_FPDFDOC_CPVT_COLOR_H_

#include "core/fpdfapi/parser/cpdf_array.h"
#include "core/fxcrt/fx_string.h"
#include "core/fxcrt/fx_system.h"

struct CPVT_Color {
  enum Type { kTransparent = 0, kGray, kRGB, kCMYK };

  CPVT_Color(Type type = kTransparent,
             float color1 = 0.0f,
             float color2 = 0.0f,
             float color3 = 0.0f,
             float color4 = 0.0f)
      : nColorType(type),
        fColor1(color1),
        fColor2(color2),
        fColor3(color3),
        fColor4(color4) {}

  Type nColorType;
  float fColor1;
  float fColor2;
  float fColor3;
  float fColor4;

  static CPVT_Color ParseColor(const ByteString& str);
  static CPVT_Color ParseColor(const CPDF_Array& array);
};

#endif  // CORE_FPDFDOC_CPVT_COLOR_H_
