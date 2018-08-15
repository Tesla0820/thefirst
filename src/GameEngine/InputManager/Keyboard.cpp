//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "DInputKeyboardDevice.h"

//���������C�u�����̃����N������//

namespace DXCT { namespace DInput 
{
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
HRESULT Keyboard::Initialize(HWND hWnd, IDirectInput8* manager)
{
    //---�e��錾---//
    HRESULT hr;

    //---�f�o�C�X����---//
    hr = manager->CreateDevice(GUID_SysKeyboard, &_device, NULL);
    if (FAILED(hr))
    {
        MessageBoxA(hWnd, "�L�[�{�[�h�̃I�u�W�F�N�g�����Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    //---���͐ݒ�---//
    //�f�[�^ �t�H�[�}�b�g�ݒ�
    hr = _device->SetDataFormat(&c_dfDIKeyboard);
    if (FAILED(hr))
    {
        SAFE_RELEASE(_device);
        MessageBoxA(hWnd, "�L�[�{�[�h�̃f�[�^�t�H�[�}�b�g�ݒ�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }
    //�������x���̐ݒ�
    hr = _device->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
    if (FAILED(hr))
    {
        SAFE_RELEASE(_device);
        MessageBoxA(hWnd, "�L�[�{�[�h�̋������x���ݒ�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    //�f�o�C�X�ւ̓��͐���J�n
    hr = _device->Acquire();
    if (FAILED(hr))
    {
        SAFE_RELEASE(_device);
        MessageBoxA(hWnd, "�Q�[���p�b�h�̓��͐���J�n�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
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
void Keyboard::End(void)
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
void Keyboard::Update(void)
{
    //---�e��錾---//
    HRESULT hr;

    if (_device)
    {
        _device->Acquire();
        CopyMemory(_preview, _current, 256);
        hr = _device->GetDeviceState(256, _current);
        if (hr == DIERR_INPUTLOST)
        {
            _device->Acquire();
        }
        else
        {
            for (int i = 0; i < 256; ++i)
            {
                _trigger[i] = (~_preview[i] & _current[i]) & 0x80;
                _release[i] = (_preview[i] & ~_current[i]) & 0x80;
            }
        }
    }
}

/////////////////////////////////////////////
//�֐����FGetHold
//
//�@�\�F�{�^���z�[���h����
//
//�����F(DWORD)���̓{�^��
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool Keyboard::GetHold(DWORD button)
{
    if (button >= _countof(_current))
    {
        return false;
    }
    return (_current[button] & 0x80) != 0;
}

/////////////////////////////////////////////
//�֐����FGetTrigger
//
//�@�\�F�{�^���g���K����
//
//�����F(DWORD)���̓{�^��
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool Keyboard::GetTrigger(DWORD button)
{
    if (button >= _countof(_trigger))
    {
        return false;
    }
    return (_trigger[button] & 0x80) != 0;
}

/////////////////////////////////////////////
//�֐����FGetRelease
//
//�@�\�F�{�^�������[�X����
//
//�����F(DWORD)���̓{�^��
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool Keyboard::GetRelease(DWORD button)
{
    if (button >= _countof(_release))
    {
        return false;
    }
    return (_release[button] & 0x80) != 0;
}

}}