//
//		ƒtƒ@ƒCƒ‹–¼:XAudio2MasteringVoice.cpp
//

#include "XAudio2MasteringVoice.h"
namespace DXCT { namespace XAudio2
{
XAudio2MasteringVoice::XAudio2MasteringVoice(IXAudio2MasteringVoice * xaudio2MasteringVoice)
	:DXObject(xaudio2MasteringVoice)
{

}

HRESULT XAudio2MasteringVoice::SetVolume(float volume)
{
	return _object->SetVolume(volume);
}

}
}
