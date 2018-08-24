//
//		�t�@�C����:XAudio2VoiceRelease.h
//

#ifndef HEADER_XAUDIO2_VOICE_RELEASE_H
#define HEADER_XAUDIO2_VOICE_RELEASE_H

#include "../dxct_inner.h"

namespace DXCT { namespace XAudio2
{

template<class T>
class XAudio2VoiceRelease
{
	static_assert(std::is_convertible <T, IXAudio2Voice>::value, "IXAudio2Voice���p�����Ȃ��N���X��XAudio2VoiceRelease�ł͉���ł��܂���B");
	public:
		void operator()(T* pointer);

};

template<class T>
inline void XAudio2VoiceRelease<T>::operator()(T * pointer)
{
	pointer->DestroyVoice();
}

}
}
#endif