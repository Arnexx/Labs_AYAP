
// MFC_PaintDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFC_Paint.h"
#include "MFC_PaintDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
public:
//	afx_msg void OnMenu();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_COMMAND(ID_32771, &CAboutDlg::OnMenu)
END_MESSAGE_MAP()


// ���������� ���� CMFC_PaintDlg



CMFC_PaintDlg::CMFC_PaintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_PaintDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_PaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_PaintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_PaintDlg::OnBnClickedButton1)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32771, &CMFC_PaintDlg::On32771)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ����������� ��������� CMFC_PaintDlg

BOOL CMFC_PaintDlg::OnInitDialog()
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
	RECT rect;
	GetClientRect(&rect);
	rect.bottom = 1500;
	rect.right = 1500;
	CClientDC dc(this);
	// �������� ������
	memDC.CreateCompatibleDC(&dc);
	CBitmap backgroundBitmap;
	CBrush mBrush;
	backgroundBitmap.CreateCompatibleBitmap(&dc, 2000, 2000);
	mBrush.CreateSolidBrush(RGB(255,255,255));
	memDC.SelectObject(&mBrush);
	memDC.SelectObject(&backgroundBitmap);
	memDC.Rectangle(&rect);

	
	backgroundBitmap.GetObject(sizeof(BITMAP),&bmp); 

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMFC_PaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_PaintDlg::OnPaint()
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
HCURSOR CMFC_PaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_PaintDlg::OnBnClickedButton1()
{
	
}


void CMFC_PaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if( (nFlags & MK_LBUTTON)==MK_LBUTTON )
	{
		
		
		
		
		
		
		CClientDC dc(this);
		RECT ellipse;
		ellipse.top =point.y-25;
		ellipse.bottom = point.y +25;
		ellipse.left = point.x-25;
		ellipse.right = point.x+25;

		
		CPen aPen;
		aPen.CreatePen(PS_DASH, 2, RGB(0, 0, 255));
		CPen *pOldPen = memDC.SelectObject(&aPen);
		CBrush aBrush;
		
		aBrush.CreateHatchBrush(HS_VERTICAL,RGB(255,0,0));
		CBrush *pOldBrush = memDC.SelectObject(&aBrush);
		memDC.Ellipse(&ellipse);
		//��������������� ������ ���� � �����
		memDC.SelectObject(pOldPen);
		memDC.SelectObject(pOldBrush);
		dc.BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 
			0, 0, SRCCOPY);

	}

	CDialogEx::OnMouseMove(nFlags, point);
}

// 
// void CAboutDlg::OnMenu()
// {
// 	CClientDC dc(this);
// 	RECT rect;
// 	GetClientRect(&rect);
// 	dc.Rectangle(&rect);
// }

void CMFC_PaintDlg::On32771()
{
	CClientDC dc(this);
	CBrush mBrush;
	RECT rect;
	GetClientRect(&rect);
	rect.bottom =2000;
	rect.right = 2000;
	mBrush.CreateSolidBrush(RGB(255,255,255));
	memDC.SelectObject(&mBrush);
 	memDC.Rectangle(&rect);	
	dc.BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 
		0, 0, SRCCOPY);
	
}


void CMFC_PaintDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CClientDC dc(this);
	dc.BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 
		0, 0, SRCCOPY);
}
