//
//		ファイル名:IModefier.h
//

#ifndef HEADER_IMODEFIER_H
#define HEADER_IMODEFIER_H

#include "../GameEngine_inner.h"
#include "../../DXCT/D3D/D3DDevice.h"

namespace GameEngine { namespace Pipeline
{
struct IModefier
{
	virtual void OnAttach(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;																//アタッチされたとき。
	virtual void OnDetach(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;																//デタッチされたとき。
	virtual void OnSetCamera(std::shared_ptr<DXCT::D3D::D3DDevice> const& device, D3DXMATRIX const & view, D3DXMATRIX const & projection) = 0;	//カメラ情報がセットされたとき。
	virtual void BeforeScene(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;															//BeginSceneより前に呼ばれます。
	virtual void BeforeRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const& device, D3DXMATRIX const & world) = 0;								//各Rendererの描画前に呼ばれます。
	virtual void AfterRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;														//各Rendererの描画後に呼ばれます。
	virtual void AfterScene(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) = 0;															//AfterSceneより後に呼ばれます。
	virtual ~IModefier() {};
};

}
}
#endif