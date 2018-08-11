//
//		�t�@�C����:DInputKeyboardDevice.h
//

#ifndef _HEADER_DINPUT_KEYBOARD_DEVICE_H
#define _HEADER_DINPUT_KEYBOARD_DEVICE_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#define DIRECTINPUT_VERSION	0x0800	//DirectX8 �𖾎�
#include <dinput.h>					//DirectInput �֘A�̃w�b�_
#include <windows.h>
#include <WinUser.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "../DXObject.h"


namespace DXCT { namespace DInput {

//�������N���X�錾������//
class Keyboard : public DXObject<IDirectInput8>
{
    private:
        IDirectInputDevice8* _device;       //�f�o�C�X
        BYTE			     _current[256];	//���݂̏��
        BYTE			     _preview[256];	//�O��̏��
        BYTE			     _trigger[256];	//�g���K���
        BYTE			     _release[256];	//�����[�X���

    public:
        HRESULT Initialize(HWND, IDirectInput8*);
        void End(void);
        void Update(void);

        bool GetHold(DWORD);
        bool GetTrigger(DWORD);
        bool GetRelease(DWORD);
};

}}
#endif