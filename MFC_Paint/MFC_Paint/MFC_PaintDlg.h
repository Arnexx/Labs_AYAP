
// MFC_PaintDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CMFC_PaintDlg
class CMFC_PaintDlg : public CDialogEx
{
// Создание
public:
	CMFC_PaintDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_MFC_PAINT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	CDC memDC;
	BITMAP bmp;  // характеристики bmp образа, структура
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void On32771();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
