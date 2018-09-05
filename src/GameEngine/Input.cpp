//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Input.h"

namespace GameEngine {

//------//
std::shared_ptr<DXCT::DInput::DInputFactory> Input::_factory;	//管理インターフェース
GameEngine::InputManager::Keyboard           Input::_keyboard;	//キーボード


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

	//キーボードの準備
	hr = _keyboard.Create(hWnd, _factory);
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
	_keyboard.End();
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
	_keyboard.Update();
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

}