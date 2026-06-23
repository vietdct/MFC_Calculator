#pragma once
#include "ICalState.h"


class NormalState : public ICalState
{
	public:
		void AppendDigit(CMFCCalculatorDlg* dlg, TCHAR ditgit) override;
		void SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) override;
		const TCHAR* Name()const override {
			return _T("Normal_State");
		}
};

