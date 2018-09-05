//
//		ファイル名:InputManager.h
//

#ifndef _HEADER_INPUT_MANAGER_H
#define _HEADER_INPUT_MANAGER_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "GameEngine_inner.h"
#include "InputManager/Keyboard.h"

//＝＝＝列挙型定義＝＝＝//
typedef enum
{
    HOLD,
    RELEASE,
    TRIGGER,
    PUSH_TYPE_MAX
}PUSH_TYPE;

namespace GameEngine 
{

//＝＝＝クラス宣言＝＝＝//
class Input
{
    private:
        static std::shared_ptr<DXCT::DInput::DInputFactory>     _factory;	//管理インターフェース
        static GameEngine::InputManager::Keyboard _keyboard;	//キーボード

    public:
        Input();

        static void Release();

        static HRESULT Create(HWND);
        static void End(void);
        static void Update(void);

        static bool GetKey(DWORD, PUSH_TYPE);
};

}
#endif