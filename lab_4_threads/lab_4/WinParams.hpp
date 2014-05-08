#pragma once
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#define _USE_MATH_DEFINES
#define WM_INITPARAMS     (WM_USER + 0)
#define  MAXSH               18
#define  threadsCounter      5
#define  lastShapes          MAXSH % threadsCounter + MAXSH/threadsCounter

struct G_Point 
{
	int x;
	int y;
};
class Shape;
struct  WindowParams
{
	HDC compatibleDc;
	HWND hWnd;
	HBITMAP compatibleBitmap;
	HBITMAP oldBitmap;
	UINT_PTR mTimer;
	Shape* mShapes[MAXSH];
	vector<DWORD*> ThreadVector;
	vector<HANDLE*> ThreadHandles;
	vector<int>   shapes_in_thread;
	bool onDraw;
	
		
};
