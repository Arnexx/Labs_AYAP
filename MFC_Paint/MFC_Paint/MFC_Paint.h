
// MFC_Paint.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFC_PaintApp:
// � ���������� ������� ������ ��. MFC_Paint.cpp
//

class CMFC_PaintApp : public CWinApp
{
public:
	CMFC_PaintApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFC_PaintApp theApp;