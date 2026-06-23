
// MFC_CalculatorDlg.h : header file
//

#pragma once
#include "OperationStrategy.h"
#include "AddStrategy.h"
#include "SubStrategy.h"
#include "MulStrategy.h"
#include "DivStrategy.h"
#include <memory>
#include "ICalState.h"

// CMFCCalculatorDlg dialog
class CMFCCalculatorDlg : public CDialogEx
{
// Construction
public:
	CMFCCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strDisplay;
	afx_msg void OnBnClickedBtnNum1();
	afx_msg void OnBnClickedBtnNum2();
	afx_msg void OnBnClickedBtnNum3();
	afx_msg void OnBnClickedBtnNum4();
	afx_msg void OnBnClickedBtnNum5();
	afx_msg void OnBnClickedBtnNum6();
	afx_msg void OnBnClickedBtnNum7();
	afx_msg void OnBnClickedBtnNum8();
	afx_msg void OnBnClickedBtnNum9();
	afx_msg void OnBnClickedBtnNum0();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnSub();
	afx_msg void OnBnClickedBtnMul();
	afx_msg void OnBnClickedBtnDiv();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnEqual();


	OperationStrategy* m_pCurrentStrategy = nullptr; // con tro den strategy hien tai
	double m_firstOperand;  //so thu nhat 
	TCHAR m_operator;       //toan tu

	void Appendigit(TCHAR digit); 
	void NextNumber();
	void SetOperator(TCHAR op);  //ham chung set toan tu
	void CalculateResult();  //ham tinh ket qua
	void ClearAll();  //ham xoa tat ca
	void SetState(std::shared_ptr<ICalState> state) {
		m_currentState = state;
	}
	std::shared_ptr<ICalState> GetNormalState() {
		return m_normalState;
	}
	std::shared_ptr<ICalState> GetOperatorPendingState() {
		return m_operatorPendingState;
	}
	std::shared_ptr<ICalState> GetJustCalculatedState() {
		return m_justCalculatedState;
	}

private:
	std::shared_ptr<ICalState> m_currentState;
	std::shared_ptr<ICalState> m_normalState;
	std::shared_ptr<ICalState> m_operatorPendingState;
	std::shared_ptr<ICalState> m_justCalculatedState;
};
