//
//		ƒtƒ@ƒCƒ‹–¼:DInputDevice.cpp
//

#include "DInputDevice.h"

namespace DXCT { namespace DInput
{

DInputDevice::DInputDevice(IDirectInputDevice8* device)
	:DXObject(device)
{

}

HRESULT DInputDevice::Acquire()
{
	return _object->Acquire();
}

HRESULT DInputDevice::GetCapabilities(DIDEVCAPS* deviceCaps)
{
	return _object->GetCapabilities(deviceCaps);
}

HRESULT DInputDevice::GetDeviceState(DWORD dataSize, void * data)
{
	return _object->GetDeviceState(dataSize, data);
}

HRESULT DInputDevice::Poll()
{
	return _object->Poll();
}

HRESULT DInputDevice::SetDataFormat(DIDATAFORMAT const * dataFormat)
{
	return _object->SetDataFormat(dataFormat);
}

HRESULT DInputDevice::SetCooperativeLevel(HWND windowHandle, DWORD flags)
{
	return _object->SetCooperativeLevel(windowHandle, flags);
}

HRESULT DInputDevice::SetProperty(GUID const & guidProp, DIPROPHEADER const * propHeader)
{
	return _object->SetProperty(guidProp, propHeader);
}

}
}