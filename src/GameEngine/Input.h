//
//		�t�@�C����:InputManager.h
//

#ifndef _HEADER_INPUT_MANAGER_H
#define _HEADER_INPUT_MANAGER_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "GameEngine_inner.h"
#include "InputManager/Keyboard.h"

//�������񋓌^��`������//
typedef enum
{
    HOLD,
    RELEASE,
    TRIGGER,
    PUSH_TYPE_MAX
}PUSH_TYPE;

namespace GameEngine 
{

//�������N���X�錾������//
class Input
{
    private:
        static std::shared_ptr<DXCT::DInput::DInputFactory>     _factory;	//�Ǘ��C���^�[�t�F�[�X
        static GameEngine::InputManager::Keyboard _keyboard;	//�L�[�{�[�h

    public:
        Input();

        static void Release();

        static HRESULT Create(HWND);
        static void End(void);
        static void Update(void);

        static bool GetKey(DWORD, PUSH_TYPE);
};

}
#endif