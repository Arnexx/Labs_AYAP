#pragma  once
#include "Line.hpp"
#include "Square.hpp"
#include "Octahedron.hpp"
#include <math.h>
#include <time.h>
#define  REDRAW             1100
#define  WM_INITPARAMS      (WM_USER + 0)
#define  MAXSH               15

LRESULT CALLBACK WndProc( HWND, UINT, UINT, LONG);

Shape* mVector[MAXSH];

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pszCmdParam, int nCmdShow)
{
	WNDCLASS WndClass;
	MSG Msg;
	WindowParams params;
	HWND  hWnd;
	char* szClassName="mWindowClass";
	memset(&WndClass, 0, sizeof(WndClass));
	WndClass.hInstance = hInstance;
	WndClass.lpszClassName = szClassName;
	WndClass.lpfnWndProc = WndProc;
	WndClass.hbrBackground = GetSysColorBrush(COLOR_WINDOW);
	WndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL,IDI_ERROR);


	if (!RegisterClass(&WndClass))
	{
		MessageBox(NULL,"Cannot register class","Error",MB_OK);
	}													  

	hWnd = CreateWindow(szClassName,(LPSTR)"Lab_4",WS_OVERLAPPEDWINDOW,0,0,1300,700,NULL,NULL,hInstance,NULL);

	params.hWnd = hWnd;

	SetWindowLongPtr( hWnd, GWLP_USERDATA, (LONG)&params );
	SendMessage( hWnd,	WM_INITPARAMS, 0, 0 );
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);

	
	while(GetMessage(&Msg,NULL,0,0))
	{
		
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		
	}
	return Msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, UINT wParam, LONG lParam)
{
	WindowParams* params;	
	params = (WindowParams*)GetWindowLongPtr(hWnd, GWLP_USERDATA );
	srand(time(NULL));
	switch(msg)
	{
	case WM_INITPARAMS:
		{
			RECT rect;
			HDC hdc = GetDC( hWnd );

			GetClientRect( hWnd, &rect );
			params->compatibleDc = CreateCompatibleDC( hdc );
			params->compatibleBitmap = CreateCompatibleBitmap( hdc, rect.right - rect.left+2000, rect.bottom - rect.top+2000 );
			params->oldBitmap = (HBITMAP)SelectObject(params->compatibleDc, params->compatibleBitmap );
			params->mTimer = SetTimer(hWnd, 1, 1000/60 , 0);
			
			
			HBRUSH brush = CreateSolidBrush( RGB(255,255,255));
			HBRUSH old = (HBRUSH)SelectObject(params->compatibleDc, brush);
			PatBlt(params->compatibleDc, 0, 0, rect.right - rect.left+2000, rect.bottom - rect.top+2000, PATCOPY);
			SelectObject(params->compatibleDc, old);
			DeleteObject(brush);

			G_Point temp;
			temp.x = 0;
			temp.y = 0;
			for (int itr = 0; itr < MAXSH; itr++)
			{
				temp.x = rand()%1000;
				temp.y = rand()%500;
				if(itr % 3 == 1)
					mVector[itr] = new Square(temp, rand()%200+30, M_PI/(float)(rand()%12),
					                   M_PI/70.0, rand()%2, rand()%5+2, rand()%256, rand()%256, rand()%256);

				if (itr % 3 == 2)
					mVector[itr] = new Octahedron(temp, rand()%200+30, M_PI/(float)(rand()%12),
					                   M_PI/70.0, rand()%2, rand()%5+2, rand()%256, rand()%256, rand()%256);

				if (itr % 3 == 0)
					mVector[itr] = new Line(temp, rand()%200+30, M_PI/(float)(rand()%12),
					                       M_PI/70.0, rand()%2, rand()%5+2, rand()%256, rand()%256, rand()%256);
				mVector[itr]->DrawShape(params);
			}


			ReleaseDC( hWnd, hdc );
		}
		break;
	
	case WM_SIZE:
		{
			RECT rect;
			GetClientRect(hWnd, &rect);
			InvalidateRect(hWnd, &rect, 0);
			SendMessage(hWnd,WM_PAINT,0,0);
		}
		break;

	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			RECT rect;
			HDC hdc = BeginPaint( hWnd , &ps );
			if (params)
			{
				GetClientRect( hWnd, &rect );
				BitBlt( hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, params->compatibleDc, 0, 0, SRCCOPY );
			}
			EndPaint( hWnd , &ps );
		}
		break;

	case  WM_TIMER :
		{
			RECT rect;
			GetClientRect(hWnd, &rect);
			for (int itr = 0; itr < MAXSH; itr++)
			{
				mVector[itr]->Wipe(params);
				mVector[itr]->setPosition(params);
				mVector[itr]->DrawShape(params);
			}
			InvalidateRect(hWnd, &rect, 0);
			SendMessage(hWnd,WM_PAINT,0,0);
		}
		break;

	case WM_DESTROY: 
		{
			KillTimer(hWnd, 1);
			SelectObject( params->compatibleDc,	params->oldBitmap );
			DeleteObject( params->compatibleBitmap );
			DeleteObject( params->compatibleDc );
			PostQuitMessage(0);
		}
		break;

	default:
		return DefWindowProc(hWnd,msg,wParam,lParam);
	}
	return 0;
}
