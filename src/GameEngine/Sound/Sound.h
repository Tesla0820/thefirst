//
//		�t�@�C����:Sound.h
//

#ifndef HEADER_SOUND_H
#define HEADER_SOUND_H

#include "../GameEngine_inner.h"

namespace GameEngine { namespace Sound
{
	class Sound
	{
		private:
			static bool HasChunk(std::istream & stream, unsigned long chunkFormat, std::size_t* chunkSize, std::streampos* chunkPosition);
			
			std::unique_ptr<unsigned char[]> _data;
			unsigned long _bufferSize;
			WAVEFORMATEXTENSIBLE _waveFormatExtensible;
			unsigned int _loopCount;

		public:
			Sound(std::unique_ptr<unsigned char[]>&& data,unsigned long bufferSize,WAVEFORMATEXTENSIBLE waveFormatExtensible, unsigned int loopCount = 0u);
			unsigned long GetBufferSize();
			unsigned char* GetData();
			void GetFomat(WAVEFORMATEXTENSIBLE *waveFormatExtensible);
			unsigned int GetLoopCount();
			void SetLoopCount(unsigned int loopCount);
			static std::shared_ptr<Sound> CreateFromWaveFile(std::string filename, unsigned int loopCount);

	};
}
}
#endif