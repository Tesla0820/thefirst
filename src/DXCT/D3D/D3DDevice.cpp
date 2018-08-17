//
//		ファイル名:D3DDevice.cpp
//

#include "D3DDevice.h"
#include <exception>
#include <memory>

namespace DXCT { namespace D3D
{

D3DDevice::D3DDevice(IDirect3DDevice9* device)
	: D3DObject(device)
{

}

HRESULT D3DDevice::ClearTexture(DWORD stage)
{
	return _object->SetTexture(stage, nullptr);
}

std::shared_ptr<D3DTexture> D3DDevice::CreateTexture(UINT width, UINT height, UINT levels, DWORD usage, D3DFORMAT format, D3DPOOL pool, HANDLE * pHandle)
{
	HRESULT hr;
	IDirect3DTexture9* _texture;
	hr = _object->CreateTexture(width, height, levels, usage, format, pool, &_texture, pHandle);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<D3DTexture>(new D3DTexture(_texture));
	}
	return std::shared_ptr<D3DTexture>();
}

//D3DXを通して、ファイルからテクスチャを生成します。
std::shared_ptr<D3DTexture> D3DDevice::CreateTextureFromFile(LPCTSTR path)
{
	HRESULT hr;
	IDirect3DTexture9 *_texture;
	hr = D3DXCreateTextureFromFile(_object, path, &_texture);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<D3DTexture>(new D3DTexture(_texture));
	}
	throw std::runtime_error("ファイルが存在しません。");
}

std::shared_ptr<D3DVertexBuffer> D3DDevice::CreateVertexBuffer(UINT length, DWORD usage, DWORD FVF, D3DPOOL pool, HANDLE * pHandle)
{
	HRESULT hr;
	IDirect3DVertexBuffer9 *_vertexBuffer;
	hr = _object->CreateVertexBuffer(length, usage, FVF, pool, &_vertexBuffer, pHandle);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<D3DVertexBuffer>(new D3DVertexBuffer(_vertexBuffer));
	}
	return std::shared_ptr<D3DVertexBuffer>();
}

std::shared_ptr<D3DVertexShader> D3DDevice::CreateVertexShaderFromFile(LPCTSTR sourceFile, D3DXMACRO const * defines, ID3DXInclude * include, LPCSTR functionName)
{
	HRESULT hr;
	ID3DXBuffer* shader;
	ID3DXBuffer* errorMessage;
	ID3DXConstantTable* table;
	IDirect3DVertexShader9* vertexShader;
	DWORD flags = 0;
#ifdef _DEBUG
	flags = D3DXSHADER_DEBUG | D3DXSHADER_SKIPOPTIMIZATION;
#endif
	hr = D3DXCompileShaderFromFile(sourceFile, defines, include, functionName, "vs_3_0", flags, &shader, &errorMessage, &table);
	if (errorMessage)
	{
		char *ErrorMessage = (char *)errorMessage->GetBufferPointer();
		DWORD ErrorLength = errorMessage->GetBufferSize();
		char *message = new char[ErrorLength+1];
		ZeroMemory(message, ErrorLength + 1);
		strncpy(message, ErrorMessage, ErrorLength);
		SAFE_RELEASE(errorMessage);
		throw(std::runtime_error(std::move(message)));
		
	}
	auto temp = (DWORD*)shader->GetBufferPointer();
	_object->CreateVertexShader(reinterpret_cast<DWORD*>(shader->GetBufferPointer()), &vertexShader);//コンパイルに成功したのでVertexShaderを作る
	SAFE_RELEASE(shader);
	SAFE_RELEASE(errorMessage);

	return std::shared_ptr<D3DVertexShader>(new D3DVertexShader(vertexShader, std::unique_ptr<D3DX::D3DXConstantTable>(new D3DX::D3DXConstantTable(table))));
}

std::shared_ptr<D3DVertexDeclaration> D3DDevice::CreateVertexDeclaration(D3DVERTEXELEMENT9 const * vertexElements)
{
	HRESULT hr;
	IDirect3DVertexDeclaration9* vertexDeclaration;
	hr = _object->CreateVertexDeclaration(vertexElements, &vertexDeclaration);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<D3DVertexDeclaration>(new D3DVertexDeclaration(vertexDeclaration));
	}
	return std::shared_ptr<D3DVertexDeclaration>();
}

