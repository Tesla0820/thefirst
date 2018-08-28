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

	public:
		UIRenderer(std::shared_ptr<Resource::Texture>&& texture);
		void SetTexture(std::shared_ptr<Resource::Texture>&& texture);
		virtual void Start() override;
		virtual void Draw(D3DXMATRIX const& matrix) override;

};

}
}
#endif