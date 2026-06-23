#include "pch.h"
#include "OperatorPendingState.h"
#include "MFC_CalculatorDlg.h"

void OperatorPendingState::AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) {
	dlg->m_strDisplay = digit;
	dlg->SetState(dlg->GetNormalState());
}
void OperatorPendingState::SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) {
	dlg->m_operator = op;
}