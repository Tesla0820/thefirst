//
//		ƒtƒ@ƒCƒ‹–¼:FPSCounter.cpp
//
#include "FPSCounter.h"

namespace GameEngine {
namespace Time
{

FPSCounter::FPSCounter()
{
	_frameRate = 60;
	_deltaTime = 0.0;
	_oldFrame = 0;
	_isFrameChanged = false;
}

void FPSCounter::SetFrameRate(int frameRate)
{
	_frameRate = frameRate;
}

void FPSCounter::Start()
{
	_clock.Start();
}

void FPSCounter::Stop()
{
	_clock.Stop();
}

void FPSCounter::Restart()
{
	_clock.ReStart();
}

void FPSCounter::Reset()
{
	_clock.Reset();
}

void FPSCounter::Update()
{
	double elapsed = _clock.GetElapsed();
	int currentFrame = elapsed*_frameRate;
	_isFrameChanged = false;
	if (_oldFrame != currentFrame)
	{
		_oldFrame = currentFrame;
		_clock.ReStart();
		_deltaTime = elapsed;
		_isFrameChanged = true;
	}
}

bool FPSCounter::IsFrameChanged()
{
	return _isFrameChanged;
}

double FPSCounter::GetDeltaTime()
{
	return _deltaTime;
}

double FPSCounter::GetCurrentFPS()
{
	if (_deltaTime <= 0.0)return 0.0;
	return 1, 0 / _deltaTime;
}

}
}