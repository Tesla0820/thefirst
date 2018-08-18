//
//		ÉtÉ@ÉCÉãñº:DefaultPipeline.h
//

#ifndef HEADER_DEFAULT_PIPELINE_H
#define HEADER_DEFAULT_PIPELINE_H

#include "../GameEngine_inner.h"
#include "IModefier.h"

namespace GameEngine { namespace Pipeline
{

class DefaultPipeline :public IModefier
{
	// IModefier ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ	
	
	virtual void OnAttach(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) override;
	virtual void OnDetach(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) override;
	virtual void OnSetCamera(std::shared_ptr<DXCT::D3D::D3DDevice> const & device, D3DXMATRIX const & view, D3DXMATRIX const & projection) override;
	virtual void BeforeScene(std::shared_ptr<DXCT::D3D::D3DDevice> const & device) override;
	virtual void BeforeRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const & device, D3DXMATRIX const & world) override;
	virtual void AfterRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const & device) override;
	virtual void AfterScene(std::shared_ptr<DXCT::D3D::D3DDevice> const & device) override;

};

}
}
#endif