#include "myapp.h"
#include "Window.h"
#include "Application.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lp, int nCmdShow)
//int main(void)
{
	MyApp myApp(nPortSvr);
	myApp.Run();
	return 0;
}