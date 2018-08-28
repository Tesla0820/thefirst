//
//		ƒtƒ@ƒCƒ‹–¼:XAudio2SourceVoice.h
//

#ifndef HEADER_XAUDIO2_SOURCE_VOICE_H
#define HEADER_XAUDIO2_SOURCE_VOICE_H

#include "../DXObject.h"
#include "XAudio2VoiceRelease.h"

namespace DXCT { namespace XAudio2
{

class XAudio2SourceVoice : public DXObject<IXAudio2SourceVoice, XAudio2VoiceRelease<IXAudio2SourceVoice>>
{
	private:


	public:
		XAudio2SourceVoice(IXAudio2SourceVoice* xaudio2SourceVoice);
		HRESULT FlushSourceBuffers();
		void GetState(XAUDIO2_VOICE_STATE *voiceState);
		HRESULT SubmitSourceBuffer(const XAUDIO2_BUFFER *buffer,const XAUDIO2_BUFFER_WMA *bufferWMA = NULL);
		HRESULT Start(unsigned int flags, unsigned int operationSet = XAUDIO2_COMMIT_NOW);
		HRESULT Stop(unsigned int flags, unsigned int operationSet = XAUDIO2_COMMIT_NOW);
};

}
}
#endif