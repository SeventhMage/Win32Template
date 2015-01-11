#ifndef FORM_H_
#define FORM_H_

#include <windows.h>
#include <cstdio>
#include <map>
#include <iostream>
#include <cassert>
//#include "application.hpp"
#include "controlpart.h"

using namespace std;

class Window
{
public:
	Window(LPCTSTR lpWindowName = "无标题");
	virtual~Window();
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
	//设置显示格式
	void ShowWay(int show);
	//设置背景
	void SetBackground(LPCTSTR addr);
	//添加一个控件
	void Add(ControlPart *pcp);
	//创建窗口
	HWND Create();
	HWND GetHandle();
protected:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT winProc(UINT msg, WPARAM wParam, LPARAM lParam);
private:
	ATOM MyRegisterClass();
	int GetNShow();
	friend class Application;
	
//虚函数
protected:
	virtual void AddControl();			//子类需要添加控件时写在这里
	virtual void Update();
	
//成员变量
protected:
	typedef void (Window::*PMSGFUN)(WPARAM wParam, LPARAM lParam);
	map<UINT, PMSGFUN> m_mapMsgFun;								//消息映射表
private:
  LPCTSTR lpClassName;  // registered class name
  LPCTSTR lpWindowName; // window name
  DWORD dwExStyle;      // extended window style
  DWORD dwStyle;        // window style
  int x;                // horizontal position of window
  int y;                // vertical position of window
  int nWidth;           // window width
  int nHeight;          // window height
  
  int nShow;						//window show state
	HWND hWnd;
	WNDCLASSEX wcex;
	
	static map<HWND, Window *> m_mapHWndToPWindow;		//HWND与对象指针的映射
	static int windowNum;		//窗口数量
};



#endif