//
//		ƒtƒ@ƒCƒ‹–¼:XAudio2SourceVoice.h
//

#ifndef HEADER_XAUDIO2_SOURCE_VOICE_H
#define HEADER_XAUDIO2_SOURCE_VOICE_H

#include "../DXObject.h"

namespace DXCT { namespace XAudio2
{
	class XAudio2SourceVoice : public DXObject<IXAudio2SourceVoice>
	{
		private:


		public:
			XAudio2SourceVoice(IXAudio2SourceVoice* xaudio2SourceVoice);

	};
}
}
#endif