#include "pch.h"
#include "JustCalculatedState.h"
#include "MFC_CalculatorDlg.h"

void JustCalculatedState::AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) {
	dlg->m_strDisplay = digit;
	dlg->SetState(dlg->GetNormalState());
}
void JustCalculatedState::SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) {
	dlg->m_firstOperand = _ttof(dlg->m_strDisplay);
	dlg->m_operator = op;
	dlg->SetState(dlg->GetOperatorPendingState());
}
