//
//		ファイル名		：StopWatch.cpp
//

//---インクルード部---
#include "StopWatch.h"

namespace GameEngine { namespace Time
{

StopWatch::StopWatch()
{
	_time = 0.0;
	_start = clock::now();
	_isStarted = false;
}

void StopWatch::Start()
{
	if (_isStarted) return;

	_time = 0.0;
	_start = clock::now();
	_isStarted = true;
}

void StopWatch::Stop()
{
	if (!_isStarted) return;

	AddTime();
	_isStarted = false;

}

void StopWatch::ReStart()
{
	if (_isStarted) return;

	_start = clock::now();
	_isStarted = true;
}

void StopWatch::Reset()
{
	_time = 0.0;
	_isStarted = false;
}

double StopWatch::GetElapsed()
{
	if (_isStarted)
	{
		AddTime();
	}
	return _time;

}
void StopWatch::AddTime()
{
	auto current = std::chrono::steady_clock::now();
	_time += std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1, 1>>>(current - _start).count();
	_start = std::move(current);
}


}
}