//
//		ƒtƒ@ƒCƒ‹–¼:MainWindow.h
//

#ifndef HEADER_MAIN_WINDOW_H
#define HEADER_MAIN_WINDOW_H

#include "GameEngine_inner.h"

namespace GameEngine
{
	class MainWindow : public DXCT::Window
	{
		private:
			MainWindow() = delete;
		public:
			MainWindow(int width,int height);
			virtual ~MainWindow();
			virtual LRESULT WindowProc(UINT msg, WPARAM wp, LPARAM lp, bool *isHooked) override;
			
	};
}
#endif