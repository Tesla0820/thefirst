#include "SoundPlay.h"

GameEngine::Behaviour::SoundPlay::SoundPlay()
{
	_code = 0;
}

void GameEngine::Behaviour::SoundPlay::SetSound(std::shared_ptr<Sound::Sound> sound)
{
	_sound = sound;
}

void GameEngine::Behaviour::SoundPlay::Play()
{
	if (!_sound) return;
	_code=Sound::SoundManager::Play(*_sound);
}

void GameEngine::Behaviour::SoundPlay::Stop()
{
	if (!_sound) return;
	if (_sound->GetLoopCount() != (char)XAUDIO2_LOOP_INFINITE)return;
	Sound::SoundManager::Stop(_code);
}

void GameEngine::Behaviour::SoundPlay::Disabled()
{
	Stop();
}
