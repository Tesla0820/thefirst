//
//		�t�@�C����:DInputMouseDevice.h
//

#ifndef _HEADER_DINPUT_MOUSE_DEVICE_H
#define _HEADER_DINPUT_MOUSE_DEVICE_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#define DIRECTINPUT_VERSION	0x0800	//DirectX8 �𖾎�
#include <dinput.h>					//DirectInput �֘A�̃w�b�_
#include <windows.h>
#include <WinUser.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "../DXObject.h"

//�������萔�E�}�N����`������//
#define MAX_JOY		8		// �ő�ڑ���
#define JOY_MIN_X	-32768	// �w���ŏ��l
#define JOY_MAX_X	32767	// �w���ő�l
#define JOY_MIN_Y	-32768	// �x���ŏ��l
#define JOY_MAX_Y	32767	// �x���ő�l


namespace DXCT { namespace DInput {

//�������N���X�錾������//
class Mouse : public DXObject<IDirectInput8>
{
    private:
        IDirectInputDevice8* _device;  //�f�o�C�X
        DIMOUSESTATE		 _current;	//���݂̏��
        DIMOUSESTATE		 _preview;	//�O��̏��
        DIMOUSESTATE		 _trigger;	//�g���K���
        DIMOUSESTATE		 _release;	//�����[�X���


    public:
        HRESULT Initialize(HWND, IDirectInput8*);
        void End(void);
        void Update(void);

        DIMOUSESTATE* GetState(void);
        bool GetHold(DWORD);
        bool GetTrigger(DWORD);
        bool GetRelease(DWORD);
};

}}
#endif