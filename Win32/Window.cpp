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
	else if (WM_DESTROY == msg)		//��֤��û����Ϣ��Ӧ����������´�������������
	{
		PostQuitMessage(0);
		return 0;
	}
	else
	{
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

//������ʾ��ʽ
void Window::SetStyle(DWORD dwStyle)
{
	this->dwStyle = dwStyle;
}
//���ø�����ʽ
void Window::SetExStyle(DWORD dwExStyle)
{
	this->dwExStyle = dwExStyle;
}
	
	//���ó�ʼλ��
void Window::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
	//���ô��ڿ��
void Window::SetWidth(int width)
{
	nWidth = width;
}
//���ô��ڸ߶�
void Window::SetHeight(int height)
{
	nHeight = height;
}
	//������ʾ��ʽ
void Window::ShowWay(int show)
{
	nShow = show;
}
//���ñ���
void Window::SetBackground(LPCTSTR addr)
{
		
}
//���һ���ؼ�
void Window::Add(ControlPart *pcp)
{
	pcp->Create(hWnd);
}
//��������
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

