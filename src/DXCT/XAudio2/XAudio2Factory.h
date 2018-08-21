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
			std::shared_ptr<XAudio2MasteringVoice> CreateMasteringVoice();

			static std::shared_ptr<XAudio2Factory> Create();
	};
}
}

#endif