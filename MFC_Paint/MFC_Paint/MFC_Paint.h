
// MFC_Paint.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFC_PaintApp:
// О реализации данного класса см. MFC_Paint.cpp
//

class CMFC_PaintApp : public CWinApp
{
public:
	CMFC_PaintApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFC_PaintApp theApp;