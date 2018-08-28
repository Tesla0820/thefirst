//
//		ƒtƒ@ƒCƒ‹–¼:XAudio2SourceVoice.cpp
//

#include "XAudio2SourceVoice.h"
namespace DXCT { namespace XAudio2
{

XAudio2SourceVoice::XAudio2SourceVoice(IXAudio2SourceVoice * xaudio2SourceVoice)
	:DXObject(xaudio2SourceVoice)
{
}

HRESULT XAudio2SourceVoice::FlushSourceBuffers()
{
	return _object->FlushSourceBuffers();
}

void XAudio2SourceVoice::GetState(XAUDIO2_VOICE_STATE * voiceState)
{
	_object->GetState(voiceState);
}

HRESULT XAudio2SourceVoice::SubmitSourceBuffer(const XAUDIO2_BUFFER * buffer, const XAUDIO2_BUFFER_WMA * bufferWMA)
{
	return _object->SubmitSourceBuffer(buffer, bufferWMA);
}

HRESULT XAudio2SourceVoice::Start(unsigned int flags, unsigned int operationSet)
{
	return _object->Start(flags, operationSet);
}

HRESULT XAudio2SourceVoice::Stop(unsigned int flags, unsigned int operationSet)
{
	return _object->Stop(flags, operationSet);
}

}
}
