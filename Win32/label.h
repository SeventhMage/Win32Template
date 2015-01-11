#ifndef LABEL_H_
#define LABEL_H_

#include "controlpart.h"

class Label:public ControlPart
{
public:
	Label(LPCTSTR name = "label",  int x = 0, int y = 0, int width = 70, int height = 30, int id = 0, DWORD dwStyle = WS_CHILD|WS_VISIBLE);	
	virtual ~Label();
public:
	virtual void Create(HWND hWndParent);								//创建一个Label;
};

#endif