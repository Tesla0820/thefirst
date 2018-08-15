//
//		ƒtƒ@ƒCƒ‹–¼:DInputFactory.h
//

#ifndef HEADER_DINPUT_FACTORY_H
#define HEADER_DINPUT_FACTORY_H

#include <vector>
#include <memory>
#include "../dxct_inner.h"
#include "../DXObject.h"
#include "DInputDevice.h"

namespace DXCT { namespace DInput
{



class DInputFactory:public DXObject<IDirectInput8>
{
	private:
		DInputFactory() = delete;
		DInputFactory(IDirectInput8* factory);
	public:
		using EnumDeviceCallBack = std::function<int(DInputFactory*, DIDEVICEINSTANCE const*, void*)>;

		~DInputFactory();
		std::shared_ptr<DInputDevice> CreateDevice(GUID const& guid,IUnknown* unknownOuter);
		HRESULT DInputFactory::EnumDevices(DWORD deviceType, EnumDeviceCallBack * callback, void* reference, DWORD flags);

		static std::shared_ptr<DInputFactory> Create();
		static int CALLBACK EnumDeviceCallBackBase(DIDEVICEINSTANCE const* instance, void* reference);

};

}
}
#endif