//
//		�t�@�C����:D3DDevice.cpp
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

//D3DX��ʂ��āA�t�@�C������e�N�X�`���𐶐����܂��B
std::shared_ptr<D3DTexture> D3DDevice::CreateTextureFromFile(LPCTSTR path)
{
	HRESULT hr;
	IDirect3DTexture9* _texture;
	hr = D3DXCreateTextureFromFile(_object, path, &_texture);
	if (SUCCEEDED(hr))
	{
		return std::shared_ptr<D3DTexture>(new D3DTexture(_texture));
	}
	throw std::runtime_error("�t�@�C�������݂��܂���B");
}

//�����_�[�X�e�[�g��ݒ肵�܂��B
HRESULT D3DDevice::SetRenderState(D3DRENDERSTATETYPE type,DWORD value)
{
	return _object->SetRenderState(type, value);
}

HRESULT D3DDevice::SetRenderTarget(DWORD renderTargetIndex, std::shared_ptr<D3DSurface>& surface)
{
	return _object->SetRenderTarget(renderTargetIndex, surface->GetPtr());
}

//�T���v���[�X�e�[�g��ݒ肵�܂��B
HRESULT D3DDevice::SetSamplerState(DWORD sampler,D3DSAMPLERSTATETYPE type,DWORD value)
{
	return _object->SetSamplerState(sampler, type, value);
}

//�e�N�X�`���X�e�[�W��ݒ肵�܂��B
HRESULT D3DDevice::SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value)
{
	return _object->SetTextureStageState(stage, type, value);
}

//�`����e���N���A���܂��B
HRESULT D3DDevice::Clear(DWORD count,D3DRECT const* rects,DWORD flags,D3DCOLOR color,float z,DWORD stencil)
{
	return _object->Clear(count, rects, flags, color, z, stencil);
}

HRESULT D3DDevice::ColorFill(std::shared_ptr<D3DSurface>& surface, RECT const * pRect, D3DCOLOR color)
{
	return _object->ColorFill(surface->GetPtr(), pRect, color);
}

//�V�[���̕`����J�n���܂��B
HRESULT D3DDevice::BeginScene()
{
	return _object->BeginScene();
}

//�V�[���̕`����I�����܂��B
HRESULT D3DDevice::EndScene()
{
	return _object->EndScene();
}

//�`����e����ʂɏo�͂��܂��B
HRESULT D3DDevice::Present(RECT const* sourceRect,RECT const* destRect,HWND destWindowOverride,RGNDATA const* dirtyRegion)
{
	return _object->Present(sourceRect, destRect, destWindowOverride, dirtyRegion);
}

//FVF���_����ݒ肵�܂��B
HRESULT D3DDevice::SetFVF(DWORD FVF)
{
	return _object->SetFVF(FVF);
}

//�e�N�X�`����ݒ肵�܂��B
HRESULT D3DDevice::SetTexture(DWORD stage, std::shared_ptr<D3DTexture> const &texture)
{
	return _object->SetTexture(stage,texture->GetPtr());
}

//�s���ݒ肵�܂��B
HRESULT D3DDevice::SetTransform(D3DTRANSFORMSTATETYPE state, D3DMATRIX const * pMatrix)
{
	return _object->SetTransform(state, pMatrix);
}

//���[�U�[�|�C���^�𗘗p���ĕ`�悵�܂��B
HRESULT D3DDevice::DrawPrimitiveUP(D3DPRIMITIVETYPE type, UINT primitiveCount, void * verticies, UINT vertexStride)
{
	return _object->DrawPrimitiveUP(type, primitiveCount, verticies, vertexStride);
}

//�f�o�C�X���X�g���畜�A���܂��B
void D3DDevice::Recovery(IRecoverable * origin)
{
	D3DObject::Recovery(origin);
}

}
}
