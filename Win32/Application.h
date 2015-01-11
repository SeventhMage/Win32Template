#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <process.h>
#include <windows.h>
#include "Window.h"

class Application;
typedef struct _App_WindowInfo
{
	Application *pApp;
	Window *pWindow;
	HANDLE hEvent;			//��֤�������߳��б��ɹ�����
}APP_FORMINFO, *PAPP_FORMINFO;

class Application
{
public:
	Application();
	virtual ~Application();
public:
	virtual void AddControl();
	void Run();
protected:
	HANDLE ShowWindow(Window *pf);
private:
	static unsigned int WINAPI Running(LPVOID lpv);
private:
	CRITICAL_SECTION m_cs;
};

#endif