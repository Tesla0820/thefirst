#include "XAudio2Factory.h"


namespace DXCT { namespace XAudio2
{

XAudio2Factory::XAudio2Factory(IXAudio2 * xaudio2)
	:DXObject(xaudio2)
{
}

std::shared_ptr<XAudio2MasteringVoice> XAudio2Factory::CreateMasteringVoice(unsigned int inputChannels, unsigned int inputSampleRate, unsigned int flags, unsigned int deviceIndex)
{
	HRESULT hr;
	IXAudio2MasteringVoice* xaudio2MasteringVoice;
	hr = _object->CreateMasteringVoice(&xaudio2MasteringVoice,inputChannels,inputSampleRate,flags,deviceIndex);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<XAudio2MasteringVoice>(new XAudio2MasteringVoice(xaudio2MasteringVoice));
	}
	return std::shared_ptr<XAudio2MasteringVoice>();
}

std::shared_ptr<XAudio2SourceVoice> XAudio2Factory::CreateSourceVoice(const WAVEFORMATEX * sourceFormat, UINT32 flags, float maxFrequencyRatio, IXAudio2VoiceCallback * callback, const XAUDIO2_VOICE_SENDS * sendList, const XAUDIO2_EFFECT_CHAIN * effectChain)
{
	HRESULT hr;
	IXAudio2SourceVoice *xaudio2SourceVoice;
	hr = _object->CreateSourceVoice(&xaudio2SourceVoice, sourceFormat, flags, maxFrequencyRatio, callback, sendList, effectChain);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<XAudio2SourceVoice>(new XAudio2SourceVoice(xaudio2SourceVoice));
	}
	return std::shared_ptr<XAudio2SourceVoice>();
}

std::shared_ptr<XAudio2Factory> DXCT::XAudio2::XAudio2Factory::Create()
{
	HRESULT hr;
	IXAudio2* xaudio2;
	hr = XAudio2Create(&xaudio2);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<XAudio2Factory>(new XAudio2Factory(xaudio2));
	}
	return std::shared_ptr<XAudio2Factory>();
}

}
}