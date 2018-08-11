//
//		ファイル名:DInputMouseDevice.h
//

#ifndef _HEADER_DINPUT_MOUSE_DEVICE_H
#define _HEADER_DINPUT_MOUSE_DEVICE_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#define DIRECTINPUT_VERSION	0x0800	//DirectX8 を明示
#include <dinput.h>					//DirectInput 関連のヘッダ
#include <windows.h>
#include <WinUser.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "../DXObject.h"

//＝＝＝定数・マクロ定義＝＝＝//
#define MAX_JOY		8		// 最大接続数
#define JOY_MIN_X	-32768	// Ｘ軸最小値
#define JOY_MAX_X	32767	// Ｘ軸最大値
#define JOY_MIN_Y	-32768	// Ｙ軸最小値
#define JOY_MAX_Y	32767	// Ｙ軸最大値


namespace DXCT { namespace DInput {

//＝＝＝クラス宣言＝＝＝//
class Mouse : public DXObject<IDirectInput8>
{
    private:
        IDirectInputDevice8* _device;  //デバイス
        DIMOUSESTATE		 _current;	//現在の状態
        DIMOUSESTATE		 _preview;	//前回の状態
        DIMOUSESTATE		 _trigger;	//トリガ状態
        DIMOUSESTATE		 _release;	//リリース状態


    public:
        HRESULT Initialize(HWND, IDirectInput8*);
        void End(void);
        void Update(void);

        DIMOUSESTATE* GetState(void);
        bool GetHold(DWORD);
        bool GetTrigger(DWORD);
        bool GetRelease(DWORD);
};

}}
#endif