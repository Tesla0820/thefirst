//
//		ƒtƒ@ƒCƒ‹–¼:IRenderer.h
//

#ifndef HEADER_IRENDERER_H
#define HEADER_IRENDERER_H

#include "GameEngine_inner.h"

namespace GameEngine
{
	struct IRenderer
	{
		virtual void Draw(D3DMATRIX const &matrix) = 0;
		virtual ~IRenderer() = 0;
	};
}
#endif