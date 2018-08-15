//
//		ファイル名:DInputjoypadDevice.h
//

#ifndef _HEADER_DINPUT_JOYPAD_DEVICE_H
#define _HEADER_DINPUT_JOYPAD_DEVICE_H

#include "../GameEngine_inner.h"

//＝＝＝定数・マクロ定義＝＝＝//
#define MAX_JOY		8		// 最大接続数
#define JOY_MIN_X	-32768	// Ｘ軸最小値
#define JOY_MAX_X	32767	// Ｘ軸最大値
#define JOY_MIN_Y	-32768	// Ｙ軸最小値
#define JOY_MAX_Y	32767	// Ｙ軸最大値


namespace DXCT { namespace DInput 
{

class Joypad
{
    private:
        IDirectInputDevice8* _device[MAX_JOY];  //デバイス
        DWORD				 _deviceValue;		//接続数
        DIJOYSTATE			 _current[MAX_JOY];	//現在の状態
        DIJOYSTATE			 _preview[MAX_JOY];	//前回の状態
        DIJOYSTATE			 _trigger[MAX_JOY];	//トリガ状態
        DIJOYSTATE			 _release[MAX_JOY];	//リリース状態

    public:
        HRESULT Initialize(HWND, std::shared_ptr<);
        void End(void);
        void Update(void);

        DWORD GetCount(void);
        DIJOYSTATE* GetState(DWORD);
        LONG GetAxisX(DWORD);
        LONG GetAxisY(DWORD);
        LONG GetAxisZ(DWORD);
        bool GetHold(DWORD, DWORD);
        bool GetTrigger(DWORD, DWORD);
        bool GetRelease(DWORD, DWORD);
        void DeleteDevice(void);

};

    
}
}
#endif