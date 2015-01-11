#include "label.h"

Label::Label(LPCTSTR name, int x, int y, int width, int height, int id, DWORD dwStyle)
	:ControlPart(name, x, y, width, height, id, dwStyle)
{
}
Label::~Label()
{
}

void Label::Create(HWND hWndParent)
{
	this->hWndParent = hWndParent;
	hWnd = CreateWindowEx(0, "static", lpName, dwStyle, x, y, nWidth, nHeight, hWndParent, HMENU(hId), NULL, lpParam);
	if (!hWnd)
	{
		printf("CreateWindowEx failed:%d\n", GetLastError());
	}
	assert(hWnd);
}