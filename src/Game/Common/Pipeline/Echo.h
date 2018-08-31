//
//		ƒtƒ@ƒCƒ‹–¼:DefaultPipeline.h
//

#ifndef HEADER_ECHO_H
#define HEADER_ECHO_H

#include <memory>
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Pipeline/DefaultPipeline.h"
#include "../../../DXCT/D3D/D3DVertexShader.h"
#include "../../../DXCT/D3D/D3DPixelShader.h"

namespace Game { namespace Pipeline
{

class Echo :public GameEngine::Pipeline::DefaultPipeline
{
	private:
		std::shared_ptr<DXCT::D3D::D3DVertexShader> _vertexShader;
		std::shared_ptr<DXCT::D3D::D3DPixelShader>  _pixelShader;
		std::shared_ptr<DXCT::D3D::D3DVertexDeclaration> _vertexDeclaration;
		D3DXMATRIX _vp;
		D3DXVECTOR3 _position;
		D3DXVECTOR3 _direction;
		float _range;
	public:
		Echo();
		virtual void OnAttach		(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) override;
		virtual void OnDetach		(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) override;
		virtual void OnSetCamera	(std::shared_ptr<DXCT::D3D::D3DDevice> const& device, D3DXMATRIX const& view, D3DXMATRIX const & projection) override;
		virtual void BeforeScene	(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) override;
		virtual void BeforeRenderer	(std::shared_ptr<DXCT::D3D::D3DDevice> const& device, D3DXMATRIX const& world) override;
		virtual void AfterRenderer	(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) override;
		virtual void AfterScene		(std::shared_ptr<DXCT::D3D::D3DDevice> const& device) override;
		void SetRate(float rate);
		void SetSonar(D3DXVECTOR3 position, D3DXVECTOR3 direction);
		void SetRange(float range);
};

}
}
#endif