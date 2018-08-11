//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "DInputMouseDevice.h"

//＝＝＝ライブラリのリンク＝＝＝//
#pragma comment(lib, "dinput8")

namespace DXCT { namespace DInput {

//＝＝＝関数定義＝＝＝//
/////////////////////////////////////////////
//関数名：Initialize
//
//機能：デバイスの初期化
//
//引数：(HWND)ハンドル,(IDirectInput8*)デバイスマネージャー
//
//戻り値：(LRESULT)処理の成否
/////////////////////////////////////////////
HRESULT DXCT::DInput::Mouse::Initialize(HWND hWnd, IDirectInput8* manager)
{
    //---各種宣言---//
    HRESULT hr;

    //---デバイス生成---//
    hr = manager->CreateDevice(GUID_SysMouse, &_device, NULL);
    if (FAILED(hr))
    {
        MessageBoxA(hWnd, "マウスのオブジェクト生成に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }
    // データ フォーマット設定
    hr = _device->SetDataFormat(&c_dfDIMouse);
    if (FAILED(hr))
    {
        End();
        MessageBoxA(hWnd, "マウスのデータフォーマット設定に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }
    // 協調レベルの設定
    hr = _device->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
    if (FAILED(hr))
    {
        End();
        MessageBoxA(hWnd, "マウスの協調レベル設定に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    // デバイス設定
    DIPROPDWORD dipdw;
    dipdw.diph.dwSize = sizeof(dipdw);
    dipdw.diph.dwHeaderSize = sizeof(dipdw.diph);
    dipdw.diph.dwObj = 0;
    dipdw.diph.dwHow = DIPH_DEVICE;
    dipdw.dwData = DIPROPAXISMODE_REL;
    _device->SetProperty(DIPROP_AXISMODE, &dipdw.diph);

    // デバイスへの入力制御開始
    hr = _device->Acquire();
    if (FAILED(hr))
    {
        End();
        MessageBoxA(hWnd, "マウスの入力制御開始に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }
    return hr;
}

//////////////////////////////////2///////////
//関数名：End
//
//機能：デバイスの終了
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void DXCT::DInput::Mouse::End(void)
{
    SAFE_RELEASE(_device);
}

/////////////////////////////////////////////
//関数名：Update
//
//機能：入力情報の更新
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void DXCT::DInput::Mouse::Update(void)
{
    //---各種宣言---//
    HRESULT hr;

    if (_device)
    {
        _device->Acquire();
        CopyMemory(&_preview, &_current, sizeof(DIMOUSESTATE));
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
//関数名：GetState
//
//機能：マウス状態取得
//
//引数：(DWORD)マウス入力

//戻り値：(DIJOYSTATE*)入力状態
/////////////////////////////////////////////
DIMOUSESTATE* DXCT::DInput::Mouse::GetState(void)
{
    return &_current;
}

/////////////////////////////////////////////
//関数名：GetHold
//
//機能：ボタンホールド判定
//
//引数：(DWORD)パッド番号,(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
/////////////////////////////////////////////
bool DXCT::DInput::Mouse::GetHold(DWORD button)
{
    if (button >= _countof(_current.rgbButtons))
    {
        return false;
    }
    return (_current.rgbButtons[button] & 0x80) != 0;
}

/////////////////////////////////////////////
//関数名：GetTrigger
//
//機能：ボタントリガ判定
//
//引数：(DWORD)パッド番号,(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
/////////////////////////////////////////////
bool DXCT::DInput::Mouse::GetTrigger(DWORD button)
{
    if (button >= _countof(_trigger.rgbButtons))
    {
        return false;
    }
    return (_trigger.rgbButtons[button] & 0x80) != 0;
}

/////////////////////////////////////////////
//関数名：GetRelease
//
//機能：ボタンリリース判定
//
//引数：(DWORD)パッド番号,(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
/////////////////////////////////////////////
bool DXCT::DInput::Mouse::GetRelease(DWORD button)
{
    if (button >= _countof(_release.rgbButtons))
    {
        return false;
    }
    return (_release.rgbButtons[button] & 0x80) != 0;
}

}}