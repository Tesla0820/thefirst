//
//		ƒtƒ@ƒCƒ‹–¼:DInputDevice.h
//

#ifndef HEADER_DINPUT_H
#define HEADER_DINPUT_H

#include <functional>
#include "../dxct_inner.h"
#include "../DXObject.h"
namespace DXCT { namespace DInput
{

class DInputDevice : public DXObject<IDirectInputDevice8>
{
	private:

	public:
		DInputDevice(IDirectInputDevice8* device);
		HRESULT Acquire();
		HRESULT GetCapabilities(DIDEVCAPS* deviceCaps);
		HRESULT GetDeviceState(DWORD dataSize,void* data);
		HRESULT Poll();
		HRESULT SetDataFormat(DIDATAFORMAT const* dataFormat);
		HRESULT SetCooperativeLevel(HWND windowHandle, DWORD flags);
		HRESULT SetProperty(GUID const& guidProp, DIPROPHEADER const* propHeader);
};

}
}
#endif