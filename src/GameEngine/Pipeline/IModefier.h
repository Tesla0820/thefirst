//
//		�t�@�C����:IModefier.h
//

#ifndef HEADER_IMODEFIER_H
#define HEADER_IMODEFIER_H

#include "../GameEngine_inner.h"
#include "../../DXCT/D3D/D3DDevice.h"

namespace GameEngine { namespace Pipeline
{
struct IModefier
{
	virtual void OnAttach(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;																//�A�^�b�`���ꂽ�Ƃ��B
	virtual void OnDetach(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;																//�f�^�b�`���ꂽ�Ƃ��B
	virtual void OnSetCamera(std::shared_ptr<DXCT::D3D::D3DDevice> const& device, D3DXMATRIX const & view, D3DXMATRIX const & projection) = 0;	//�J������񂪃Z�b�g���ꂽ�Ƃ��B
	virtual void BeforeScene(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;															//BeginScene���O�ɌĂ΂�܂��B
	virtual void BeforeRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const& device, D3DXMATRIX const & world) = 0;								//�eRenderer�̕`��O�ɌĂ΂�܂��B
	virtual void AfterRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;														//�eRenderer�̕`���ɌĂ΂�܂��B
	virtual void AfterScene(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;															//AfterScene����ɌĂ΂�܂��B
	virtual ~IModefier() {};
};

}
}
#endif