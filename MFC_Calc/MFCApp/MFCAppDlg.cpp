
// MFCAppDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFCApp.h"
#include "MFCAppDlg.h"
#include "afxdialogex.h"
#include "Exception.hpp"
#include "StrtoDigit.hpp"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define IDC_EDIT3                       1005

// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMFCAppDlg



CMFCAppDlg::CMFCAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCAppDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCAppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCAppDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCAppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCAppDlg::OnBnClickedButton4)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCAppDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCAppDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// ����������� ��������� CMFCAppDlg

BOOL CMFCAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMFCAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMFCAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCAppDlg::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialogEx::OnOK();
}


void CMFCAppDlg::OnBnClickedButton1()
{
	try 
	{
	CString text;
	GetDlgItemText(IDC_EDIT1,text);
	double oper1 = StrtoDigit(text, text.GetLength());
	GetDlgItemText(IDC_EDIT2,text);
	double res, oper2 = StrtoDigit(text, text.GetLength());
	res = oper1 +oper2;
	char str[50];
	sprintf_s(str, "%f", res);
	SetDlgItemText(IDC_EDIT3, (LPCTSTR)str);
	CListBox* Lb = (CListBox*)GetDlgItem(IDC_LIST1);
	sprintf_s(str, "%f + %f = %f",oper1,oper2,res);
	Lb->AddString(str);
	}
	catch(mException ex)
	{
		MessageBox ( ex.ShowStr(), "ERROR", MB_OK );
	}
	
}


void CMFCAppDlg::OnBnClickedButton2()
{

	try 
	{
		CString text;
		GetDlgItemText(IDC_EDIT1,text);
		double oper1 = StrtoDigit(text, text.GetLength());
		GetDlgItemText(IDC_EDIT2,text);
		double res, oper2 = StrtoDigit(text, text.GetLength());
		res = oper1 - oper2;
		char str[50];
		sprintf_s(str, "%f", res);
		SetDlgItemText(IDC_EDIT3, (LPCTSTR)str);
		CListBox* Lb = (CListBox*)GetDlgItem(IDC_LIST1);
		sprintf_s(str, "%f - %f = %f",oper1,oper2,res);
		Lb->AddString(str);
	}
	catch(mException ex)
	{
		MessageBox ( ex.ShowStr(), "ERROR", MB_OK );
	}

}


void CMFCAppDlg::OnBnClickedButton3()
{

	try 
	{
		CString text;
		GetDlgItemText(IDC_EDIT1,text);
		double oper1 = StrtoDigit(text, text.GetLength());
		GetDlgItemText(IDC_EDIT2,text);
		double res, oper2 = StrtoDigit(text, text.GetLength());
		res = oper1 * oper2;
		char str[50];
		sprintf_s(str, "%f", res);
		SetDlgItemText(IDC_EDIT3, (LPCTSTR)str);
		CListBox* Lb = (CListBox*)GetDlgItem(IDC_LIST1);
		sprintf_s(str, "%f * %f = %f",oper1,oper2,res);
		Lb->AddString(str);

	}
	catch(mException ex)
	{
		MessageBox ( ex.ShowStr(), "ERROR", MB_OK );
	}

}


void CMFCAppDlg::OnBnClickedButton4()
{

	try 
	{
		CString text;
		GetDlgItemText(IDC_EDIT1,text);
		double oper1 = StrtoDigit(text, text.GetLength());
		GetDlgItemText(IDC_EDIT2,text);
		double res, oper2 = StrtoDigit(text, text.GetLength());
		if ( !oper2 ) 
			throw(mException("Division dy zero"));
		res = oper1 / oper2;
		char str[50];
		sprintf_s(str, "%f", res);
		SetDlgItemText(IDC_EDIT3, (LPCTSTR)str);
		CListBox* Lb = (CListBox*)GetDlgItem(IDC_LIST1);
		sprintf_s(str, "%f / %f = %f",oper1,oper2,res);
		Lb->AddString(str);
			
	}
	catch(mException ex)
	{
		MessageBox ( ex.ShowStr(), "ERROR", MB_OK );
	}

}


void CMFCAppDlg::OnLbnSelchangeList1()
{
	// TODO: �������� ���� ��� ����������� �����������
}


void CMFCAppDlg::OnBnClickedButton5()
{
	CListBox* Lb = (CListBox*)GetDlgItem(IDC_LIST1);
	for(int j = 0; j<5;j++)
	for (int itr = 0; itr < Lb->GetCount();itr++)
	Lb->DeleteString(itr);
}
