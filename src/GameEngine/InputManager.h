//
//		�t�@�C����:InputManager.h
//

#ifndef _HEADER_INPUT_MANAGER_H
#define _HEADER_INPUT_MANAGER_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include <dinput.h>					//DirectInput �֘A�̃w�b�_
#include <windows.h>
#include <WinUser.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "../DXCT/DInput/DInputJoypadDevice.h"
#include "../DXCT/DInput/DInputKeyboardDevice.h"
#include "../DXCT/DInput/DInputMouseDevice.h"

//�������񋓌^��`������//
typedef enum
{
    HOLD,
    RELEASE,
    TRIGGER,
    PUSH_TYPE_MAX
}PUSH_TYPE;

typedef enum
{
    X,
    Y,
    Z,
    AXIS_TYPE_MAX
}AXIS_TYPE;

namespace GameEngine {
//�������N���X�錾������//
class InputManager
{
    private:
        IDirectInput8*         _manager;	//�Ǘ��C���^�[�t�F�[�X
        DXCT::DInput::Joypad   _joypad;		//�Q�[���p�b�h
        DXCT::DInput::Keyboard _keyboard;	//�L�[�{�[�h
        DXCT::DInput::Mouse	   _mouse;		//�}�E�X

    public:
        HRESULT Initialize(HWND);
        void End(void);
        void Update(void);

        BOOL CallJoyInfo(const DIDEVICEINSTANCE* lpddi);

        bool GetJoyButton(DWORD, DWORD, PUSH_TYPE);
        LONG GetJoyStick(DWORD, AXIS_TYPE);
        bool GetKey(DWORD, PUSH_TYPE);
        bool GetMouseButton(DWORD, PUSH_TYPE);
        DIMOUSESTATE* GetMouseMove(void);
};

//�������v���g�^�C�v�錾������//
static BOOL CALLBACK EnumJoyCallback(const DIDEVICEINSTANCE*, VOID*);

}
#endif