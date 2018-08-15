//
//		�t�@�C����:DInputjoypadDevice.h
//

#ifndef _HEADER_DINPUT_JOYPAD_DEVICE_H
#define _HEADER_DINPUT_JOYPAD_DEVICE_H

#include "../GameEngine_inner.h"

//�������萔�E�}�N����`������//
#define MAX_JOY		8		// �ő�ڑ���
#define JOY_MIN_X	-32768	// �w���ŏ��l
#define JOY_MAX_X	32767	// �w���ő�l
#define JOY_MIN_Y	-32768	// �x���ŏ��l
#define JOY_MAX_Y	32767	// �x���ő�l


namespace DXCT { namespace DInput 
{

class Joypad
{
    private:
        IDirectInputDevice8* _device[MAX_JOY];  //�f�o�C�X
        DWORD				 _deviceValue;		//�ڑ���
        DIJOYSTATE			 _current[MAX_JOY];	//���݂̏��
        DIJOYSTATE			 _preview[MAX_JOY];	//�O��̏��
        DIJOYSTATE			 _trigger[MAX_JOY];	//�g���K���
        DIJOYSTATE			 _release[MAX_JOY];	//�����[�X���

    public:
        HRESULT Initialize(HWND, std::shared_ptr<);
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

};

    
}
}
#endif