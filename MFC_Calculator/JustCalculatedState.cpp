#include "pch.h"
#include "JustCalculatedState.h"
#include "MFC_CalculatorDlg.h"

void JustCalculatedState::AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) {
	dlg->m_strInputBuffer = digit;
	dlg->m_strExprPrefix = _T("");
	dlg->m_strExpression = dlg->m_strInputBuffer;
	dlg->m_strDisplay = _T("");
	dlg->SetState(dlg->GetNormalState());
}
void JustCalculatedState::SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) {
	dlg->m_firstOperand = _ttof(dlg->m_strDisplay);
	dlg->m_operator = op;
	dlg->m_strExprPrefix = dlg->m_strDisplay + _T(" ") + op + _T(" ");
	dlg->m_strExpression = dlg->m_strExprPrefix;
	dlg->m_strInputBuffer = _T("");
	dlg->SetState(dlg->GetOperatorPendingState());
}
