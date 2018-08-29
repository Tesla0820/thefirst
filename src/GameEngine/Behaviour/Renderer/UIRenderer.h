//
//		ƒtƒ@ƒCƒ‹–¼:UIRenderer.h
//

#ifndef HEADER_UIRENDERER_H
#define HEADER_UIRENDERER_H

#include "../../Resource/Texture.h"
#include "../Transform.h"
#include "RendererBase.h"

namespace GameEngine { namespace Behaviour
{

class UIRenderer : public RendererBase
{
	private:
		Transform* _transform;
		std::shared_ptr<Resource::Texture> _texture;
		D3DCOLOR _color;
	public:
		UIRenderer();
		UIRenderer(std::shared_ptr<Resource::Texture>&& texture);
		
		void SetTexture(std::shared_ptr<Resource::Texture>&& texture);
		void SetColor(D3DCOLOR color);
		virtual void Start() override;
		virtual void Draw(D3DXMATRIX const& matrix) override;
		void DrawTextured(std::shared_ptr<DXCT::D3D::D3DDevice>& device);
		void DrawColored(std::shared_ptr<DXCT::D3D::D3DDevice>& device);

};

}
}
#endif