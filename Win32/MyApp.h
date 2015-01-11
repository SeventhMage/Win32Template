#ifndef MYAPP_H_
#define MYAPP_H_

#include "Window.h"
#include "Application.h"
#include "button.h"
#include "listbox.h"
#include "label.h"



#include <time.h>

#define MAINWIDTH 605
#define MAINHEIGHT 430


class MainWindow:public Window
{
public:
	MainWindow(LPCTSTR lpWindowName = "无标题");
	virtual ~MainWindow();
public:
	virtual void AddControl();
	virtual void Update();
public:
	//消息
	void OnCommand(WPARAM wParam, LPARAM lParam);
	void OnDraw(WPARAM wParam, LPARAM lParam);
	void OnSize(WPARAM wParam, LPARAM lParam);	
public:
	//控件
private:
	HDC m_hdc;
	unsigned int m_uWidth;
	unsigned int m_uHeight;
};



class MyApp:public Application
{
public:
	MyApp();
	virtual ~MyApp();
public:
	virtual void AddControl();
private:
	MainWindow *m_pMainWindow;
};

#endif