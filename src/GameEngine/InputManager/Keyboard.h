//
//		�t�@�C����:Keyboard.h
//

#ifndef HEADER_KEYBOARD_H
#define HEADER_KEYBOARD_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "../GameEngine_inner.h"

namespace GameEngine { namespace InputManager
{

//�������N���X�錾������//
class Keyboard
{
    private:
        std::shared_ptr<DXCT::DInput::DInputDevice> _device;       //�f�o�C�X
        BYTE			                            _current[256];	//���݂̏��
        BYTE			                            _preview[256];	//�O��̏��
        BYTE			                            _trigger[256];	//�g���K���
        BYTE			                            _release[256];	//�����[�X���

    public:
        Keyboard();

        HRESULT Create(HWND, std::shared_ptr<DXCT::DInput::DInputFactory>);
        void End(void);
        void Update(void);

        bool GetHold(DWORD);
        bool GetTrigger(DWORD);
        bool GetRelease(DWORD);
};

}}
#endif