#pragma once
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <math.h>
#include "iostream"
#include <vector>
using namespace std;
#define _USE_MATH_DEFINES
#define WM_INITPARAMS     (WM_USER + 0)

struct G_Point 
{
	int x;
	int y;
};

struct  WindowParams
{
	HDC compatibleDc;
	HWND hWnd;
	HBITMAP compatibleBitmap;
	HBITMAP oldBitmap;
	UINT_PTR mTimer;
	//int time;
	
};