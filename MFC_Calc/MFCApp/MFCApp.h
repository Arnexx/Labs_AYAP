
// MFCApp.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFCAppApp:
// � ���������� ������� ������ ��. MFCApp.cpp
//

class CMFCAppApp : public CWinApp
{
public:
	CMFCAppApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFCAppApp theApp;