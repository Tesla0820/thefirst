//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Input.h"

namespace GameEngine {

//------//
std::shared_ptr<DXCT::DInput::DInputFactory> Input::_factory;	//�Ǘ��C���^�[�t�F�[�X
GameEngine::InputManager::Joypad             Input::_joypad;	//�Q�[���p�b�h
GameEngine::InputManager::Keyboard           Input::_keyboard;	//�L�[�{�[�h
GameEngine::InputManager::Mouse	             Input::_mouse;		//�}�E�X


Input::Input()
{
}

void Input::Release()
{
}

//�������֐���`������//
/////////////////////////////////////////////
//�֐����FCreate
//
//�@�\�F�f�o�C�X�̏�����
//
//�����F(HWND)�n���h��
//
//�߂�l�F(LRESULT)�����̐���
/////////////////////////////////////////////
HRESULT GameEngine::Input::Create(HWND hWnd)
{
    //---�e��錾---//
    HRESULT hr;

    //DirectInput�I�u�W�F�N�g����
    _factory = DXCT::DInput::DInputFactory::Create();
    if (!_factory)
    {
        MessageBoxA(hWnd, "DirectInput�I�u�W�F�N�g�����Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return S_FALSE;
    }

    //�Q�[���p�b�h�̏���
    hr = _joypad.Create(hWnd, _factory);
    if (FAILED(hr))
    {
        End();
        return hr;
    }

    //�L�[�{�[�h�̏���
    hr = _keyboard.Create(hWnd, _factory);
    if (FAILED(hr))
    {
        End();
        return hr;
    }

    //�}�E�X�̏���
    hr = _mouse.Create(hWnd, _factory);
    if (FAILED(hr))
    {
        End();
        return hr;
    }

    return hr;
}

//////////////////////////////////2///////////
//�֐����FEnd
//
//�@�\�F�f�o�C�X�̏I��
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void  GameEngine::Input::End(void)
{
    _joypad.End();
    _keyboard.End();
    _mouse.End();
    SAFE_RELEASE(_factory);
}

/////////////////////////////////////////////
//�֐����FUpdate
//
//�@�\�F���͏��̍X�V
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GameEngine::Input::Update(void)
{
    _joypad.Update();
    _keyboard.Update();
    _mouse.Update();
}

/////////////////////////////////////////////
//�֐����FGetJoyButton
//
//�@�\�F�Q�[���p�b�h�{�^�����͔���
//
//�����F(DWORD)�p�b�h�ԍ�,(DWORD)�{�^��,(PUSH_TYPE)����^�C�v
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool GameEngine::Input::GetJoyButton(DWORD joynumber, DWORD button, PUSH_TYPE type)
{
    switch (type)
    {
        case HOLD:
            return _joypad.GetHold(joynumber, button);

        case TRIGGER:
            return _joypad.GetTrigger(joynumber, button);

        case RELEASE:
            return _joypad.GetRelease(joynumber, button);

        default:
            return false;
    }
}

/////////////////////////////////////////////
//�֐����FGetJoyStick
//
//�@�\�F�Q�[���p�b�h�X�e�B�b�N���͎擾
//
//�����F(DWORD)�p�b�h�ԍ�,(AXIS_TYPE)���n��

//�߂�l�F(LONG)���̓f�[�^
/////////////////////////////////////////////
LONG GameEngine::Input::GetJoyStick(DWORD joynumber, AXIS_TYPE type)
{
    switch (type)
    {
    case X:
        return _joypad.GetAxisX(joynumber);

    case Y:
        return _joypad.GetAxisY(joynumber);

    case Z:
        return _joypad.GetAxisZ(joynumber);

    default:
        return 0;
    }
}

/////////////////////////////////////////////
//�֐����FGetKey
//
//�@�\�F�L�[�{�[�h���͔���
//
//�����F(DWORD)���̓{�^��,(PUSH_TYPE)����^�C�v
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool GameEngine::Input::GetKey(DWORD button, PUSH_TYPE type)
{
    switch (type)
    {
        case HOLD:
            return _keyboard.GetHold(button);

        case TRIGGER:
            return _keyboard.GetTrigger(button);

        case RELEASE:
            return _keyboard.GetRelease(button);

        default:
            return false;
    }
}

/////////////////////////////////////////////
//�֐����FGetMouseButton
//
//�@�\�F�}�E�X�{�^���g���K����
//
//�����F(DWORD)���̓{�^��,(PUSH_TYPE)����^�C�v
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool GameEngine::Input::GetMouseButton(DWORD button, PUSH_TYPE type)
{
    switch (type)
    {
        case HOLD:
            return _mouse.GetHold(button);

        case TRIGGER:
            return _mouse.GetTrigger(button);

        case RELEASE:
            return _mouse.GetRelease(button);

        default:
            return false;
    }
}

/////////////////////////////////////////////
//�֐����FGetMouseMove
//
//�@�\�F�}�E�X���W�擾
//
//�����F(DWORD)�p�b�h�ԍ�,(DWORD)���̓{�^��
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
DIMOUSESTATE* GameEngine::Input::GetMouseMove(void)
{
    return _mouse.GetState();
}

}