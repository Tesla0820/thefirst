//
//		ƒtƒ@ƒCƒ‹–¼:MeshRenderer.h
//

#ifndef HEADER_MESH_RENDERER_H
#define HEADER_MESH_RENDERER_H

#include <vector>

#include "RendererBase.h"
#include "../../Resource/Mesh/IMesh.h"

namespace GameEngine { namespace Behaviour
{

class MeshRenderer : public RendererBase
{
	private:
		std::shared_ptr<Resource::Mesh::IMesh> _mesh;

	public:
		MeshRenderer() =default;
		void SetMesh(std::shared_ptr<Resource::Mesh::IMesh> _mesh);
		virtual void Draw(D3DXMATRIX const& matrix) override;

		
};

}
}
#endif