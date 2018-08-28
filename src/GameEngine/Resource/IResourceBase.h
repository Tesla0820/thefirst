//
//		ƒtƒ@ƒCƒ‹–¼:IResourceBase.h
//

#ifndef HEADER_IRESOURCE_BASE_H
#define HEADER_IRESOURCE_BASE_H

#include <string>

namespace GameEngine { namespace Resource
{

struct IResourceBase
{
	virtual std::string GetResourceType() = 0;
	virtual ~IResourceBase() { }
};

}
}
#endif