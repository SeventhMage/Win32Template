#include "Application.h"
#include "button.h"

Application::Application()
{
	InitializeCriticalSection(&m_cs);
}

Application::~Application()
{
	DeleteCriticalSection(&m_cs);
}

void Application::Run()
{
	AddControl();
}

HANDLE Application::ShowWindow(Window *pf)
{
	APP_FORMINFO afInfo = {this, pf, CreateEvent(NULL, false, false, NULL)};
	
	if (!afInfo.hEvent)
	{
		printf("CreateEvent() error:%d", GetLastError());
		return NULL;
	}
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, &Application::Running, &afInfo, 0, NULL);	
	if (!hThread)
	{
		printf("_beginthreadex() failed\n");
		return NULL;
	}
	WaitForSingleObject(afInfo.hEvent, INFINITE);
	return hThread;
}


void Application::AddControl()
{
	
}

unsigned int WINAPI Application::Running(LPVOID lpv)
{
	assert(lpv);
	
	PAPP_FORMINFO pafInfo = (PAPP_FORMINFO)lpv;
	
	Window *pf = pafInfo->pWindow;
	Application *pApp = pafInfo->pApp;
	
	SetEvent(pafInfo->hEvent);
	CloseHandle(pafInfo->hEvent);
	
	pf->Create();
	pf->AddControl();
	
	HWND hWnd = pf->GetHandle();	
	::ShowWindow(hWnd, pf->GetNShow());
	::UpdateWindow(hWnd);
	if (!hWnd)
	{
		printf("UpdateWindow() error:%d\n", GetLastError());
		return 0;
	}	
	
	MSG msg;
	memset(&msg, 0, sizeof(MSG));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage (&msg);
  		DispatchMessage (&msg);
		}
		else
		{
			pf->Update();
		}
	}
	
	return 0;
}