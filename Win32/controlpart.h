/*
**控件类基类
*/
#ifndef CONTROLPART_H_
#define CONTROLPART_H_
#include <windows.h>
#include <cstdio>
#include <cassert>
using namespace std;

class ControlPart
{
public:
	ControlPart(LPCTSTR name,  int x, int y, int width, int height, int id, DWORD dwStyle);
	virtual ~ControlPart(){}
	virtual void Create(HWND hWndParent)=0;
	LPCTSTR GetName()const{return lpName;}
	HWND GetHandle()const{return hWnd;}
	friend class Window;
//成员函数
public:
	//设置显示样式
	void SetStyle(DWORD dwStyle);
	//设置附加样式
	void SetExStyle(DWORD dwExStyle);
	//设置初始位置
	void SetPosition(int x, int y);
	//设置窗口宽度
	void SetWidth(int width);
	//设置窗口高度
	void SetHeight(int height);
	//设置背景
	void SetBackground(LPCTSTR addr);
protected:
	LPCTSTR lpName; 			// window name
  DWORD dwStyle;        // window style
  DWORD dwExStyle;
  int x;                // horizontal position of window
  int y;                // vertical position of window
  int nWidth;           // window width
  int nHeight;          // window height
  HWND hWndParent;      // handle to parent or owner window
  HMENU hId;          	// menu handle or child identifier
  LPVOID lpParam;       // window-creation data
  HWND hWnd;
};

#endif