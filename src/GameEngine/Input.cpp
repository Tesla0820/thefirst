//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Input.h"

namespace GameEngine {

//------//
std::shared_ptr<DXCT::DInput::DInputFactory> Input::_factory;	//管理インターフェース
GameEngine::InputManager::Joypad             Input::_joypad;	//ゲームパッド
GameEngine::InputManager::Keyboard           Input::_keyboard;	//キーボード
GameEngine::InputManager::Mouse	             Input::_mouse;		//マウス


Input::Input()
{
}

void Input::Release()
{
}

//＝＝＝関数定義＝＝＝//
/////////////////////////////////////////////
//関数名：Create
//
//機能：デバイスの初期化
//
//引数：(HWND)ハンドル
//
//戻り値：(LRESULT)処理の成否
/////////////////////////////////////////////
HRESULT GameEngine::Input::Create(HWND hWnd)
{
    //---各種宣言---//
    HRESULT hr;

    //DirectInputオブジェクト生成
    _factory = DXCT::DInput::DInputFactory::Create();
    if (!_factory)
    {
        MessageBoxA(hWnd, "DirectInputオブジェクト生成に失敗しました。", "ERROR", MB_ICONSTOP | MB_OK);
        return S_FALSE;
    }

    //ゲームパッドの準備
    hr = _joypad.Create(hWnd, _factory);
    if (FAILED(hr))
    {
        End();
        return hr;
    }

    //キーボードの準備
    hr = _keyboard.Create(hWnd, _factory);
    if (FAILED(hr))
    {
        End();
        return hr;
    }

    //マウスの準備
    hr = _mouse.Create(hWnd, _factory);
    if (FAILED(hr))
    {
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
void  GameEngine::Input::End(void)
{
    _joypad.End();
    _keyboard.End();
    _mouse.End();
    SAFE_RELEASE(_factory);
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
void GameEngine::Input::Update(void)
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
//関数名：GetJoyStick
//
//機能：ゲームパッドスティック入力取得
//
//引数：(DWORD)パッド番号,(AXIS_TYPE)軸系統

//戻り値：(LONG)入力データ
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
//関数名：GetKey
//
//機能：キーボード入力判定
//
//引数：(DWORD)入力ボタン,(PUSH_TYPE)判定タイプ
//
//戻り値：(bool)判定結果
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
//関数名：GetMouseButton
//
//機能：マウスボタントリガ判定
//
//引数：(DWORD)入力ボタン,(PUSH_TYPE)判定タイプ
//
//戻り値：(bool)判定結果
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
//関数名：GetMouseMove
//
//機能：マウス座標取得
//
//引数：(DWORD)パッド番号,(DWORD)入力ボタン
//
//戻り値：(bool)判定結果
/////////////////////////////////////////////
DIMOUSESTATE* GameEngine::Input::GetMouseMove(void)
{
    return _mouse.GetState();
}

}