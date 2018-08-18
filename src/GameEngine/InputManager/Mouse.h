//
//		�t�@�C����:Mouse.h
//

#ifndef HEADER_MOUSE_H
#define HEADER_MOUSE_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "../GameEngine_inner.h"

namespace GameEngine {namespace InputManager
{

//�������N���X�錾������//
class Mouse
{
    private:
        std::shared_ptr<DXCT::DInput::DInputDevice> _device;    //�f�o�C�X
        DIMOUSESTATE		                        _current;	//���݂̏��
        DIMOUSESTATE		                        _preview;	//�O��̏��
        DIMOUSESTATE		                        _trigger;	//�g���K���
        DIMOUSESTATE		                        _release;	//�����[�X���

    public:
        Mouse();

        HRESULT Create(HWND, std::shared_ptr<DXCT::DInput::DInputFactory>);
        void End(void);
        void Update(void);

        DIMOUSESTATE* GetState(void);
        bool GetHold(DWORD);
        bool GetTrigger(DWORD);
        bool GetRelease(DWORD);
};

}}
#endif