#ifndef LISTBOX_H_
#define LISTBOX_H_
#include "controlpart.h"

class ListBox:public ControlPart
{
public:
	ListBox(LPCTSTR name = "listbox",  int x = 0, int y = 0, int width = 80, int height = 100, int id = 0, DWORD dwStyle = WS_CHILD|WS_VISIBLE|WS_VSCROLL );
	virtual ~ListBox(){}
private:
	virtual void Create(HWND hWndParent);
};



#endif