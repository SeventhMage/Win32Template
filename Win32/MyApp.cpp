#include "MyApp.h"

int g_iWidth;
int g_iHeight;

MainWindow::MainWindow(LPCTSTR lpWindowName):Window(lpWindowName)
{
	m_mapMsgFun[WM_COMMAND] = (PMSGFUN)&MainWindow::OnCommand;
	m_mapMsgFun[WM_PAINT] = (PMSGFUN)&MainWindow::OnDraw;
	m_mapMsgFun[WM_SIZE] = (PMSGFUN)&MainWindow::OnSize;
		
}
MainWindow::~MainWindow()
{
}

void MainWindow::AddControl()
{	
}

void MainWindow::OnCommand(WPARAM wParam, LPARAM lParam)
{
		;
}

void MainWindow::OnDraw(WPARAM wParam, LPARAM lParam)
{
	
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(GetHandle(), &ps);
	
	EndPaint(GetHandle(), &ps);
}

void MainWindow::OnSize(WPARAM wParam, LPARAM lParam)
{
	m_uWidth = LOWORD(lParam);
	m_uHeight = HIWORD(lParam);
}

void MainWindow::Update()
{
	
}

/////////////////////////////////////////////////////
//MyApp
/////////////////////////////////////////////////////
MyApp::MyApp()
{
	m_pMainWindow = new MainWindow("ÎÞ±êÌâ");
	assert(m_pMainWindow);
}

MyApp::~MyApp()
{
	
}


void MyApp::AddControl()
{
	m_pMainWindow->SetStyle(WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME);
	m_pMainWindow->SetWidth(MAINWIDTH);
	m_pMainWindow->SetHeight(MAINHEIGHT);
	HANDLE hWnd = ShowWindow(m_pMainWindow);
	WaitForSingleObject(hWnd, INFINITE);
	CloseHandle(hWnd);
}
