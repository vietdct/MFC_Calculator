
// MFC_CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"
#include "OperationStrategy.h"
#include "JustCalculatedState.h"
#include "NormalState.h"
#include "OperatorPendingState.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCalculatorDlg dialog



CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_firstOperand = 0.0;
	m_operator = _T('0');
}

void CMFCCalculatorDlg::ClearAll() {
	m_strDisplay = _T("0");
	m_firstOperand = 0.0;
	m_operator = _T('0');
	SetState(GetNormalState());
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::CalculateResult() {
	UpdateData(TRUE); //lay du lieu tu UI vao bien
	double secondOperand = _ttof(m_strDisplay); // Lấy số thứ hai từ display)
	double result = 0.0;
	result = m_pCurrentStrategy->Calculator(m_firstOperand, secondOperand);
	delete m_pCurrentStrategy; 

	if (result == static_cast<long long> (result)) {
		m_strDisplay.Format(_T("%lld"), static_cast<long long>(result));
	}
	else {
		m_strDisplay.Format(_T("%g"), result);
	}
	SetState(GetJustCalculatedState());
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::NextNumber()
{
	UpdateData(TRUE);
	m_firstOperand = _ttof(m_strDisplay);

	//m_operatorPending = true;
	//m_JustCalculated = false;
	UpdateData(FALSE);
}

void CMFCCalculatorDlg::SetOperator(TCHAR op) {
	UpdateData(TRUE);
	m_currentState->SetOperator(this,op);
	UpdateData(FALSE);

}

void CMFCCalculatorDlg::Appendigit(TCHAR digit)
{
	UpdateData(TRUE);  // Lấy giá trị hiện tại từ giao diện)
	m_currentState->AppendDigit(this, digit);
	UpdateData(FALSE);
}
void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DISPLAY, m_strDisplay);


}

BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BTN_NUM1, &CMFCCalculatorDlg::OnBnClickedBtnNum1)
	ON_BN_CLICKED(IDC_BTN_NUM2, &CMFCCalculatorDlg::OnBnClickedBtnNum2)
	ON_BN_CLICKED(IDC_BTN_NUM3, &CMFCCalculatorDlg::OnBnClickedBtnNum3)
	ON_BN_CLICKED(IDC_BTN_NUM4, &CMFCCalculatorDlg::OnBnClickedBtnNum4)
	ON_BN_CLICKED(IDC_BTN_NUM5, &CMFCCalculatorDlg::OnBnClickedBtnNum5)
	ON_BN_CLICKED(IDC_BTN_NUM6, &CMFCCalculatorDlg::OnBnClickedBtnNum6)
	ON_BN_CLICKED(IDC_BTN_NUM7, &CMFCCalculatorDlg::OnBnClickedBtnNum7)
	ON_BN_CLICKED(IDC_BTN_NUM8, &CMFCCalculatorDlg::OnBnClickedBtnNum8)
	ON_BN_CLICKED(IDC_BTN_NUM9, &CMFCCalculatorDlg::OnBnClickedBtnNum9)
	ON_BN_CLICKED(IDC_BTN_NUM0, &CMFCCalculatorDlg::OnBnClickedBtnNum0)
	ON_BN_CLICKED(IDC_BTN_ADD, &CMFCCalculatorDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_SUB, &CMFCCalculatorDlg::OnBnClickedBtnSub)
	ON_BN_CLICKED(IDC_BTN_MUL, &CMFCCalculatorDlg::OnBnClickedBtnMul)
	ON_BN_CLICKED(IDC_BTN_DIV, &CMFCCalculatorDlg::OnBnClickedBtnDiv)
	ON_BN_CLICKED(IDC_BTN_DEL, &CMFCCalculatorDlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_EQUAL, &CMFCCalculatorDlg::OnBnClickedBtnEqual)
END_MESSAGE_MAP()


// CMFCCalculatorDlg message handlers

BOOL CMFCCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// khoi tao gia tri ban dau
	m_normalState = std::make_shared<NormalState>();
	m_operatorPendingState = std::make_shared<OperatorPendingState>();
	m_justCalculatedState = std::make_shared<JustCalculatedState>();
	m_currentState = m_normalState;
	UpdateData(FALSE); 


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCCalculatorDlg::OnBnClickedBtnNum1()
{
	Appendigit(_T('1'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum2()
{
	Appendigit(_T('2'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum3()
{
	Appendigit(_T('3'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum4()
{
	Appendigit(_T('4'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum5()
{
	Appendigit(_T('5'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum6()
{
	Appendigit(_T('6'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum7()
{
	Appendigit(_T('7'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum8()
{
	Appendigit(_T('8'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum9()
{
	Appendigit(_T('9'));
}

void CMFCCalculatorDlg::OnBnClickedBtnNum0()
{
	Appendigit(_T('0'));
}

void CMFCCalculatorDlg::OnBnClickedBtnAdd()
{
	m_pCurrentStrategy = new AddStrategy();
	SetOperator(_T('+'));
	//NextNumber();
}

void CMFCCalculatorDlg::OnBnClickedBtnSub()
{
	m_pCurrentStrategy = new SubStrategy();
	SetOperator(_T('-'));
	//NextNumber();
}

void CMFCCalculatorDlg::OnBnClickedBtnMul()
{
	m_pCurrentStrategy = new MulStrategy();
	SetOperator(_T('*'));
	//NextNumber();
}

void CMFCCalculatorDlg::OnBnClickedBtnDiv()
{
	m_pCurrentStrategy = new DivStrategy();
	SetOperator(_T('/'));
	//NextNumber();
}

void CMFCCalculatorDlg::OnBnClickedBtnDel()
{
	ClearAll();
}

void CMFCCalculatorDlg::OnBnClickedBtnEqual()
{
	CalculateResult();
}
