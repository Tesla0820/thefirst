//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "DInputJoypadDevice.h"

//���������C�u�����̃����N������//

namespace DXCT { namespace DInput {

//�������֐���`������//
/////////////////////////////////////////////
//�֐����FInitializeInput
//
//�@�\�F�Q�[���p�b�h�₢���킹�p�R�[���o�b�N�֐�
//
//�����F(HWND)�n���h��
//  
//�߂�l�F(BOOL)�����̐���
/////////////////////////////////////////////
BOOL CALLBACK Joypad::EnumJoyCallback( DIDEVICEINSTANCE const* lpddi, VOID* pvRef)
{
    //---�e��錾---//
    DIDEVCAPS diDevCaps;
    HRESULT   hr;

    hr = _pDI->CreateDevice(lpddi->guidInstance, &_device[_deviceValue], NULL);
    if (FAILED(hr))
    {
        return DIENUM_CONTINUE;
    }
    diDevCaps.dwSize = sizeof(diDevCaps);
    hr = _device[_deviceValue]->GetCapabilities(&diDevCaps);
    if (FAILED(hr))
    {
        SAFE_RELEASE(_device[_deviceValue]);
        return DIENUM_CONTINUE;
    }
    if (++_deviceValue < MAX_JOY)
    {
        return DIENUM_CONTINUE;
    }

    return DIENUM_STOP;
}

/////////////////////////////////////////////
//�֐����FInitialize
//
//�@�\�F�f�o�C�X�̏�����
//
//�����F(HWND)�n���h��,(IDirectInput8*)�f�o�C�X�}�l�[�W���[
//
//�߂�l�F(LRESULT)�����̐���
/////////////////////////////////////////////
HRESULT Joypad::Initialize(HWND hWnd, IDirectInput8* manager)
{
    //---�e��錾---//
    HRESULT hr;

    //---�f�o�C�X����---//
    _deviceValue = 0;
    hr = manager->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoyCallback, NULL, DIEDFL_ATTACHEDONLY);
    if (FAILED(hr))
    {
        DeleteDevice();
        MessageBoxA(hWnd, "�Q�[���p�b�h�̃I�u�W�F�N�g�����Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    //---���͐ݒ�---//
    for (DWORD i = 0; i < _deviceValue; ++i)
    {
        //�f�[�^ �t�H�[�}�b�g�ݒ�
        hr = _device[i]->SetDataFormat(&c_dfDIJoystick);
        if (FAILED(hr))
        {
            DeleteDevice();
            MessageBoxA(hWnd, "�Q�[���p�b�h�̃f�[�^�t�H�[�}�b�g�ݒ�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
            return hr;
        }
        //�������x���̐ݒ�
        hr = _device[i]->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
        if (FAILED(hr))
        {
            DeleteDevice();
            MessageBoxA(hWnd, "�Q�[���p�b�h�̋������x���ݒ�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
            return hr;
        }
        //�f�o�C�X�ݒ�
        DIPROPRANGE diprg;
        ZeroMemory(&diprg, sizeof(diprg));
        diprg.diph.dwSize = sizeof(diprg);
        diprg.diph.dwHeaderSize = sizeof(diprg.diph);
        diprg.diph.dwObj = DIJOFS_X;
        diprg.diph.dwHow = DIPH_BYOFFSET;
        diprg.lMin = JOY_MIN_X;
        diprg.lMax = JOY_MAX_X;
        _device[i]->SetProperty(DIPROP_RANGE, &diprg.diph);
        diprg.diph.dwObj = DIJOFS_Y;
        diprg.diph.dwHow = DIPH_BYOFFSET;
        diprg.lMin = JOY_MIN_Y;
        diprg.lMax = JOY_MAX_Y;
        _device[i]->SetProperty(DIPROP_RANGE, &diprg.diph);

        //�f�o�C�X�ւ̓��͐���J�n
        hr = _device[i]->Acquire();
        if (FAILED(hr))
        {
            DeleteDevice();
            MessageBoxA(hWnd, "�Q�[���p�b�h�̓��͐���J�n�Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
            return hr;
        }
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
void Joypad::End(void)
{
    DeleteDevice();
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
void Joypad::Update(void)
{
    //---�e��錾---//
    HRESULT hr;

    for (DWORD i = 0; i < _deviceValue; ++i)
    {
        _device[i]->Acquire();
        _device[i]->Poll();
        CopyMemory(&_preview[i], &_current[i], sizeof(DIJOYSTATE));
        hr = _device[i]->GetDeviceState(sizeof(DIJOYSTATE), &_current[i]);
        if (hr == DIERR_INPUTLOST)
        {
            _device[i]->Acquire();
        }
        else
        {
            for (int j = 0; j < 32; ++j)
            {
                _trigger[i].rgbButtons[j] = (_preview[i].rgbButtons[j] & _current[i].rgbButtons[j]) & 0x80;
                _release[i].rgbButtons[j] = (_preview[i].rgbButtons[j] & ~_current[i].rgbButtons[j]) & 0x80;
            }
        }
    }
}

/////////////////////////////////////////////
//�֐����FGetCount
//
//�@�\�F�Q�[���p�b�h���擾
//
//�����F�Ȃ�
//
//�߂�l�F(DWORD)�ڑ���
/////////////////////////////////////////////
DWORD Joypad::GetCount(void)
{
    return _deviceValue;
}

/////////////////////////////////////////////
//�֐����FGetState
//
//�@�\�F�Q�[���p�b�h��Ԏ擾
//
//�����F(DWORD)�p�b�h����

//�߂�l�F(DIJOYSTATE*)���͏��
/////////////////////////////////////////////
DIJOYSTATE* Joypad::GetState(DWORD joynumber)
{
    if (joynumber >= _deviceValue)
    {
        return nullptr;
    }
    return &_current[joynumber];
}

/////////////////////////////////////////////
//�֐����FGetAxisX
//
//�@�\�F�Q�[���p�b�hX���擾
//
//�����F(DWORD)�p�b�h�ԍ�
//
//�߂�l�F(LONG)���͓��e
/////////////////////////////////////////////
LONG Joypad::GetAxisX(DWORD joynumber)
{
    if (joynumber >= _deviceValue)
    {
        return 0;
    }
    return _current[joynumber].lX;
}

/////////////////////////////////////////////
//�֐����FGetAxisY
//
//�@�\�F�Q�[���p�b�hY���擾
//
//�����F(DWORD)�p�b�h�ԍ�
//
//�߂�l�F(LONG)���͓��e
/////////////////////////////////////////////
LONG Joypad::GetAxisY(DWORD joynumber)
{
    if (joynumber >= _deviceValue)
    {
        return 0;
    }
    return _current[joynumber].lY;
}

/////////////////////////////////////////////
//�֐����FGetAxisZ
//
//�@�\�F�Q�[���p�b�hZ���擾
//
//�����F(DWORD)�p�b�h�ԍ�
//
//�߂�l�F(LONG)���͓��e
/////////////////////////////////////////////
LONG Joypad::GetAxisZ(DWORD joynumber)
{
    if (joynumber >= _deviceValue)
    {
        return 0;
    }
    return _current[joynumber].lZ;
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
bool Joypad::GetHold(DWORD joynumber, DWORD button)
{
    if (joynumber >= _deviceValue)
    {
        return false;
    }
    if (button >= _countof(_current[joynumber].rgbButtons))
    {
        return false;
    }
    return (_current[joynumber].rgbButtons[button] & 0x80) != 0;
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
bool Joypad::GetTrigger(DWORD joynumber, DWORD button)
{
    if (joynumber >= _deviceValue)
    {
        return false;
    }
    if (button >= _countof(_trigger[joynumber].rgbButtons))
    {
        return false;
    }
    return (_trigger[joynumber].rgbButtons[button] & 0x80) != 0;
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
bool Joypad::GetRelease(DWORD joynumber, DWORD button)
{
    if (joynumber >= _deviceValue)
    {
        return false;
    }
    if (button >= _countof(_release[joynumber].rgbButtons))
    {
        return false;
    }
    return (_release[joynumber].rgbButtons[button] & 0x80) != 0;
}

/////////////////////////////////////////////
//�֐����FDeleteDevice
//
//�@�\�F�f�o�C�X�̍폜
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void Joypad::DeleteDevice(void)
{
    for (DWORD i = 0; i < _deviceValue; ++i)
    {
        SAFE_RELEASE(_device[i]);
    }
}

}}