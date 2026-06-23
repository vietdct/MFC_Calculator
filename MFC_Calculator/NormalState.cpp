#include "pch.h"
#include "NormalState.h"
#include "MFC_CalculatorDlg.h"


void NormalState:: AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) {
	if (dlg->m_strDisplay == _T('0')) {
		dlg->m_strDisplay = digit;
	}
	else {
		dlg->m_strDisplay += digit;
	}
}
void NormalState::SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) {
	dlg->m_firstOperand = _ttof(dlg->m_strDisplay);
	dlg->m_operator = op;
	dlg->SetState(dlg->GetOperatorPendingState());
}