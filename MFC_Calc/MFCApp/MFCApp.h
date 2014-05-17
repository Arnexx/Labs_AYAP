
// MFCApp.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCAppApp:
// О реализации данного класса см. MFCApp.cpp
//

class CMFCAppApp : public CWinApp
{
public:
	CMFCAppApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCAppApp theApp;