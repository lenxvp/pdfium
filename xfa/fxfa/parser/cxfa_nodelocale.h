// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FXFA_PARSER_CXFA_NODELOCALE_H_
#define XFA_FXFA_PARSER_CXFA_NODELOCALE_H_

#include <memory>

#include "core/fxcrt/ifx_locale.h"
#include "xfa/fxfa/fxfa_basic.h"

class CXFA_Node;

WideString XFA_PatternToString(FX_LOCALENUMSUBCATEGORY category);

class CXFA_NodeLocale : public IFX_Locale {
 public:
  explicit CXFA_NodeLocale(CXFA_Node* pLocale);
  ~CXFA_NodeLocale() override;

  // IFX_Locale
  WideString GetName() const override;
  WideString GetNumbericSymbol(FX_LOCALENUMSYMBOL eType) const override;

  WideString GetDateTimeSymbols() const override;
  WideString GetMonthName(int32_t nMonth, bool bAbbr) const override;
  WideString GetDayName(int32_t nWeek, bool bAbbr) const override;
  WideString GetMeridiemName(bool bAM) const override;
  FX_TIMEZONE GetTimeZone() const override;
  WideString GetEraName(bool bAD) const override;

  WideString GetDatePattern(FX_LOCALEDATETIMESUBCATEGORY eType) const override;
  WideString GetTimePattern(FX_LOCALEDATETIMESUBCATEGORY eType) const override;
  WideString GetNumPattern(FX_LOCALENUMSUBCATEGORY eType) const override;

 private:
  CXFA_Node* GetNodeByName(CXFA_Node* pParent,
                           const WideStringView& wsName) const;
  WideString GetSymbol(XFA_Element eElement,
                       const WideStringView& symbol_type) const;
  WideString GetCalendarSymbol(XFA_Element eElement,
                               int index,
                               bool bAbbr) const;

  CFX_UnownedPtr<CXFA_Node> const m_pLocale;
};

#endif  // XFA_FXFA_PARSER_CXFA_NODELOCALE_H_
