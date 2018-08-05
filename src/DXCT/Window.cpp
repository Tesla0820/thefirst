//
//		ファイル名:Window.cpp
//

#include "Window.h"

namespace DXCT
{

Window::Window(LPCTSTR className, LPCTSTR windowName,int width,int height)
{
	DWORD windowStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
	HINSTANCE hInst = ::GetModuleHandle(NULL);
	WNDCLASSEX wcex =
	{
		sizeof(wcex),
		CS_CLASSDC,
		WindowsProcBase,
		0,
		0,
		hInst,
		NULL,
		::LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		className,
		NULL
	};

	::RegisterClassEx(&wcex);
	_windowHandle = ::CreateWindowEx(0,className, windowName, windowStyle, CW_USEDEFAULT, CW_USEDEFAULT, width,height, NULL, NULL, hInst, this);
	_className = className;
	_isReleased = false;
}

Window::~Window()
{
	Release();
}

HWND Window::GetHandle()
{
	return _windowHandle;
}

void Window::SetTitle(std::wstring title)
{
	::SetWindowText(_windowHandle, title.c_str());
}

std:: wstring Window::GetTitle()
{
	constexpr int text_length = 1024;
	TCHAR text[text_length];
	::GetWindowText(_windowHandle, text, text_length);
	return std::wstring(text);
}

void Window::Show()
{
	::ShowWindow(_windowHandle, SW_SHOWDEFAULT);
	::UpdateWindow(_windowHandle);
}

void Window::Close()
{
	//閉じる前に確認する場合のため、直接閉じない
	::SendMessage(_windowHandle, WM_CLOSE, 0, 0);
}

void Window::SetPosition(RECT const * rect)
{
	::SetWindowPos(_windowHandle, NULL, rect->left, rect->top, rect->right, rect->bottom, SWP_NOZORDER);
}

void Window::GetClientRect(RECT * rect)
{
	::GetClientRect(_windowHandle, rect);
}

void Window::GetPosition(RECT *rect)
{
	::GetWindowRect(_windowHandle, rect);
}



LRESULT Window::WindowsProcBase(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	Window* window = reinterpret_cast<Window*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));

	if (!window)
	{
		//取得失敗

		if (msg == WM_CREATE)
		{
			//作成中の場合
			//LPにwindowのthisポインタが格納されているため
			window = reinterpret_cast<Window*>(((LPCREATESTRUCT)lp)->lpCreateParams);
			window->_windowHandle = hWnd;
			::SetWindowLongPtr(hWnd, GWLP_USERDATA,reinterpret_cast<LONG_PTR>(window));
		}
	}
	if (window)
	{
		bool isHooked=false;
		LRESULT result = window->WindowProc(msg, wp, lp, &isHooked);
		//メッセージがフックされた場合のみ
		if (isHooked)
		{
			return result;
		}
	}
	return ::DefWindowProc(hWnd, msg, wp, lp);
}


LRESULT Window::WindowProc(UINT msg, WPARAM wp, LPARAM lp, bool* isHooked)
{
	if (msg == WM_CLOSE)
	{
		Release();
		*isHooked = true;
	}
	return	0;
}

#pragma region IReleasable 

void Window::Release()
{
	if (_isReleased) return;
	if (_windowHandle != NULL)
	{
		if (::IsWindow(_windowHandle))
		{
			::DestroyWindow(_windowHandle);
		}
		if (!_className.empty())
		{
			::UnregisterClass(_className.c_str(), ::GetModuleHandle(NULL));
		}
	}

	_isReleased = true;
}
bool Window::IsReleased()
{
	return _isReleased;
}
#pragma endregion

}

