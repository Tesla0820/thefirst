//
//		ƒtƒ@ƒCƒ‹–¼:IMesh.h
//

#ifndef HEADER_IMESH_H
#define HEADER_IMESH_H
#include "../../GameEngine_inner.h"

namespace GameEngine { namespace Resource { namespace Mesh
{
	struct IMesh
	{
		virtual void Setup() = 0;
		virtual void Draw() = 0;
		virtual ~IMesh() {};
	};
}
}
}
#endif