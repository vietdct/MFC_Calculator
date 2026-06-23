#pragma once
#include "MFC_CalculatorDlg.h"

class JustCalculatedState : public ICalState
{
	void AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) override;
	void SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) override;
	const TCHAR* Name() const override {
		return _T("JustCalculated_State");
	};
};

