//
//		ƒtƒ@ƒCƒ‹–¼:Vertex.h
//

#ifndef HEADER_VERTEX_H
#define HEADER_VERTEX_H

#include "GameEngine_inner.h"

namespace GameEngine
{
	constexpr DWORD FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;

	struct Vertex
	{
		D3DVECTOR pos;
		float rhw;
		D3DCOLOR color;
		float u;
		float v;
	};
}
#endif