#pragma once

class CMFCCalculatorDlg;

class ICalState
{
	public:
		virtual ~ICalState() = default;
		virtual void AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) = 0;
		virtual void SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) = 0;
		virtual const TCHAR* Name() const = 0;

};

