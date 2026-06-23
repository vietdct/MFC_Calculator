#include "pch.h"
#include "OperatorPendingState.h"
#include "MFC_CalculatorDlg.h"

void OperatorPendingState::AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) {
	dlg->m_strInputBuffer = digit;
	dlg->m_strExprPrefix = dlg->m_strInputBuffer + dlg->m_strExprPrefix;
	dlg->m_strDisplay = _T("");
	dlg->SetState(dlg->GetNormalState());
}
void OperatorPendingState::SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) {
	dlg->m_operator = op;
	dlg->m_strExprPrefix.SetAt(dlg->m_strExprPrefix.GetLength() - 2, op);
	dlg->m_strExpression = dlg->m_strExprPrefix;
}