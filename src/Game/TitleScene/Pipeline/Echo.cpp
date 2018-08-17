#include "Echo.h"
namespace Game { namespace Pipeline
{

Echo::Echo()
{

}

void Echo::OnAttach(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
	D3DVERTEXELEMENT9 elements[] = 
	{
		{ 0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		{ 0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0 },
		D3DDECL_END()
	};
	_vertexShader = device->CreateVertexShaderFromFile(TEXT("./data/shader/vs.fx"), NULL, NULL, "vertex");
	_pixelShader = device->CreatePixelShaderFromFile(TEXT("./data/shader/ps.fx"), NULL, NULL, "pixel");
	_vertexDeclaration = device->CreateVertexDeclaration(elements);
}

void Echo::OnDetach(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
}

void Echo::OnSetCamera(std::shared_ptr<DXCT::D3D::D3DDevice> const & device, D3DXMATRIX const & view, D3DXMATRIX const & projection)
{
	D3DXMATRIX temp;
	D3DXMatrixMultiply(&_vp, &view, &projection);
}

void Echo::BeforeScene(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
	
}

void Echo::BeforeRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const & device, D3DXMATRIX const& world)
{
	float vec[4] = { 0.0f,0.0f,0.0f,0.0f };
	D3DXMATRIX wvp;
	_vertexShader->SetMatrix(device, "W", &world);
	D3DXMatrixMultiply(&wvp, &world, &_vp);
	_vertexShader->SetMatrix(device, "WVP", &wvp);
	_pixelShader->SetFloatArray(device, "position", vec,4);
	_pixelShader->SetFloat(device, "range", 11.0f);
	_pixelShader->SetFloat(device, "weight", 0.0625f);
	device->SetVertexShader(_vertexShader);
	device->SetPixelShader(_pixelShader);
	device->SetVertexDeclaration(_vertexDeclaration);
	
}

void Echo::AfterRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
	device->ClearVertexDeclaration();
}

void Echo::AfterScene(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{

}

}
}