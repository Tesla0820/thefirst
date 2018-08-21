//
//		ƒtƒ@ƒCƒ‹–¼:XAudio2MasteringVoice.h
//

#ifndef HEADER_XAUDIO2_MASTERING_VOICE_H
#define HEADER_XAUDIO2_MASTERING_VOICE_H

#include "../DXObject.h"
#include "XAudio2VoiceRelease.h"

namespace DXCT { namespace XAudio2
{

class XAudio2MasteringVoice:public DXObject<IXAudio2MasteringVoice,XAudio2VoiceRelease<IXAudio2MasteringVoice>>
{
	private:


	public:
	XAudio2MasteringVoice(IXAudio2MasteringVoice* xaudio2MasteringVoice);

};

}
}
#endif