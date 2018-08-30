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
		{	//�擪�̓`�����N�T�C�Y�ł͂Ȃ��t�@�C���T�C�Y�Ȃ̂�
			*chunkSize = 4;
		}
		else
		{
			*chunkSize = size;
		}

		if (chunkFormat == format)
		{
			//�}�b�`
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
	//�t�H�[�}�b�g�^�C�v����
	waveFile.open(filename, std::ios::in | std::ios::binary);
	if (waveFile.fail())
	{
		//�t�@�C�������݂��Ȃ�
		throw(std::runtime_error("�t�@�C����������܂���B"));
	}
	//RIFF�w�b�_�[�`�F�b�N dataPosition�Ƀt�@�C���t�H�[�}�b�g�������Ă���
	if (!HasChunk(waveFile, 'FFIR', &chunkSize,&chunkPosition))
	{
		throw(std::runtime_error("RIFF�`���ł͂���܂���B"));
	}
	waveFile.seekg(chunkPosition);
	waveFile.read(reinterpret_cast<char*>(&fileFormat), chunkSize);
	if (fileFormat != 'EVAW')
	{
		throw(std::runtime_error("Wave�t�@�C���ł͂���܂���B"));
	}

	fileSize = chunkSize;

	//�`�����N�f�[�^�ǂݍ���
	//fmt(�f�[�^�t�H�[�}�b�g)�ǂݍ���
	if (!HasChunk(waveFile, ' tmf', &chunkSize,&chunkPosition))
	{
		throw(std::runtime_error("�f�[�^�t�H�[�}�b�g������܂���B"));
	}
	//�`�����N�f�[�^�ǂݍ���
	waveFile.seekg(chunkPosition);
	waveFile.read(reinterpret_cast<char*>(&waveFormatExtensible), chunkSize);
	//data(�g�`�f�[�^)�ǂݍ���
	if (!HasChunk(waveFile,'atad',&chunkSize,&chunkPosition))
	{
		throw(std::runtime_error("�g�`�f�[�^������܂���B"));
	}
	waveFile.seekg(chunkPosition);
	unsigned char * buffer = new unsigned char[chunkSize+1];
	waveFile.read(reinterpret_cast<char*>(buffer), chunkSize);
	std::unique_ptr<unsigned char[]> data(buffer);
	return new Sound(std::move(data),waveFile.gcount(),waveFormatExtensible, loopCount);
}

}
}