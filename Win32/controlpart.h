/*
**�ؼ������
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
	//���ñ���
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