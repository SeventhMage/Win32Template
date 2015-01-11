#include "controlpart.h"

ControlPart::ControlPart(LPCTSTR name, int x, int y, int width, int height, int id, DWORD dwStyle)
	:lpName(name), x(x), y(y), nWidth(width), nHeight(height), hId(HMENU(id)),lpParam(0),dwStyle(dwStyle)
{	
}

//设置显示样式
void ControlPart::SetStyle(DWORD dwStyle)
{
	this->dwStyle = dwStyle;
}
//设置附加样式
void ControlPart::SetExStyle(DWORD dwExStyle)
{
	this->dwExStyle = dwExStyle;
}
	
	//设置初始位置
void ControlPart::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
	//设置窗口宽度
void ControlPart::SetWidth(int width)
{
	nWidth = width;
}
//设置窗口高度
void ControlPart::SetHeight(int height)
{
	nHeight = height;
}

//设置背景
void ControlPart::SetBackground(LPCTSTR addr)
{
		
}