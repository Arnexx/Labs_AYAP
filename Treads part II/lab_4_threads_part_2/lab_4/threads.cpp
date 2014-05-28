#include "threads.hpp"


DWORD WINAPI drawfunc(void* pParams)
{
	WindowParams* params = (WindowParams*) pParams;
	int Index = 0;
	while(! params->shapes_in_thread[Index])
		Index++;
	int pos = lastShapes + Index * (MAXSH / threadsCounter);
	params->shapes_in_thread[Index] = 0;
	while(1)
	{
		if(! params->onDraw)
		{
			params->onDraw = true;
			for(int itr = pos; itr < pos + MAXSH / threadsCounter; itr++)
			{
				params->mShapes[itr]->Wipe(params);
				params->mShapes[itr]->setPosition(params);
				params->mShapes[itr]->DrawShape(params);
			}	

		RECT rect;
		GetClientRect(params->hWnd, &rect);

		InvalidateRect(params->hWnd, &rect, 0);
		SendMessage(params->hWnd,WM_PAINT,0,0);
		params->onDraw = false;
		}
		Sleep(15);
	}
	DWORD temp = NULL;
	return temp;
}

DWORD WINAPI catchEvent(void* pParams)
{
	WindowParams* params = (WindowParams*) pParams;
	HANDLE hEvent = params->H_event;
	while(1)
	{
		WaitForSingleObject(hEvent,INFINITE); 

		while(WaitForSingleObject(hEvent, 0)==WAIT_OBJECT_0)
		{
			params->RotationEvent = true;
		}
		params->RotationEvent = false;

	}

}

void newThreads(WindowParams* params)
{
	for(int itr = 0; itr < threadsCounter; itr++)
	{
		DWORD* temp = new DWORD;
		HANDLE* tempHandle = new HANDLE;
		params->ThreadVector.push_back(temp);
		if(itr == threadsCounter -1)
			*tempHandle = CreateThread(NULL, 0, catchEvent, params, 0, temp);
		else
			*tempHandle = CreateThread(NULL, 0, drawfunc, params, 0, temp);
		params->ThreadHandles.push_back(tempHandle);
	}
}

void killThreads(WindowParams* params)
{
	for(int itr = 0; itr < threadsCounter; itr++)
	{
		CloseHandle( *(params->ThreadHandles[itr]) );
		delete params->ThreadVector[itr];
		delete params->ThreadHandles[itr];

	}
	// 	CloseHandle( *(params->ThreadHandles[0]) );
	// 	delete params->ThreadVector[0];
	// 	delete params->ThreadHandles[0];
}