//
//		ファイル名:InputManager.h
//

#ifndef _HEADER_INPUT_MANAGER_H
#define _HEADER_INPUT_MANAGER_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include <dinput.h>					//DirectInput 関連のヘッダ
#include <windows.h>
#include <WinUser.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "../DXCT/DInput/DInputJoypadDevice.h"
#include "../DXCT/DInput/DInputKeyboardDevice.h"
#include "../DXCT/DInput/DInputMouseDevice.h"

//＝＝＝列挙型定義＝＝＝//
typedef enum
{
    HOLD,
    RELEASE,
    TRIGGER,
    PUSH_TYPE_MAX
}PUSH_TYPE;

typedef enum
{
    X,
    Y,
    Z,
    AXIS_TYPE_MAX
}AXIS_TYPE;

namespace GameEngine {
//＝＝＝クラス宣言＝＝＝//
class InputManager
{
    private:
        IDirectInput8*         _manager;	//管理インターフェース
        DXCT::DInput::Joypad   _joypad;		//ゲームパッド
        DXCT::DInput::Keyboard _keyboard;	//キーボード
        DXCT::DInput::Mouse	   _mouse;		//マウス

    public:
        HRESULT Initialize(HWND);
        void End(void);
        void Update(void);

        BOOL CallJoyInfo(const DIDEVICEINSTANCE* lpddi);

        bool GetJoyButton(DWORD, DWORD, PUSH_TYPE);
        LONG GetJoyStick(DWORD, AXIS_TYPE);
        bool GetKey(DWORD, PUSH_TYPE);
        bool GetMouseButton(DWORD, PUSH_TYPE);
        DIMOUSESTATE* GetMouseMove(void);
};

//＝＝＝プロトタイプ宣言＝＝＝//
static BOOL CALLBACK EnumJoyCallback(const DIDEVICEINSTANCE*, VOID*);

}
#endif