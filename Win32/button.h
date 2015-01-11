#ifndef BUTTON_H_
#define BUTTON_H_

#include "controlpart.h"
class Button:public ControlPart
{
public:
	Button(LPCTSTR name = "button",  int x = 0, int y = 0, int width = 70, int height = 30, int id = 0, DWORD dwStyle = WS_CHILD|WS_VISIBLE);	
	virtual ~Button();
public:
	virtual void Create(HWND hWndParent);								//创建一个按键
};



#endif