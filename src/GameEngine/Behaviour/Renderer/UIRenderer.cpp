//
//		ƒtƒ@ƒCƒ‹–¼:UIRenderer.cpp
//

#include "../../Environment.h"
#include "UIRenderer.h"

namespace GameEngine { namespace Behaviour
{

UIRenderer::UIRenderer(std::shared_ptr<Resource::Texture>&& texture)
	:_texture(std::move(texture))
{
	_transform = nullptr;
}
void UIRenderer::SetTexture(std::shared_ptr<Resource::Texture>&& texture)
{
	_texture = std::move(texture);
}

void UIRenderer::Start()
{
	_transform = GetAttachedObject()->GetTransform();
}

void UIRenderer::Draw(D3DXMATRIX const & matrix)
{
	struct 
	{
		D3DXVECTOR3 position;
		float w;
		float u;
		float v;
	} rect[4];

	D3DXVECTOR3 pos = _transform->GetPosition();
	D3DXVECTOR3 scale = _transform->GetScale();

	ZeroMemory(rect,sizeof(rect));
	for(int i=0;i<4;i++)
	{
		bool isRight	= (i		& 1);
		bool isBottom	= (i >> 1	& 1);
		float x = (-0.5f + 1.0f*isRight	) * scale.x + pos.x;
		float y = (-0.5f + 1.0f*isBottom) * scale.y + pos.y;
		rect[i].position	= D3DXVECTOR3(x, y, 0.0f);
		rect[i].w			= 1.0f;
		//rect[i].uv			= D3DXVECTOR2(isRight,isBottom);
		rect[i].u = isRight;
		rect[i].v = isBottom;
	}

	auto device = GameEngine::Environment::Get()->GetCurrentDevice();
	device->ClearVertexShader();
	device->ClearPixelShader();
	device->ClearVertexDeclaration();
	device->SetTexture(0, _texture->Get());
	device->SetTransform(D3DTS_WORLD, &matrix);
	device->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, rect, sizeof(rect[0]));
}

}
}