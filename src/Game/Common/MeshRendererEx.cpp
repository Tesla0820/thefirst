//
//		ƒtƒ@ƒCƒ‹–¼:MeshRendererEx.cpp
//

#include "MeshRendererEx.h"
#include "Pipeline/Echo.h"
namespace Game
{

MeshRendererEx::MeshRendererEx()
{
	_rate = 0.0f;
}

void MeshRendererEx::Draw(D3DXMATRIX const & matrix)
{
	auto echo = dynamic_cast<Pipeline::Echo*>(GameEngine::Environment::Get()->GetCurrentPipeline());
	echo->SetRate(_rate);
	MeshRenderer::Draw(matrix);
}

void MeshRendererEx::SetRate(float rate)
{
    _rate = rate;
}

}
