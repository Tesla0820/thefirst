#include "SoundManager.h"

namespace GameEngine { namespace Sound
{

std::shared_ptr<DXCT::XAudio2::XAudio2Factory> SoundManager::_factory;
std::shared_ptr<DXCT::XAudio2::XAudio2MasteringVoice> SoundManager::_masteringVoice;
std::list<std::shared_ptr<DXCT::XAudio2::XAudio2SourceVoice>> SoundManager::_sourceVoiceList;

unsigned int SoundManager::Play(Sound & sound)
{
	XAUDIO2_BUFFER buffer;

	memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));

	buffer.AudioBytes = sound.GetBufferSize();
	buffer.pAudioData = sound.GetData();
	buffer.Flags = XAUDIO2_END_OF_STREAM;
	buffer.LoopCount = sound.GetLoopCount();

	WAVEFORMATEXTENSIBLE format;
	sound.GetFomat(&format);

	std::shared_ptr<DXCT::XAudio2::XAudio2SourceVoice> voice = _factory->CreateSourceVoice(&format.Format);

	voice->SubmitSourceBuffer(&buffer);
	voice->Start(0);

	_sourceVoiceList.push_back(std::move(voice));
	return (unsigned int)_sourceVoiceList.size() - 1u;
}

void SoundManager::Stop(int code)
{
	if (code < -1 || code >= _sourceVoiceList.size()) return;
	auto voiceIterator = _sourceVoiceList.begin();
	std::advance(voiceIterator, code);
	XAUDIO2_VOICE_STATE state;
	(*voiceIterator)->GetState(&state);
	if (state.BuffersQueued)
	{
		(*voiceIterator)->Stop(0);
	}
	_sourceVoiceList.erase(voiceIterator);
}

void SoundManager::StopAll()
{
	while (!_sourceVoiceList.empty())
	{
		auto voice = _sourceVoiceList.back();
		XAUDIO2_VOICE_STATE state;
		voice->GetState(&state);
		if (state.BuffersQueued)
		{
			voice->Stop(0);
		}
		_sourceVoiceList.pop_back();
	}
}

void SoundManager::Create()
{
	_factory = DXCT::XAudio2::XAudio2Factory::Create();
	_masteringVoice = _factory->CreateMasteringVoice();
	_masteringVoice->SetVolume(1.0f);
}

void SoundManager::Release()
{
	StopAll();
	_masteringVoice.reset();
	_factory.reset();
}

}
}
