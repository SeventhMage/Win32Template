#include "controlpart.h"

ControlPart::ControlPart(LPCTSTR name, int x, int y, int width, int height, int id, DWORD dwStyle)
	:lpName(name), x(x), y(y), nWidth(width), nHeight(height), hId(HMENU(id)),lpParam(0),dwStyle(dwStyle)
{	
}

//������ʾ��ʽ
void ControlPart::SetStyle(DWORD dwStyle)
{
	this->dwStyle = dwStyle;
}
//���ø�����ʽ
void ControlPart::SetExStyle(DWORD dwExStyle)
{
	this->dwExStyle = dwExStyle;
}
	
	//���ó�ʼλ��
void ControlPart::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
	//���ô��ڿ��
void ControlPart::SetWidth(int width)
{
	nWidth = width;
}
//���ô��ڸ߶�
void ControlPart::SetHeight(int height)
{
	nHeight = height;
}

//���ñ���
void ControlPart::SetBackground(LPCTSTR addr)
{
		
}