//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "InputManager.h"

//＝＝＝ライブラリのリンク＝＝＝//
#pragma comment(lib, "dinput8")

namespace GameEngine {
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
HRESULT GameEngine::InputManager::Initialize(HWND hWnd)
{
    //---各種宣言---//
    HRESULT hr;
    HINSTANCE hInst;

    hInst = (HINSTANCE)GetWindowLong(hWnd, -6/*GWL_HINSTANCE*/);

    //DirectInputオブジェクト生成
    hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&_manager, NULL);
    if (FAILED(hr))
    {
        MessageBoxA(hWnd, "DirectInputオブジェクト生成に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return hr;
    }

    //ゲームパッドの準備
    hr = _joypad.Initialize(hWnd, _manager);
    if (FAILED(hr))
    {
        End();
        return hr;
    }

    //キーボードの準備
    hr = _keyboard.Initialize(hWnd, _manager);
    if (FAILED(hr))
    {
        _joypad.End();
        End();
        return hr;
    }

    //マウスの準備
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
//関数名：End
//
//機能：デバイスの終了
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void  GameEngine::InputManager::End(void)
{
    _joypad.End();
    _keyboard.End();
    _mouse.End();
    SAFE_RELEASE(_manager);
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
void GameEngine::InputManager::Update(void)
{
    _joypad.Update();
    _keyboard.Update();
    _mouse.Update();
}

/////////////////////////////////////////////
//関数名：GetJoyButton
//
//機能：ゲームパッドボタン入力判定
//
//引数：(DWORD)パッド番号,(DWORD)ボタン,(PUSH_TYPE)判定タイプ
//
//戻り値：(bool)判定結果
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
//関数名：GetJoyStick
//
//機能：ゲームパッドスティック入力取得
//
//引数：(DWORD)パッド番号,(AXIS_TYPE)軸系統

//戻り値：(LONG)入力データ
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
//関数名：GetKey
//
//機能：キーボード入力判定
//
//引数：(DWORD)入力ボタン,(PUSH_TYPE)判定タイプ
//
//戻り値：(bool)判定結果
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
//関数名：GetMouseButton
//
//機能：マウスボタントリガ判定
//
//引数：(DWORD)入力ボタン,(PUSH_TYPE)判定タイプ
//
//戻り値：(bool)判定結果
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
//関数名：GetMouseMove
//
//機能：マウス座標取得
//
//引数：(DWORD)パッド番号,(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
/////////////////////////////////////////////
DIMOUSESTATE* GameEngine::InputManager::GetMouseMove(void)
{
    return _mouse.GetState();
}

}