std::shared_ptr<D3DPixelShader> D3DDevice::CreatePixelShaderFromFile(LPCTSTR sourceFile, D3DXMACRO const * defines, ID3DXInclude * include, LPCSTR functionName)
{
	HRESULT hr;
	ID3DXBuffer* shader;
	ID3DXBuffer* errorMessage;
	ID3DXConstantTable* table;
	IDirect3DPixelShader9* pixelShader;
	DWORD flags = 0;
#ifdef _DEBUG
	flags = D3DXSHADER_DEBUG | D3DXSHADER_SKIPOPTIMIZATION;
#endif
	hr = D3DXCompileShaderFromFile(sourceFile, defines, include, functionName, "ps_3_0", flags, &shader, &errorMessage, &table);
	if (errorMessage)
	{
		char *ErrorMessage = (char *)errorMessage->GetBufferPointer();
		DWORD ErrorLength = errorMessage->GetBufferSize();
		char *message = new char[ErrorLength + 1];
		ZeroMemory(message, ErrorLength + 1);
		strncpy(message, ErrorMessage, ErrorLength);
		SAFE_RELEASE(errorMessage);
		throw(std::runtime_error(std::move(message)));
	}

	_object->CreatePixelShader(reinterpret_cast<DWORD*>(shader->GetBufferPointer()), &pixelShader);//コンパイルに成功したのでVertexShaderを作る
	SAFE_RELEASE(shader);
	SAFE_RELEASE(errorMessage);

	return std::shared_ptr<D3DPixelShader>(new D3DPixelShader(pixelShader, std::unique_ptr<D3DX::D3DXConstantTable>(new D3DX::D3DXConstantTable(table))));
}

HRESULT D3DDevice::LightEnable(DWORD lightIndex, BOOL enable)
{
	return _object->LightEnable(lightIndex, enable);
}

HRESULT D3DDevice::SetLight(DWORD index, D3DLIGHT9 const *light)
{
	return _object->SetLight(index, light);
}

//レンダーステートを設定します。
HRESULT D3DDevice::SetRenderState(D3DRENDERSTATETYPE type,DWORD value)
{
	return _object->SetRenderState(type, value);
}

HRESULT D3DDevice::SetRenderTarget(DWORD renderTargetIndex, std::shared_ptr<D3DSurface>& surface)
{
	return _object->SetRenderTarget(renderTargetIndex, surface->GetPtr());
}

//サンプラーステートを設定します。
HRESULT D3DDevice::SetSamplerState(DWORD sampler,D3DSAMPLERSTATETYPE type,DWORD value)
{
	return _object->SetSamplerState(sampler, type, value);
}

HRESULT D3DDevice::SetMaterial(D3DMATERIAL9 const * material)
{
	return _object->SetMaterial(material);
}

//テクスチャステージを設定します。
HRESULT D3DDevice::SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value)
{
	return _object->SetTextureStageState(stage, type, value);
}

HRESULT D3DDevice::ClearVertexShader()
{
	return _object->SetVertexShader(nullptr);
}

HRESULT D3DDevice::ClearVertexDeclaration()
{
	return _object->SetVertexDeclaration(nullptr);
}

HRESULT D3DDevice::ClearPixelShader()
{
	return _object->SetPixelShader(nullptr);
}

HRESULT D3DDevice::SetVertexShader(std::shared_ptr<D3DVertexShader> const& shader)
{
	return _object->SetVertexShader(shader->GetPtr());
}

HRESULT D3DDevice::SetVertexDeclaration(std::shared_ptr<D3DVertexDeclaration> const & vertexDeclaration)
{
	return _object->SetVertexDeclaration(vertexDeclaration->GetPtr());
}

HRESULT D3DDevice::SetPixelShader(std::shared_ptr<D3DPixelShader> const & shader)
{
	return _object->SetPixelShader(shader->GetPtr());
}

//描画内容をクリアします。
HRESULT D3DDevice::Clear(DWORD count,D3DRECT const* rects,DWORD flags,D3DCOLOR color,float z,DWORD stencil)
{
	return _object->Clear(count, rects, flags, color, z, stencil);
}

HRESULT D3DDevice::ColorFill(std::shared_ptr<D3DSurface>& surface, RECT const * pRect, D3DCOLOR color)
{
	return _object->ColorFill(surface->GetPtr(), pRect, color);
}

//シーンの描画を開始します。
HRESULT D3DDevice::BeginScene()
{
	return _object->BeginScene();
}

//シーンの描画を終了します。
HRESULT D3DDevice::EndScene()
{
	return _object->EndScene();
}

//描画内容を画面に出力します。
HRESULT D3DDevice::Present(RECT const* sourceRect,RECT const* destRect,HWND destWindowOverride,RGNDATA const* dirtyRegion)
{
	return _object->Present(sourceRect, destRect, destWindowOverride, dirtyRegion);
}

//FVF頂点情報を設定します。
HRESULT D3DDevice::SetFVF(DWORD FVF)
{
	return _object->SetFVF(FVF);
}

//テクスチャを設定します。
HRESULT D3DDevice::SetTexture(DWORD stage, std::shared_ptr<D3DTexture> const &texture)
{
	return _object->SetTexture(stage,texture->GetPtr());
}

//行列を設定します。
HRESULT D3DDevice::SetTransform(D3DTRANSFORMSTATETYPE state, D3DMATRIX const * pMatrix)
{
	return _object->SetTransform(state, pMatrix);
}

//ユーザーポインタを利用して描画します。
HRESULT D3DDevice::DrawPrimitiveUP(D3DPRIMITIVETYPE type, UINT primitiveCount, void * verticies, UINT vertexStride)
{
	return _object->DrawPrimitiveUP(type, primitiveCount, verticies, vertexStride);
}

//デバイスロストから復帰します。
void D3DDevice::Recovery(IRecoverable * origin)
{
	D3DObject::Recovery(origin);
}

}
}
