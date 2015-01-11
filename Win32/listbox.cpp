#include "listbox.h"
#include <cassert>
ListBox::ListBox(LPCTSTR name,  int x, int y, int width, int height, int id, DWORD dwStyle)
	:ControlPart(name, x, y, width, height, id, dwStyle)
{
}

void ListBox::Create(HWND hWndParent)
{
	this->hWndParent = hWndParent;
	hWnd = CreateWindowEx(0, "listbox", lpName, dwStyle, x, y, nWidth, nHeight, hWndParent, hId, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), lpParam);
		assert(hWnd);
}