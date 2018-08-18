//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Mouse.h"

namespace GameEngine { namespace InputManager
{

Mouse::Mouse()
{
    _device = nullptr;
}

//�������֐���`������//
/////////////////////////////////////////////
//�֐����FCreate
//
//�@�\�F�f�o�C�X�̏�����
//
//�����F(HWND)�n���h��,(DInputFactory)�f�o�C�X�}�l�[�W���[
//
//�߂�l�F(LRESULT)�����̐���
/////////////////////////////////////////////
HRESULT Mouse::Create(HWND hWnd, std::shared_ptr<DXCT::DInput::DInputFactory> manager)
{
    //---�e��錾---//
    HRESULT hr;

    //---�f�o�C�X����---//
    _device = manager->CreateDevice(GUID_SysMouse, NULL);
    if (!_device)
    {
        MessageBoxA(hWnd, "�}�E�X�̃I�u�W�F�N�g�����Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return S_FALSE;
    }

    //---���͐ݒ�---//
    //�f�[�^�t�H�[�}�b�g�ݒ�
    hr = _device->SetDataFormat(&c_dfDIMouse);
    if (FAILED(hr))
    {
        End();
        MessageBoxA(hWnd, "�}�E�X�̃f�[�^�t�H�[�}�b�g�ݒ�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }
    //�������x���̐ݒ�
    hr = _device->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
    if (FAILED(hr))
    {
        End();
        MessageBoxA(hWnd, "�}�E�X�̋������x���ݒ�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    //�f�o�C�X�ݒ�
    DIPROPDWORD dipdw;
    dipdw.diph.dwSize = sizeof(DIPROPDWORD);
    dipdw.diph.dwHeaderSize = sizeof(dipdw.diph);
    dipdw.diph.dwObj = 0;
    dipdw.diph.dwHow = DIPH_DEVICE;
    dipdw.dwData = DIPROPAXISMODE_REL;
    hr = _device->SetProperty(DIPROP_AXISMODE, &dipdw.diph);
    if (FAILED(hr))
    {
        End();
        MessageBoxA(hWnd, "�}�E�X�̃f�o�C�X�ݒ�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    //�f�o�C�X�ւ̓��͐���J�n
    hr = _device->Acquire();
    if (FAILED(hr))
    {
        End();
        MessageBoxA(hWnd, "�}�E�X�̓��͐���J�n�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }
    return hr;
}

/////////////////////////////////////////////
//�֐����FEnd
//
//�@�\�F�f�o�C�X�̏I��
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void Mouse::End(void)
{
    SAFE_RELEASE(_device);
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
void Mouse::Update(void)
{
    //---�e��錾---//
    HRESULT hr;

    if (_device)
    {
        _device->Acquire();
        memcpy(&_preview, &_current, sizeof(DIMOUSESTATE));
        hr = _device->GetDeviceState(sizeof(DIMOUSESTATE), &_current);
        if (hr == DIERR_INPUTLOST)
        {
            _device->Acquire();
        }
        else
        {
            for (int i = 0; i < 4; ++i)
            {
                _trigger.rgbButtons[i] = (~_preview.rgbButtons[i] & _current.rgbButtons[i]) & 0x80;
                _release.rgbButtons[i] = (_preview.rgbButtons[i] & ~_current.rgbButtons[i]) & 0x80;
            }
        }
    }
}

/////////////////////////////////////////////
//�֐����FGetState
//
//�@�\�F�}�E�X��Ԏ擾
//
//�����F(DWORD)�}�E�X����

//�߂�l�F(DIJOYSTATE*)���͏��
/////////////////////////////////////////////
DIMOUSESTATE* Mouse::GetState(void)
{
    return &_current;
}

/////////////////////////////////////////////
//�֐����FGetHold
//
//�@�\�F�{�^���z�[���h����
//
//�����F(DWORD)�p�b�h�ԍ�,(DWORD)���̓{�^��
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool Mouse::GetHold(DWORD button)
{
    if (button >= _countof(_current.rgbButtons))
    {
        return false;
    }
    return (_current.rgbButtons[button] & 0x80) != 0;
}

/////////////////////////////////////////////
//�֐����FGetTrigger
//
//�@�\�F�{�^���g���K����
//
//�����F(DWORD)�p�b�h�ԍ�,(DWORD)���̓{�^��
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool Mouse::GetTrigger(DWORD button)
{
    if (button >= _countof(_trigger.rgbButtons))
    {
        return false;
    }
    return (_trigger.rgbButtons[button] & 0x80) != 0;
}

/////////////////////////////////////////////
//�֐����FGetRelease
//
//�@�\�F�{�^�������[�X����
//
//�����F(DWORD)�p�b�h�ԍ�,(DWORD)���̓{�^��
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool Mouse::GetRelease(DWORD button)
{
    if (button >= _countof(_release.rgbButtons))
    {
        return false;
    }
    return (_release.rgbButtons[button] & 0x80) != 0;
}

}}