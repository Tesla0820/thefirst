//
//		ƒtƒ@ƒCƒ‹–¼:MeshRenderer.h
//

#ifndef HEADER_MESH_RENDERER_H
#define HEADER_MESH_RENDERER_H

#include <vector>

#include "RendererBase.h"
#include "../../Mesh.h"

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
		std::shared_ptr<Mesh> _mesh;

	public:
		void SetMesh(std::shared_ptr<Mesh> _mesh);
		virtual void Draw(D3DXMATRIX const& matrix) override;

		
};

}
}
#endif