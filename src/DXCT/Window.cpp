//
//		�t�@�C����:Window.cpp
//

#include "Window.h"

namespace DXCT
{

//�E�B���h�E�N���X���A�E�B���h�E�^�C�g���A�T�C�Y���g�p���ăE�B���h�E���쐬���܂��B
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

//�E�B���h�E��������܂��B
Window::~Window()
{
	Release();
}

//�E�B���h�E�n���h�����擾���܂��B
HWND Window::GetHandle()
{
	return _windowHandle;
}

//�E�B���h�E�^�C�g����ݒ肵�܂��B
void Window::SetTitle(std::wstring title)
{
	::SetWindowText(_windowHandle, title.c_str());
}

//�E�B���h�E�^�C�g�����擾���܂��B
std:: wstring Window::GetTitle()
{
	constexpr int text_length = 1024;
	TCHAR text[text_length];
	::GetWindowText(_windowHandle, text, text_length);
	return std::wstring(text);
}

//�E�B���h�E��\�����܂��B
void Window::Show()
{
	::ShowWindow(_windowHandle, SW_SHOWDEFAULT);
	::UpdateWindow(_windowHandle);
}

//�E�B���h�E����܂��B
void Window::Close()
{
	//����O�Ɋm�F����ꍇ�̂��߁A���ڕ��Ȃ�
	::SendMessage(_windowHandle, WM_CLOSE, 0, 0);
}

//�E�B���h�E�̈ʒu�A�T�C�Y��ݒ肵�܂��B
void Window::SetPosition(RECT const * rect)
{
	::SetWindowPos(_windowHandle, NULL, rect->left, rect->top, rect->right, rect->bottom, SWP_NOZORDER);
}

//�E�B���h�E�̃N���C�A���g�̈���擾���܂��B
void Window::GetClientRect(RECT * rect)
{
	::GetClientRect(_windowHandle, rect);
}

//�E�B���h�E�̑S�̃T�C�Y���擾���܂��B
void Window::GetPosition(RECT *rect)
{
	::GetWindowRect(_windowHandle, rect);
}


//Win32API�̃v���V�[�W������e Window �N���X�փ��b�Z�[�W��`�d���܂��B
LRESULT Window::WindowsProcBase(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	Window* window = reinterpret_cast<Window*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));//���[�U�[�|�C���^����ǂ�Window�N���X���擾����B

	if (!window)
	{
		//�擾���s

		if (msg == WM_CREATE)
		{
			//�쐬���̏ꍇ
			//LP��window��this�|�C���^���i�[����Ă��邽��
			window = reinterpret_cast<Window*>(((LPCREATESTRUCT)lp)->lpCreateParams);
			window->_windowHandle = hWnd;
			::SetWindowLongPtr(hWnd, GWLP_USERDATA,reinterpret_cast<LONG_PTR>(window));//���[�U�[�|�C���^��this���Z�b�g
		}
	}
	if (window)
	{
		//�擾����
		bool isHooked=false;
		LRESULT result = window->WindowProc(msg, wp, lp, &isHooked);
		//���b�Z�[�W���t�b�N���ꂽ�ꍇ�̂�
		if (isHooked)
		{
			return result;
		}
	}
	//WM_CREATE����������܂ł̊ԁA�܂��̓��[�U�[�|�C���^�̎擾�Ɏ��s�����ꍇ�A�܂��̓��b�Z�[�W���t�b�N����Ȃ������B
	return ::DefWindowProc(hWnd, msg, wp, lp);
}

//���b�Z�[�W���t�b�N���܂��B
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
//�E�B���h�E��������܂��B
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

//�E�B���h�E��������ꂽ���擾���܂��B
bool Window::IsReleased()
{
	return _isReleased;
}
#pragma endregion

}

