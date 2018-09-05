#include "Echo.h"
namespace Game { namespace Pipeline
{

Echo::Echo()
{

}

void Echo::OnAttach(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
	SIZE screenSize=GameEngine::Environment::Get()->GetScreenSize();
	SIZE targetSize = { 1,1 };
	while (screenSize.cx > targetSize.cx || screenSize.cy > targetSize.cy)
	{
		targetSize.cx *= 2;
		targetSize.cy *= 2;
	}

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
	D3DXVECTOR3 lightVec(0.1f,1.0f,0.0f);
	float vec[4] = { _position.x,_position.y,_position.z,0.0f };
	float light[3] = { 0.0f,0.0f,0.0f};
	float effectAngle[4] = { 0.0f,0.0f,0.0f,1.0f };
	D3DXMATRIX wvp;
	_vertexShader->SetMatrix(device, "W", &world);
	D3DXMatrixMultiply(&wvp, &world, &_vp);
	_vertexShader->SetMatrix(device, "WVP", &wvp);
	D3DXVec3Normalize(&lightVec, &lightVec);
	for (int i = 0; i < 3; i++)
	{
		light[i] = lightVec[i];
		effectAngle[i] = _direction[i];
	}

	_vertexShader->SetFloatArray(device, "light", lightVec, 3);
	_pixelShader->SetFloatArray(device, "position", vec, 4);
	_pixelShader->SetFloat(device, "range", _range);
	_pixelShader->SetFloat(device, "weight", 256.0f);
	_pixelShader->SetFloatArray(device, "angle", effectAngle,4);
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

void Echo::SetRate(float rate)
{ 
	auto device = GameEngine::Environment::Get()->GetCurrentDevice();
	_vertexShader->SetFloat(device, "rate", rate);
}

void Echo::SetSonar(D3DXVECTOR3 position, D3DXVECTOR3 direction)
{
	_position = position;
	D3DXVec3Normalize(&_direction, &direction);
}

void Echo::SetRange(float range)
{
	_range = range;
}

}
}