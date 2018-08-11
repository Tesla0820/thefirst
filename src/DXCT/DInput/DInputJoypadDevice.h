//
//		�t�@�C����:DInputjoypadDevice.h
//

#ifndef _HEADER_DINPUT_JOYPAD_DEVICE_H
#define _HEADER_DINPUT_JOYPAD_DEVICE_H

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
class Joypad : public DXObject<IDirectInput8>
{
    private:
        IDirectInputDevice8* _device[MAX_JOY];  //�f�o�C�X
        DWORD				 _deviceValue;		//�ڑ���
        DIJOYSTATE			 _current[MAX_JOY];	//���݂̏��
        DIJOYSTATE			 _preview[MAX_JOY];	//�O��̏��
        DIJOYSTATE			 _trigger[MAX_JOY];	//�g���K���
        DIJOYSTATE			 _release[MAX_JOY];	//�����[�X���

    public:
        HRESULT Initialize(HWND, IDirectInput8*);
        void End(void);
        void Update(void);

        DWORD GetCount(void);
        DIJOYSTATE* GetState(DWORD);
        LONG GetAxisX(DWORD);
        LONG GetAxisY(DWORD);
        LONG GetAxisZ(DWORD);
        bool GetHold(DWORD, DWORD);
        bool GetTrigger(DWORD, DWORD);
        bool GetRelease(DWORD, DWORD);
        void DeleteDevice(void);

        BOOL CALLBACK EnumJoyCallback(const DIDEVICEINSTANCE*, VOID*);
};

//�������v���g�^�C�v�錾������//
    
}}
#endif