//
//		�t�@�C����:Sound.cpp
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

bool Sound::CheckChunk(std::istream & stream, unsigned long chunkFormat, unsigned long * chunkSize)
{
	unsigned long format;
	unsigned long size;
	*chunkSize = 0;
	stream.read(reinterpret_cast<char*>(&format), sizeof(format));
	stream.read(reinterpret_cast<char*>(&size), sizeof(size));
	if (format == 'FFIR')
	{	//�擪�̓`�����N�T�C�Y�ł͂Ȃ��t�@�C���T�C�Y�Ȃ̂�
		*chunkSize = 4;
	}
	else
	{
		*chunkSize = size;
	}
	return chunkFormat == format;
}


Sound * Sound::CreateFromWaveFile(std::string filename, char loopCount)
{
	unsigned long fileSize;
	unsigned long chunkSize;
	unsigned long fileFormat;
	WAVEFORMATEXTENSIBLE waveFormatExtensible;
	std::ifstream waveFile;
	//�t�H�[�}�b�g�^�C�v����
	waveFile.open(filename, std::ios::in | std::ios::binary);
	if (waveFile.fail())
	{
		//�t�@�C�������݂��Ȃ�
		throw(std::runtime_error("�t�@�C����������܂���B"));
	}
	waveFile.seekg(0, std::ios::beg);
	//RIFF�w�b�_�[�`�F�b�N dataPosition�Ƀt�@�C���t�H�[�}�b�g�������Ă���
	if (!CheckChunk(waveFile, 'FFIR', &chunkSize))
	{
		throw(std::runtime_error("RIFF�`���ł͂���܂���B"));
	}
	waveFile.read(reinterpret_cast<char*>(&fileFormat), chunkSize);
	if (fileFormat != 'EVAW')
	{
		throw(std::runtime_error("Wave�t�@�C���ł͂���܂���B"));
	}

	fileSize = chunkSize;

	//�`�����N�f�[�^�ǂݍ���
	//fmt(�f�[�^�t�H�[�}�b�g)�ǂݍ���
	if (!CheckChunk(waveFile, ' tmf', &chunkSize))
	{
		throw(std::runtime_error("�f�[�^�t�H�[�}�b�g������܂���B"));
	}
	//�`�����N�f�[�^�ǂݍ���
	waveFile.read(reinterpret_cast<char*>(&waveFormatExtensible), chunkSize);
	//data(�g�`�f�[�^)�ǂݍ���
	if (!CheckChunk(waveFile,'atad',&chunkSize))
	{
		throw(std::runtime_error("�g�`�f�[�^������܂���B"));
	}
	unsigned char * buffer = new unsigned char[chunkSize+1];
	waveFile.read(reinterpret_cast<char*>(buffer), chunkSize);
	std::unique_ptr<unsigned char[]> data(buffer);
	return new Sound(std::move(data),waveFile.gcount(),waveFormatExtensible, loopCount);
}

}
}