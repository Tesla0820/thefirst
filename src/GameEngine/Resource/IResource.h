//
//		ƒtƒ@ƒCƒ‹–¼:IResource.h
//

#ifndef HEADER_IRESOURCE_H
#define HEADER_IRESOURCE_H

#include <memory>
#include "IResourceBase.h"

namespace GameEngine { namespace Resource
{

template<class T>
struct IResource : public IResourceBase
{
	using get_result = std::shared_ptr<T>;
	virtual get_result Get() = 0;
	virtual ~IResource() { }
};

}
}
#endif