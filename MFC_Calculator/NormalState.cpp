#include "pch.h"
#include "NormalState.h"
#include "MFC_CalculatorDlg.h"


void NormalState:: AppendDigit(CMFCCalculatorDlg* dlg, TCHAR digit) {
	if (dlg->m_strInputBuffer.IsEmpty() || dlg->m_strInputBuffer == _T('0')) {
		dlg->m_strInputBuffer = digit;
	}
	else
	{
		dlg->m_strInputBuffer += digit;
	}
	dlg->m_strExpression = dlg->m_strExprPrefix + dlg->m_strInputBuffer;
	dlg->m_strDisplay = _T("");
}
void NormalState::SetOperator(CMFCCalculatorDlg* dlg, TCHAR op) {
	dlg->m_firstOperand = _ttof(dlg->m_strInputBuffer);
	dlg->m_operator = op;
	dlg->m_strExprPrefix = dlg->m_strInputBuffer + _T(" ") + op + _T(" ");
	dlg->m_strExpression = dlg->m_strExprPrefix;
	dlg->m_strInputBuffer = _T("");
	
	dlg->SetState(dlg->GetOperatorPendingState());
}