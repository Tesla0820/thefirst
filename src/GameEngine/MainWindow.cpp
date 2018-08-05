//
//		ファイル名		：MainWindow.cpp
//

//---インクルード部---
#include "MainWindow.h"

namespace GameEngine
{

MainWindow::MainWindow(int width,int height):Window(TEXT("Main"), TEXT("Game"),width,height)
{

}

MainWindow::~MainWindow()
{

}

LRESULT MainWindow::WindowProc(UINT msg, WPARAM wp, LPARAM lp, bool * isHooked)
{
	switch (msg)
	{
		case WM_CREATE:
			break;

		case WM_DESTROY:
			*isHooked = true;
			::PostQuitMessage(0);
			return 0;

		default:
			break;

	}
	return Window::WindowProc(msg, wp, lp, isHooked);
}

}