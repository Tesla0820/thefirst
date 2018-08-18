//
//		ファイル名:Keyboard.h
//

#ifndef HEADER_KEYBOARD_H
#define HEADER_KEYBOARD_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "../GameEngine_inner.h"

namespace GameEngine { namespace InputManager
{

//＝＝＝クラス宣言＝＝＝//
class Keyboard
{
    private:
        std::shared_ptr<DXCT::DInput::DInputDevice> _device;       //デバイス
        BYTE			                            _current[256];	//現在の状態
        BYTE			                            _preview[256];	//前回の状態
        BYTE			                            _trigger[256];	//トリガ状態
        BYTE			                            _release[256];	//リリース状態

    public:
        Keyboard();

        HRESULT Create(HWND, std::shared_ptr<DXCT::DInput::DInputFactory>);
        void End(void);
        void Update(void);

        bool GetHold(DWORD);
        bool GetTrigger(DWORD);
        bool GetRelease(DWORD);
};

}}
#endif