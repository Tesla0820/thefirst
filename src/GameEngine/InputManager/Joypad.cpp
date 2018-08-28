//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Joypad.h"

//＝＝＝定数・マクロ定義＝＝＝//
#define MAX_JOY		8		// 最大接続数
#define JOY_MIN_X	-32768	// Ｘ軸最小値
#define JOY_MAX_X	32767	// Ｘ軸最大値
#define JOY_MIN_Y	-32768	// Ｙ軸最小値
#define JOY_MAX_Y	32767	// Ｙ軸最大値

namespace GameEngine { namespace InputManager
{

//＝＝＝関数定義＝＝＝//
/////////////////////////////////////////////
//関数名：EnumCallBack
//
//機能：コールバック関数の呼び出し
//
//引数：(std::shared_ptr<DXCT::DInput::DInputFactory>)デバイス, (DIDEVICEINSTANCE const*)インスタンス, (void*)リファレンス
//
//戻り値：(int)結果
/////////////////////////////////////////////
int Joypad::EnumCallBack(std::shared_ptr<DXCT::DInput::DInputFactory> factory, DIDEVICEINSTANCE const* instance, void* reference)
{
    ////---各種宣言---//
    //DIDEVCAPS diDevCaps;
    //HRESULT   hr;

    //hr = factory->EnumDeviceCallBackBase(instance, reference);
    //if (FAILED(hr))
    //{
    //    return DIENUM_CONTINUE;
    //}
    //diDevCaps.dwSize = sizeof(diDevCaps);
    //hr = _device[_deviceValue]->GetCapabilities(&diDevCaps);
    //if (FAILED(hr))
    //{
    //    SAFE_RELEASE(_device[_deviceValue]);
    //    return DIENUM_CONTINUE;
    //}
    //if (++_deviceValue < MAX_JOY)
    //{
    //    return DIENUM_CONTINUE;
    //}

    return DIENUM_STOP;
}

/////////////////////////////////////////////
//関数名：Initialize
//
//機能：デバイスの初期化
//
//引数：(HWND)ハンドル,(DInputFactory)デバイスマネージャー
//
//戻り値：(LRESULT)処理の成否
/////////////////////////////////////////////
HRESULT GameEngine::InputManager::Joypad::Create(HWND hWnd, std::shared_ptr<DXCT::DInput::DInputFactory> manager)
{
    ////---各種宣言---//
    //HRESULT hr;
    //
    ////---デバイス生成---//
    //_deviceValue = 0;
    //hr = manager->EnumDevices(DI8DEVCLASS_GAMECTRL, std::bind<int>(&Joypad::EnumCallBack, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), NULL, DIEDFL_ATTACHEDONLY);
    //if (FAILED(hr))
    //{
    //    DeleteDevice();
    //    MessageBoxA(hWnd, "ゲームパッドのオブジェクト生成に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
    //    return S_FALSE;
    //}

    ////---入力設定---//
    //for (DWORD i = 0; i < _deviceValue; ++i)
    //{
    //    //データ フォーマット設定
    //    hr = _device[i]->SetDataFormat(&c_dfDIJoystick);
    //    if (FAILED(hr))
    //    {
    //        DeleteDevice();
    //        MessageBoxA(hWnd, "ゲームパッドのデータフォーマット設定に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
    //        return hr;
    //    }
    //    //協調レベルの設定
    //    hr = _device[i]->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
    //    if (FAILED(hr))
    //    {
    //        DeleteDevice();
    //        MessageBoxA(hWnd, "ゲームパッドの協調レベル設定に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
    //        return hr;
    //    }
    //    //デバイス設定
    //    DIPROPRANGE diprg;
    //    ZeroMemory(&diprg, sizeof(diprg));
    //    diprg.diph.dwSize = sizeof(diprg);
    //    diprg.diph.dwHeaderSize = sizeof(diprg.diph);
    //    diprg.diph.dwObj = DIJOFS_X;
    //    diprg.diph.dwHow = DIPH_BYOFFSET;
    //    diprg.lMin = JOY_MIN_X;
    //    diprg.lMax = JOY_MAX_X;
    //    _device[i]->SetProperty(DIPROP_RANGE, &diprg.diph);
    //    diprg.diph.dwObj = DIJOFS_Y;
    //    diprg.diph.dwHow = DIPH_BYOFFSET;
    //    diprg.lMin = JOY_MIN_Y;
    //    diprg.lMax = JOY_MAX_Y;
    //    _device[i]->SetProperty(DIPROP_RANGE, &diprg.diph);
    //    if (FAILED(hr))
    //    {
    //        End();
    //        MessageBoxA(hWnd, "ゲームパッドのデバイス設定に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
    //        return hr;
    //    }

    //    //デバイスへの入力制御開始
    //    hr = _device[i]->Acquire();
    //    if (FAILED(hr))
    //    {
    //        DeleteDevice();
    //        MessageBoxA(hWnd, "ゲームパッドの入力制御開始に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
    //        return hr;
    //    }
    //}
    //return  hr;
    return S_OK;
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
void Joypad::End(void)
{
    DeleteDevice();
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
void Joypad::Update(void)
{
    //---各種宣言---//
    HRESULT hr;

    for (DWORD i = 0; i < _deviceValue; ++i)
    {
        _device[i]->Acquire();
        _device[i]->Poll();
        memcpy(&_preview[i], &_current[i], sizeof(DIJOYSTATE));
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
//関数名：GetCount
//
//機能：ゲームパッド数取得
//
//引数：なし
//
//戻り値：(DWORD)接続数
/////////////////////////////////////////////
DWORD Joypad::GetCount(void)
{
    return _deviceValue;
}

/////////////////////////////////////////////
//関数名：GetState
//
//機能：ゲームパッド状態取得
//
//引数：(DWORD)パッド入力

//戻り値：(DIJOYSTATE*)入力状態
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
//関数名：GetAxisX
//
//機能：ゲームパッドX軸取得
//
//引数：(DWORD)パッド番号
//
//戻り値：(LONG)入力内容
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
//関数名：GetAxisY
//
//機能：ゲームパッドY軸取得
//
//引数：(DWORD)パッド番号
//
//戻り値：(LONG)入力内容
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
//関数名：GetAxisZ
//
//機能：ゲームパッドZ軸取得
//
//引数：(DWORD)パッド番号
//
//戻り値：(LONG)入力内容
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
//関数名：GetHold
//
//機能：ボタンホールド判定
//
//引数：(DWORD)パッド番号,(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
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
//関数名：GetTrigger
//
//機能：ボタントリガ判定
//
//引数：(DWORD)パッド番号,(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
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
//関数名：GetRelease
//
//機能：ボタンリリース判定
//
//引数：(DWORD)パッド番号,(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
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
//関数名：DeleteDevice
//
//機能：デバイスの削除
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void Joypad::DeleteDevice(void)
{
    for (DWORD i = 0; i < _deviceValue; ++i)
    {
        SAFE_RELEASE(_device[i]);
    }
}

}}