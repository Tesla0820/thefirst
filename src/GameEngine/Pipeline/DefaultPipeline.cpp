#include "DefaultPipeline.h"
namespace GameEngine { namespace Pipeline
{

void DefaultPipeline::OnAttach(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
	
}

void DefaultPipeline::OnDetach(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{

}

void DefaultPipeline::OnSetCamera(std::shared_ptr<DXCT::D3D::D3DDevice> const & device, D3DXMATRIX const & view, D3DXMATRIX const & projection)
{
}

void DefaultPipeline::BeforeScene(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{

	// レンダーステートパラメータの設定
	device->SetRenderState(D3DRS_AMBIENT,D3DCOLOR_ARGB(255,32,32,32));	// 画面を少し明るく
	device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// カリングしない
	device->SetRenderState(D3DRS_ZENABLE, TRUE);						// Zバッファを使用しない
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// αブレンドを行う
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// αソースカラーの指定
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// αデスティネーションカラーの指定

	// サンプラーステートパラメータの設定
	device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);		// テクスチャアドレッシング方法(U値)を設定
	device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);		// テクスチャアドレッシング方法(V値)を設定
	device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);		// テクスチャ縮小フィルタモードを設定
	device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);		// テクスチャ拡大フィルタモードを設定

	// テクスチャステージステートの設定
	device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	// アルファブレンディング処理
	device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);	// 最初のアルファ引数
	device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);	// ２番目のアルファ引数
	
	//ライティングの設定
	device->SetRenderState(D3DRS_LIGHTING, FALSE);						
}

void DefaultPipeline::BeforeRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const & device, D3DXMATRIX const & world)
{
}

void DefaultPipeline::AfterRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
}

void DefaultPipeline::AfterScene(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
}

}
}