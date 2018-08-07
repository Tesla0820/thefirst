//
//		ファイル名:Window.h
//

#ifndef HEADER_WINDOW_H
#define HEADER_WINDOW_H

#include <string>
#include "dxct_inner.h"
#include "IReleasable.h"

namespace DXCT
{

//ウィンドウの管理クラスです。
class Window :public IReleasable
{
	private:
		std::wstring _className;
		HWND _windowHandle;
		//IReleasable
		bool _isReleased;

		Window() = delete;

		static LRESULT CALLBACK WindowsProcBase(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

	protected:
		virtual LRESULT WindowProc(UINT msg, WPARAM wp, LPARAM lp, bool *isHooked);

	public:
		Window(LPCTSTR className, LPCTSTR windowName, int width, int height);
		Window(Window const&) = default;
		Window(Window && window) noexcept = default;
		Window& operator=(Window const&) = default;
		Window& operator=(Window&&) noexcept = default;
		virtual ~Window();

		HWND GetHandle();
		void SetTitle(std::wstring title);
		std::wstring GetTitle();
		void Show();
		void Close();
		void SetPosition(RECT const * rect);
		void GetClientRect(RECT *rect);
		void GetPosition(RECT *rect);

		virtual void Release();
		virtual bool IsReleased();
};

}
#endif