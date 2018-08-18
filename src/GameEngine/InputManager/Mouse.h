//
//		ファイル名:Mouse.h
//

#ifndef HEADER_MOUSE_H
#define HEADER_MOUSE_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "../GameEngine_inner.h"

namespace GameEngine {namespace InputManager
{

//＝＝＝クラス宣言＝＝＝//
class Mouse
{
    private:
        std::shared_ptr<DXCT::DInput::DInputDevice> _device;    //デバイス
        DIMOUSESTATE		                        _current;	//現在の状態
        DIMOUSESTATE		                        _preview;	//前回の状態
        DIMOUSESTATE		                        _trigger;	//トリガ状態
        DIMOUSESTATE		                        _release;	//リリース状態

    public:
        Mouse();

        HRESULT Create(HWND, std::shared_ptr<DXCT::DInput::DInputFactory>);
        void End(void);
        void Update(void);

        DIMOUSESTATE* GetState(void);
        bool GetHold(DWORD);
        bool GetTrigger(DWORD);
        bool GetRelease(DWORD);
};

}}
#endif