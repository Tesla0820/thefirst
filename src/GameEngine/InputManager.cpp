//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "InputManager.h"

//���������C�u�����̃����N������//
#pragma comment(lib, "dinput8")

namespace GameEngine {
//�������֐���`������//
/////////////////////////////////////////////
//�֐����FInitialize
//
//�@�\�F�f�o�C�X�̏�����
//
//�����F(HWND)�n���h��,(IDirectInput8*)�f�o�C�X�}�l�[�W���[
//
//�߂�l�F(LRESULT)�����̐���
/////////////////////////////////////////////
HRESULT GameEngine::InputManager::Initialize(HWND hWnd)
{
    //---�e��錾---//
    HRESULT hr;
    HINSTANCE hInst;

    hInst = (HINSTANCE)GetWindowLong(hWnd, -6/*GWL_HINSTANCE*/);

    //DirectInput�I�u�W�F�N�g����
    hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&_manager, NULL);
    if (FAILED(hr))
    {
        MessageBoxA(hWnd, "DirectInput�I�u�W�F�N�g�����Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    //�Q�[���p�b�h�̏���
    hr = _joypad.Initialize(hWnd, _manager);
    if (FAILED(hr))
    {
        End();
        return hr;
    }

    //�L�[�{�[�h�̏���
    hr = _keyboard.Initialize(hWnd, _manager);
    if (FAILED(hr))
    {
        _joypad.End();
        End();
        return hr;
    }

    //�}�E�X�̏���
    hr = _mouse.Initialize(hWnd, _manager);
    if (FAILED(hr))
    {
        _joypad.End();
        _keyboard.End();
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
void  GameEngine::InputManager::End(void)
{
    _joypad.End();
    _keyboard.End();
    _mouse.End();
    SAFE_RELEASE(_manager);
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
void GameEngine::InputManager::Update(void)
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
bool GameEngine::InputManager::GetJoyButton(DWORD joynumber, DWORD button, PUSH_TYPE type)
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
LONG GameEngine::InputManager::GetJoyStick(DWORD joynumber, AXIS_TYPE type)
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
bool GameEngine::InputManager::GetKey(DWORD button, PUSH_TYPE type)
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
bool GameEngine::InputManager::GetMouseButton(DWORD button, PUSH_TYPE type)
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
DIMOUSESTATE* GameEngine::InputManager::GetMouseMove(void)
{
    return _mouse.GetState();
}

}