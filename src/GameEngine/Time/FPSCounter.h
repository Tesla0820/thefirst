//
//		ƒtƒ@ƒCƒ‹–¼:FPSCounter.h
//

#ifndef HEADER_FPS_COUNTER_H
#define HEADER_FPS_COUNTER_H

#include "StopWatch.h"

namespace GameEngine { namespace Time 
{
	class FPSCounter
	{
		private:
			StopWatch	_clock;
			int			_frameRate;
			int			_oldFrame;
			bool		_isFrameChanged;
			double		_deltaTime;
		public:
			FPSCounter();
			void SetFrameRate(int frameRate);
			void Start();
			void Stop();
			void Restart();
			void Reset();
			void Update();
			bool IsFrameChanged();
			double GetDeltaTime();
			double GetCurrentFPS();

	};
}
}
#endif