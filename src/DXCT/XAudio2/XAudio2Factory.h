//
//		ƒtƒ@ƒCƒ‹–¼:XAudioFactory.h
//

#ifndef HEADER_XAUDIO2_FACTORY_H
#define HEADER_XAUDIO2_FACTORY_H
#include <memory>
#include "../DXObject.h"
#include "XAudio2MasteringVoice.h"
#include "XAudio2SourceVoice.h"

namespace DXCT { namespace XAudio2
{
	class XAudio2Factory:public DXObject<IXAudio2>
	{
		private:
			XAudio2Factory(IXAudio2* xaudio2);


		public:
			std::shared_ptr<XAudio2MasteringVoice> CreateMasteringVoice(
				unsigned int inputCHannels = XAUDIO2_DEFAULT_CHANNELS,
				unsigned int inputSampleRate = XAUDIO2_DEFAULT_SAMPLERATE,
				unsigned int flags = 0,unsigned int deviceIndex = 0
			);
			std::shared_ptr<XAudio2SourceVoice> CreateSourceVoice(
				const WAVEFORMATEX *sourceFormat,
				UINT32 flags = 0,
				float maxFrequencyRatio = XAUDIO2_DEFAULT_FREQ_RATIO,
				IXAudio2VoiceCallback *callback = NULL,
				const XAUDIO2_VOICE_SENDS *sendList = NULL,
				const XAUDIO2_EFFECT_CHAIN *effectChain = NULL
			);
			static std::shared_ptr<XAudio2Factory> Create();
	};
}
}

#endif