//
//		ファイル名:D3DDevice.h
//

#ifndef HEADER_D3DDEVICE_H
#define HEADER_D3DDEVICE_H

#include <memory>
#include "../dxct_inner.h"
#include "D3DObject.h"
#include "D3DTexture.h"
#include "D3DSurface.h"
#include "D3DVertexBuffer.h"
#include "D3DVertexShader.h"
#include "D3DPixelShader.h"
#include "D3DVertexDeclaration.h"

namespace DXCT{ namespace D3D
{

//IDirect3DDevice9のラッパークラスです。
class D3DDevice:public D3DObject<IDirect3DDevice9>
{
	private:
		D3DDevice() = delete;
	
	protected:
		virtual void Recovery(IRecoverable * origin) override;

	public:
		D3DDevice(IDirect3DDevice9 *device);
		HRESULT	ClearTexture(DWORD stage);
		HRESULT	ClearVertexShader();
		HRESULT ClearVertexDeclaration();
		HRESULT	ClearPixelShader();
		std::shared_ptr<D3DTexture>	CreateTexture(UINT Width, UINT height, UINT levels, DWORD usage, D3DFORMAT format, D3DPOOL pool, HANDLE* pHandle = nullptr);
		std::shared_ptr<D3DTexture>	CreateTextureFromFile(LPCTSTR path);
		std::shared_ptr<D3DVertexBuffer> CreateVertexBuffer(UINT length, DWORD usage, DWORD FVF, D3DPOOL pool, HANDLE* pHandle = nullptr);
		std::shared_ptr<D3DVertexShader> CreateVertexShaderFromFile(LPCTSTR sourceFile, D3DXMACRO const* defines, ID3DXInclude* include, LPCSTR functionName);
		std::shared_ptr<D3DVertexDeclaration> CreateVertexDeclaration(D3DVERTEXELEMENT9 const* vertexElements);
		std::shared_ptr<D3DPixelShader>	CreatePixelShaderFromFile(LPCTSTR sourceFile, D3DXMACRO const* defines, ID3DXInclude* include, LPCSTR functionName);
		HRESULT	LightEnable(DWORD lightIndex,BOOL enable);
		HRESULT	SetFVF(DWORD FVF);
		HRESULT	SetLight(DWORD index, D3DLIGHT9 const* light);
		HRESULT	SetMaterial(D3DMATERIAL9 const* material);
		HRESULT	SetRenderState(D3DRENDERSTATETYPE type, DWORD value);
		HRESULT	SetRenderTarget(DWORD renderTargetIndex, std::shared_ptr<D3DSurface> &surface);
		HRESULT	SetSamplerState(DWORD sampler, D3DSAMPLERSTATETYPE type, DWORD value);
		HRESULT	SetTexture(DWORD stage, std::shared_ptr<D3DTexture> const& texture);
		HRESULT	SetTransform(D3DTRANSFORMSTATETYPE state, D3DMATRIX const* pMatrix);
		HRESULT	SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value);
		HRESULT	SetVertexShader(std::shared_ptr<D3DVertexShader> const& shader);
		HRESULT SetVertexDeclaration(std::shared_ptr<D3DVertexDeclaration> const& vertexDeclaration);
		HRESULT	SetPixelShader(std::shared_ptr<D3DPixelShader> const& shader);
		HRESULT	Clear(DWORD count, D3DRECT const* rects, DWORD flags, D3DCOLOR color, float z, DWORD stencil);
		HRESULT	ColorFill(std::shared_ptr<D3DSurface> &surface,RECT const* pRect,D3DCOLOR color);
		HRESULT	BeginScene();
		HRESULT	EndScene();
		HRESULT	Present(RECT const* sourceRect, RECT const* destRect, HWND destWindowOverride, RGNDATA const* dirtyRegion);
		HRESULT	DrawPrimitiveUP(D3DPRIMITIVETYPE type, UINT primitiveCount, void* verticies, UINT vertexStride);
};

}
}

#endif