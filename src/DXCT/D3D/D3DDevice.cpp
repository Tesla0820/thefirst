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

//テクスチャステージを設定します。
HRESULT D3DDevice::SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value)
{
	return _object->SetTextureStageState(stage, type, value);
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
