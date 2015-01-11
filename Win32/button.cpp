#include "button.h"

Button::Button(LPCTSTR name, int x, int y, int width, int height, int id, DWORD dwStyle)
	:ControlPart(name, x, y, width, height, id, dwStyle)
{	
}
Button::~Button()
{
}
void Button::Create(HWND hWndParent)
{
	this->hWndParent = hWndParent;
	hWnd = CreateWindowEx(0, "button", lpName, dwStyle, x, y, nWidth, nHeight, hWndParent, HMENU(hId), NULL, lpParam);
	if (!hWnd)
	{
		printf("CreateWindowEx failed:%d\n", GetLastError());
	}
	assert(hWnd);
}