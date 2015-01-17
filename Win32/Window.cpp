#include "Window.h"

map<HWND, Window *> Window::m_mapHWndToPWindow;
int Window::windowNum = 0;

Window::Window(LPCTSTR lpWindowName)
		:dwExStyle(0), lpWindowName(lpWindowName), dwStyle(WS_OVERLAPPEDWINDOW), 
			x(CW_USEDEFAULT), y(CW_USEDEFAULT), nWidth(CW_USEDEFAULT), nHeight(CW_USEDEFAULT), nShow(SW_SHOWNORMAL)
{
	char *buf = new char[48];
	assert(buf);
	sprintf(buf, "%s%d", "window", windowNum);
	lpClassName = buf;
	windowNum++;
}
Window::~Window()
{
	UnregisterClass(lpClassName, GetModuleHandle(NULL));
	delete[]lpClassName;
	windowNum--;
}

ATOM Window::MyRegisterClass()				
{
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= &Window::WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= GetModuleHandle(NULL);
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL; //MAKEINTRESOURCE(IDC_GETDESKTOP);
	wcex.lpszClassName	= lpClassName;
	wcex.hIconSm		= NULL;
	return RegisterClassEx(&wcex);
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Window *pWindow = m_mapHWndToPWindow[hWnd];
	
	if (pWindow)
	{
		return pWindow->winProc(msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT Window::winProc(UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (m_mapMsgFun[msg])
	{
		(this->*m_mapMsgFun[msg])(wParam, lParam);
		return 0;
	}
	else if (WM_DESTROY == msg)		//保证在没有消息响应函数的情况下窗口能正常消毁
	{
		PostQuitMessage(0);
		return 0;
	}
	else
	{
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

//设置显示样式
void Window::SetStyle(DWORD dwStyle)
{
	this->dwStyle = dwStyle;
}
//设置附加样式
void Window::SetExStyle(DWORD dwExStyle)
{
	this->dwExStyle = dwExStyle;
}
	
	//设置初始位置
void Window::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
	//设置窗口宽度
void Window::SetWidth(int width)
{
	nWidth = width;
}
//设置窗口高度
void Window::SetHeight(int height)
{
	nHeight = height;
}
	//设置显示格式
void Window::ShowWay(int show)
{
	nShow = show;
}
//设置背景
void Window::SetBackground(LPCTSTR addr)
{
		
}
//添加一个控件
void Window::Add(ControlPart *pcp)
{
	pcp->Create(hWnd);
}
//创建窗口
HWND Window::Create()
{
	MyRegisterClass();
	hWnd = CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, NULL, NULL, NULL, NULL);
	if (!hWnd)
	{
		printf("CreateWindowEx() error:%d\n", GetLastError());
	}
  assert(hWnd);
  m_mapHWndToPWindow[hWnd] = this;
	return hWnd;
}

HWND Window::GetHandle()
{
	return hWnd;
}

int Window::GetNShow()
{
	return nShow;
}

void Window::AddControl()
{
	
}

void Window::Update()
{
	
}

void Window::Init()
{

}

