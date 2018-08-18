//
//		ƒtƒ@ƒCƒ‹–¼:DInputFactory.cpp
//

#include "DInputFactory.h"

namespace DXCT { namespace DInput
{

DInputFactory::DInputFactory(IDirectInput8* factory)
	:DXObject(factory)
{
}

DInputFactory::~DInputFactory()
{
}

std::shared_ptr<DInputDevice> DInputFactory::CreateDevice(GUID const & guid, IUnknown* unknownOuter)
{
	HRESULT hr;
	IDirectInputDevice8* device;
	hr = _object->CreateDevice(guid, &device, unknownOuter);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<DInputDevice>(new DInputDevice(device));
	}
	return std::shared_ptr<DInputDevice>();
}

HRESULT DInputFactory::EnumDevices(DWORD deviceType, EnumDeviceCallBack callback,void* reference, DWORD flags)
{
	std::tuple<EnumDeviceCallBack*, DInputFactory*, void*> tuple = std::make_tuple(&callback, this, reference);
	return _object->EnumDevices(deviceType, EnumDeviceCallBackBase, reinterpret_cast<void*>(&tuple), flags);
}

std::shared_ptr<DInputFactory> DInputFactory::Create()
{
	HRESULT hr;
	IDirectInput8* factory;
	hr = ::DirectInput8Create(::GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, reinterpret_cast<void**>(&factory), nullptr);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<DInputFactory>(new DInputFactory(factory));
	}
	return std::shared_ptr<DInputFactory>();
}



int CALLBACK DInputFactory::EnumDeviceCallBackBase(DIDEVICEINSTANCE const* instance, void* reference)
{
	auto tuple = reinterpret_cast<std::tuple<EnumDeviceCallBack*, DInputFactory*, void*>*>(reference);
	return (*(std::get<0>(*tuple)))(std::get<1>(*tuple),instance, std::get<2>(*tuple));
}

}
}