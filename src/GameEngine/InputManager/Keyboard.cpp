//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Keyboard.h"

namespace GameEngine { namespace InputManager
{

Keyboard::Keyboard()
{

}

//＝＝＝関数定義＝＝＝//
/////////////////////////////////////////////
//関数名：Create
//
//機能：デバイスの初期化
//
//引数：(HWND)ハンドル,(DInputFactory)デバイスマネージャー
//
//戻り値：(LRESULT)処理の成否
/////////////////////////////////////////////
HRESULT Keyboard::Create(HWND hWnd , std::shared_ptr<DXCT::DInput::DInputFactory> manager)
{
    //---各種宣言---//
    HRESULT hr;

    //---デバイス生成---//
    _device = manager->CreateDevice(GUID_SysKeyboard, NULL);
    if (!_device)
    {
        MessageBoxA(hWnd, "キーボードのオブジェクト生成に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return S_FALSE;
    }

    //---入力設定---//
    //データフォーマット設定
    hr = _device->SetDataFormat(&c_dfDIKeyboard);
    if (FAILED(hr))
    {
        SAFE_RELEASE(_device);
        MessageBoxA(hWnd, "キーボードのデータフォーマット設定に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }
    //協調レベルの設定
    hr = _device->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
    if (FAILED(hr))
    {
        SAFE_RELEASE(_device);
        MessageBoxA(hWnd, "キーボードの協調レベル設定に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    //デバイスへの入力制御開始
    hr = _device->Acquire();
    if (FAILED(hr))
    {
        SAFE_RELEASE(_device);
        MessageBoxA(hWnd, "キーボードの入力制御開始に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
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
void Keyboard::End(void)
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
void Keyboard::Update(void)
{
    //---各種宣言---//
    HRESULT hr;

    if (_device)
    {
        _device->Acquire();
        memcpy(_preview, _current, 256);
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
//関数名：GetHold
//
//機能：ボタンホールド判定
//
//引数：(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
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
//関数名：GetTrigger
//
//機能：ボタントリガ判定
//
//引数：(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
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
//関数名：GetRelease
//
//機能：ボタンリリース判定
//
//引数：(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
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