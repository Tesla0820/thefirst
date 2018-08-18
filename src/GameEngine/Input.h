//
//		�t�@�C����:InputManager.h
//

#ifndef _HEADER_INPUT_MANAGER_H
#define _HEADER_INPUT_MANAGER_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "GameEngine_inner.h"
#include "InputManager/Joypad.h"
#include "InputManager/Keyboard.h"
#include "InputManager/Mouse.h"

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

namespace GameEngine 
{

//�������N���X�錾������//
class Input
{
    private:
        static std::shared_ptr<DXCT::DInput::DInputFactory>     _factory;	//�Ǘ��C���^�[�t�F�[�X
        static GameEngine::InputManager::Joypad   _joypad;		//�Q�[���p�b�h
        static GameEngine::InputManager::Keyboard _keyboard;	//�L�[�{�[�h
        static GameEngine::InputManager::Mouse	  _mouse;		//�}�E�X

    public:
        Input();

        static void Release();

        static HRESULT Create(HWND);
        static void End(void);
        static void Update(void);

        static bool GetJoyButton(DWORD, DWORD, PUSH_TYPE);
        static LONG GetJoyStick(DWORD, AXIS_TYPE);
        static bool GetKey(DWORD, PUSH_TYPE);
        static bool GetMouseButton(DWORD, PUSH_TYPE);
        static DIMOUSESTATE* GetMouseMove(void);
};

}
#endif