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
	Window(LPCTSTR lpWindowName = "�ޱ���");
	virtual~Window();
//��Ա����
public:
	//������ʾ��ʽ
	void SetStyle(DWORD dwStyle);
	//���ø�����ʽ
	void SetExStyle(DWORD dwExStyle);
	//���ó�ʼλ��
	void SetPosition(int x, int y);
	//���ô��ڿ��
	void SetWidth(int width);
	//���ô��ڸ߶�
	void SetHeight(int height);
	//������ʾ��ʽ
	void ShowWay(int show);
	//���ñ���
	void SetBackground(LPCTSTR addr);
	//���һ���ؼ�
	void Add(ControlPart *pcp);
	//��������
	HWND Create();
	HWND GetHandle();
protected:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT winProc(UINT msg, WPARAM wParam, LPARAM lParam);
private:
	ATOM MyRegisterClass();
	int GetNShow();
	friend class Application;
	
//�麯��
protected:
	virtual void AddControl();			//������Ҫ��ӿؼ�ʱд������
	virtual void Update();
	
//��Ա����
protected:
	typedef void (Window::*PMSGFUN)(WPARAM wParam, LPARAM lParam);
	map<UINT, PMSGFUN> m_mapMsgFun;								//��Ϣӳ���
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
	
	static map<HWND, Window *> m_mapHWndToPWindow;		//HWND�����ָ���ӳ��
	static int windowNum;		//��������
};



#endif