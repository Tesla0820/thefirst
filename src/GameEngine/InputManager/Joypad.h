//
//		�t�@�C����:DInputjoypadDevice.h
//

#ifndef _HEADER_DINPUT_JOYPAD_DEVICE_H
#define _HEADER_DINPUT_JOYPAD_DEVICE_H


#include "../GameEngine_inner.h"

#define MAX_JOY		8		// �ő�ڑ���

namespace GameEngine { namespace InputManager {

class Joypad
{
    private:
        std::shared_ptr<DXCT::DInput::DInputDevice> _device[MAX_JOY];       //�f�o�C�X
        DWORD				                        _deviceValue;		//�ڑ���
        DIJOYSTATE			                        _current[MAX_JOY];	//���݂̏��
        DIJOYSTATE			                        _preview[MAX_JOY];	//�O��̏��
        DIJOYSTATE			                        _trigger[MAX_JOY];	//�g���K���
        DIJOYSTATE			                        _release[MAX_JOY];	//�����[�X���

        int EnumCallBack(std::shared_ptr<DXCT::DInput::DInputFactory>, DIDEVICEINSTANCE const*, void*);
        void DeleteDevice(void);

    public:
        HRESULT Create(HWND, std::shared_ptr<DXCT::DInput::DInputFactory>);
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
};

    
}}
#endif