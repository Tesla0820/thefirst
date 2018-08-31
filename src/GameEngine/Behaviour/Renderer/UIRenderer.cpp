//
//		ファイル名:UIRenderer.cpp
//

#include "../../Environment.h"
#include "UIRenderer.h"

namespace GameEngine { namespace Behaviour
{

UIRenderer::UIRenderer()
{
	_color = D3DCOLOR_ARGB(255, 255, 255, 255);
	_transform = nullptr;
}

UIRenderer::UIRenderer(std::shared_ptr<Resource::Texture>&& texture)
	:_texture(std::move(texture))
{
	_color = D3DCOLOR_ARGB(255, 255, 255, 255);
	_transform = nullptr;
}

void UIRenderer::SetTexture(std::shared_ptr<Resource::Texture>&& texture)
{
	_texture = std::move(texture);
}

void UIRenderer::SetColor(D3DCOLOR color)
{
	_color = color;
}

void UIRenderer::Start()
{
	_transform = GetAttachedObject()->GetTransform();
}

void UIRenderer::Draw(D3DXMATRIX const & matrix)
{
	auto device = GameEngine::Environment::Get()->GetCurrentDevice();
	device->ClearVertexShader();
	device->ClearPixelShader();
	device->ClearVertexDeclaration();
	device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				// カリングしない
	device->SetRenderState(D3DRS_ZENABLE, FALSE);						// Zバッファを使用しない
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// αブレンドを行う
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// αソースカラーの指定
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// αデスティネーションカラーの指定
	if (_texture) 
	{
		DrawTextured(device);
	}
	else
	{
		DrawColored(device);
	}

}

void UIRenderer::DrawTextured(std::shared_ptr<DXCT::D3D::D3DDevice>& device)
{
	struct
	{
		D3DXVECTOR3 position;
		float w;
		D3DCOLOR color;
		D3DXVECTOR2 uv;
	} rectTextured[4];

	D3DXVECTOR3 pos = _transform->GetPosition();
	D3DXVECTOR3 scale = _transform->GetScale();

	ZeroMemory(rectTextured, sizeof(rectTextured));
	for (int i = 0; i < 4; i++)
	{
		bool isRight = (i & 1);
		bool isBottom = (i >> 1 & 1);
		float x = (-0.5f + 1.0f*isRight) * scale.x + pos.x;
		float y = (-0.5f + 1.0f*isBottom) * scale.y + pos.y;

		rectTextured[i].position = D3DXVECTOR3(x, y, 0.0f);
		rectTextured[i].w = 1.0f;
		rectTextured[i].color = _color;
		rectTextured[i].uv = D3DXVECTOR2(isRight, isBottom);

	}
	device->SetTexture(0, _texture->Get());
	device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, rectTextured, sizeof(rectTextured[0]));
}

void UIRenderer::DrawColored(std::shared_ptr<DXCT::D3D::D3DDevice>& device)
{
	struct
	{
		D3DXVECTOR3 position;
		float w;
		D3DCOLOR color;
	}rectColored[4];
	
	D3DXVECTOR3 pos = _transform->GetPosition();
	D3DXVECTOR3 scale = _transform->GetScale();
	for (int i = 0; i < 4; i++)
	{
		bool isRight = (i & 1);
		bool isBottom = (i >> 1 & 1);
		float x = (-0.5f + 1.0f*isRight) * scale.x + pos.x;
		float y = (-0.5f + 1.0f*isBottom) * scale.y + pos.y;

		rectColored[i].position = D3DXVECTOR3(x, y, 0.0f);
		rectColored[i].w = 1.0f;
		rectColored[i].color = _color;
	}
	device->ClearTexture(0);
	device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, rectColored, sizeof(rectColored[0]));
}

}
}