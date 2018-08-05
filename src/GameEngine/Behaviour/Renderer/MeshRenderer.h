//
//		ƒtƒ@ƒCƒ‹–¼:MeshRenderer.h
//

#ifndef HEADER_MESH_RENDERER_H
#define HEADER_MESH_RENDERER_H

#include <vector>

#include "RendererBase.h"

namespace GameEngine { namespace Behaviour
{

struct Vertex
{
	D3DVECTOR pos;
	D3DVECTOR normal;
	D3DCOLOR color;
};


class MeshRenderer : public RendererBase
{
	private:
	D3DPRIMITIVETYPE _primitiveType;
	Vertex vertex[3];

	public:
		virtual void Draw(D3DXMATRIX const& matrix) override;
		void CalculateNormals();
};

}
}
#endif