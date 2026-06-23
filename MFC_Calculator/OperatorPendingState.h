#pragma once
#include "ICalState.h"

class OperatorPendingState : public ICalState
{
	void AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) override;
	void SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) override;
	const TCHAR* Name() const override {
		return _T("OperatorPending_State");
	}
};

