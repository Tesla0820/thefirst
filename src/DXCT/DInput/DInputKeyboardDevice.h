//
//		ファイル名:DInputKeyboardDevice.h
//

#ifndef _HEADER_DINPUT_KEYBOARD_DEVICE_H
#define _HEADER_DINPUT_KEYBOARD_DEVICE_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#define DIRECTINPUT_VERSION	0x0800	//DirectX8 を明示
#include <dinput.h>					//DirectInput 関連のヘッダ
#include <windows.h>
#include <WinUser.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "../DXObject.h"


namespace DXCT { namespace DInput {

//＝＝＝クラス宣言＝＝＝//
class Keyboard : public DXObject<IDirectInput8>
{
    private:
        IDirectInputDevice8* _device;       //デバイス
        BYTE			     _current[256];	//現在の状態
        BYTE			     _preview[256];	//前回の状態
        BYTE			     _trigger[256];	//トリガ状態
        BYTE			     _release[256];	//リリース状態

    public:
        HRESULT Initialize(HWND, IDirectInput8*);
        void End(void);
        void Update(void);

        bool GetHold(DWORD);
        bool GetTrigger(DWORD);
        bool GetRelease(DWORD);
};

}}
#endif