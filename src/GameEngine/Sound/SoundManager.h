//
//		ƒtƒ@ƒCƒ‹–¼:SoundManager.h
//

#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "Sound.h"
#include "../GameEngine_inner.h"

namespace GameEngine { namespace Sound
{

class SoundManager
{
	private:
		static std::shared_ptr<DXCT::XAudio2::XAudio2Factory> _factory;
		static std::shared_ptr<DXCT::XAudio2::XAudio2MasteringVoice> _masteringVoice;
		static std::list<std::shared_ptr<DXCT::XAudio2::XAudio2SourceVoice>> _sourceVoiceList;

	public:
		static int Play(Sound& sound);
		static void Stop(int code);
		static void StopAll();
		static void Create();
		static void Release();
};

}
}
#endif