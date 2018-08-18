//
//		ファイル名:DInputjoypadDevice.h
//

#ifndef _HEADER_DINPUT_JOYPAD_DEVICE_H
#define _HEADER_DINPUT_JOYPAD_DEVICE_H


#include "../GameEngine_inner.h"

#define MAX_JOY		8		// 最大接続数

namespace GameEngine { namespace InputManager {

class Joypad
{
    private:
        std::shared_ptr<DXCT::DInput::DInputDevice> _device[MAX_JOY];       //デバイス
        DWORD				                        _deviceValue;		//接続数
        DIJOYSTATE			                        _current[MAX_JOY];	//現在の状態
        DIJOYSTATE			                        _preview[MAX_JOY];	//前回の状態
        DIJOYSTATE			                        _trigger[MAX_JOY];	//トリガ状態
        DIJOYSTATE			                        _release[MAX_JOY];	//リリース状態

        int EnumCallBack(std::shared_ptr<DXCT::DInput::DInputFactory>, DIDEVICEINSTANCE const*, void*);
        void DeleteDevice(void);

    public:
        HRESULT Create(HWND, std::shared_ptr<DXCT::DInput::DInputFactory>);
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
};

    
}}
#endif