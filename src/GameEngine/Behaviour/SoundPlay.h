//
//		ƒtƒ@ƒCƒ‹–¼:SoundPlay.h
//

#ifndef HEADER_SOUND_PLAY_H
#define HEADER_SOUND_PLAY_H

#include "../Sound/Sound.h"
#include "../Sound/SoundManager.h"
#include "Behaviour.h"


namespace GameEngine { namespace Behaviour
{

class SoundPlay:public Behaviour
{
	private:
		std::shared_ptr<Sound::Sound> _sound;
		int _code;
	public:
	SoundPlay();
	void SetSound(std::shared_ptr<Sound::Sound> sound);
	void Play();
	void Stop();
	virtual void Disabled() override;


};

}
}
#endif