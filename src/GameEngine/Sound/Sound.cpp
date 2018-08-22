//
//		ファイル名:Sound.cpp
//

#include <fstream>
#include "Sound.h"
namespace GameEngine { namespace Sound
{

bool Sound::CheckChunk(std::istream & stream, unsigned long chunkFormat, unsigned long * chunkSize)
{
	unsigned long format;
	unsigned long size;
	*chunkSize = 0;
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
	return chunkFormat == format;
}

Sound::Sound(std::unique_ptr<char[]>&& data, WAVEFORMATEXTENSIBLE waveFormatExtensible, char loopCount)
{
	_data = std::move(data);
	_waveFormatExtensible = waveFormatExtensible;
	_loopCount = loopCount;
}

Sound * Sound::CreateFromWaveFile(std::string filename, char loopCount)
{
	unsigned long fileSize;
	unsigned long chunkSize;
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
	waveFile.seekg(0, std::ios::beg);
	//RIFFヘッダーチェック dataPositionにファイルフォーマットが入っている
	if (!CheckChunk(waveFile, 'FFIR', &chunkSize))
	{
		throw(std::runtime_error("RIFF形式ではありません。"));
	}
	waveFile.read(reinterpret_cast<char*>(&fileFormat), chunkSize);
	if (fileFormat != 'EVAW')
	{
		throw(std::runtime_error("Waveファイルではありません。"));
	}

	fileSize = chunkSize;

	//チャンクデータ読み込み
	//fmt(データフォーマット)読み込み
	if (!CheckChunk(waveFile, ' tmf', &chunkSize))
	{
		throw(std::runtime_error("データフォーマットがありません。"));
	}
	//チャンクデータ読み込み
	//data(波形データ)読み込み
	waveFile.read(reinterpret_cast<char*>(&waveFormatExtensible), chunkSize);
	if (!CheckChunk(waveFile,'atad',&chunkSize))
	{
		throw(std::runtime_error("波形データがありません。"));
	}
	std::unique_ptr<char[]> data(new char[chunkSize]);
	waveFile.read(data.get(), sizeof(chunkSize));
	return new Sound(std::move(data),waveFormatExtensible, loopCount);
}

}
}