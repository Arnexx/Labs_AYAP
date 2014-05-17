
// MFCAppDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CMFCAppDlg
class CMFCAppDlg : public CDialogEx
{
// Создание
public:
	CMFCAppDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_MFCAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton5();
};
