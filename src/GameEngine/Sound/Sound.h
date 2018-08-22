//
//		ƒtƒ@ƒCƒ‹–¼:Sound.h
//

#ifndef HEADER_SOUND_H
#define HEADER_SOUND_H

#include "../GameEngine_inner.h"

namespace GameEngine { namespace Sound
{
	class Sound
	{
		private:
			static bool CheckChunk(std::istream & stream, unsigned long chunkFormat, unsigned long * chunkSize);
			
			std::unique_ptr<char[]> _data;
			WAVEFORMATEXTENSIBLE _waveFormatExtensible;
			char _loopCount;

		public:
			Sound(std::unique_ptr<char[]>&& data,WAVEFORMATEXTENSIBLE waveFormatExtensible, char loopCount);
			
			static Sound* CreateFromWaveFile(std::string filename, char loopCount);

	};
}
}
#endif