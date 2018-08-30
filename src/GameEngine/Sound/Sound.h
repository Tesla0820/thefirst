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
			static bool HasChunk(std::istream & stream, unsigned long chunkFormat, unsigned long * chunkSize, unsigned long *chunkPosition);
			
			std::unique_ptr<unsigned char[]> _data;
			unsigned long _bufferSize;
			WAVEFORMATEXTENSIBLE _waveFormatExtensible;
			char _loopCount;

		public:
			Sound(std::unique_ptr<unsigned char[]>&& data,unsigned long bufferSize,WAVEFORMATEXTENSIBLE waveFormatExtensible, char loopCount);
			unsigned long GetBufferSize();
			unsigned char* GetData();
			void GetFomat(WAVEFORMATEXTENSIBLE *waveFormatExtensible);
			int GetLoopCount();
			static Sound* CreateFromWaveFile(std::string filename, char loopCount);

	};
}
}
#endif