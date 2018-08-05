//
//		ƒtƒ@ƒCƒ‹–¼:Clock.h
//

#ifndef HEADER_CLOCK_H
#define HEADER_CLOCK_H
#include <chrono>
#include "../GameEngine_inner.h"

namespace GameEngine { namespace Time 
{
class StopWatch
{
	private:
		using clock = std::chrono::steady_clock;
	
		clock::time_point _start;
		double _time;
		bool _isStarted;

		void AddTime();

	public:
		StopWatch();
		void Start();
		void Stop();
		void ReStart();
		void Reset();
		double GetElapsed();



};
}
}
#endif