//
//		ファイル名:Sound.cpp
//

#include <fstream>
#include "Sound.h"
namespace GameEngine { namespace Sound
{

Sound::Sound(std::unique_ptr<unsigned char[]>&& data,unsigned long bufferSize, WAVEFORMATEXTENSIBLE waveFormatExtensible, char loopCount)
{
	_data = std::move(data);
	_bufferSize = bufferSize;
	_waveFormatExtensible = waveFormatExtensible;
	_loopCount = loopCount;
}

unsigned long Sound::GetBufferSize()
{
	return _bufferSize;
}

unsigned char * Sound::GetData()
{
	return _data.get();
}

void Sound::GetFomat(WAVEFORMATEXTENSIBLE * waveFormatExtensible)
{
	*waveFormatExtensible = _waveFormatExtensible;
}

int Sound::GetLoopCount()
{
	return _loopCount;
}

bool Sound::HasChunk(std::istream & stream, unsigned long chunkFormat, unsigned long * chunkSize,unsigned long *chunkPosition)
{
	bool isEnd = false;
	bool result = false;
	unsigned long currentPos;
	unsigned long format;
	unsigned long size;
	*chunkSize = 0;
	*chunkPosition = 0;
	currentPos = 0;
	stream.seekg(0, std::ios::beg);
	do
	{
		stream.read(reinterpret_cast<char*>(&format), sizeof(format));
		stream.read(reinterpret_cast<char*>(&size), sizeof(size));
		if (format == 'FFIR')
		{	//先頭はチャンクサイズではなくファイルサイズなので
			*chunkSize = 4;
		}
		else
		{
			*chunkSize = size;
		}

		if (chunkFormat == format)
		{
			//マッチ
			isEnd = true;
			result = true;
		}
		else
		{
			char temp;
			stream.seekg(*chunkSize, std::ios::cur);
			stream.read(&temp, sizeof(temp));
			if (stream.eof())
			{
				isEnd = true;
				result = false;
			}
			else
			{
				stream.seekg(-1, std::ios::cur);
			}
		}

	} while (!isEnd);
	*chunkPosition = stream.tellg();
	return result;
}


Sound * Sound::CreateFromWaveFile(std::string filename, char loopCount)
{
	unsigned long fileSize;
	unsigned long chunkSize;
	unsigned long chunkPosition;
	unsigned long fileFormat;
	WAVEFORMATEXTENSIBLE waveFormatExtensible;
	std::ifstream waveFile;
	//フォーマットタイプ特定
	waveFile.open(filename, std::ios::in | std::ios::binary);
	if (waveFile.fail())
	{
		//ファイルが存在しない
		throw(std::runtime_error("ファイルが見つかりません。"));
	}
	//RIFFヘッダーチェック dataPositionにファイルフォーマットが入っている
	if (!HasChunk(waveFile, 'FFIR', &chunkSize,&chunkPosition))
	{
		throw(std::runtime_error("RIFF形式ではありません。"));
	}
	waveFile.seekg(chunkPosition);
	waveFile.read(reinterpret_cast<char*>(&fileFormat), chunkSize);
	if (fileFormat != 'EVAW')
	{
		throw(std::runtime_error("Waveファイルではありません。"));
	}

	fileSize = chunkSize;

	//チャンクデータ読み込み
	//fmt(データフォーマット)読み込み
	if (!HasChunk(waveFile, ' tmf', &chunkSize,&chunkPosition))
	{
		throw(std::runtime_error("データフォーマットがありません。"));
	}
	//チャンクデータ読み込み
	waveFile.seekg(chunkPosition);
	waveFile.read(reinterpret_cast<char*>(&waveFormatExtensible), chunkSize);
	//data(波形データ)読み込み
	if (!HasChunk(waveFile,'atad',&chunkSize,&chunkPosition))
	{
		throw(std::runtime_error("波形データがありません。"));
	}
	waveFile.seekg(chunkPosition);
	unsigned char * buffer = new unsigned char[chunkSize+1];
	waveFile.read(reinterpret_cast<char*>(buffer), chunkSize);
	std::unique_ptr<unsigned char[]> data(buffer);
	return new Sound(std::move(data),waveFile.gcount(),waveFormatExtensible, loopCount);
}

}
}