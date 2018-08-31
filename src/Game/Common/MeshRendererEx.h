//
//		ƒtƒ@ƒCƒ‹–¼:MeshRendererEx.h
//

#ifndef HEADER_MESH_RENDERER_EX_H
#define HEADER_MESH_RENDERER_EX_H

#include "../../GameEngine/GameEngine.h"

namespace Game
{
	class MeshRendererEx: public GameEngine::Behaviour::MeshRenderer
	{
		private:
			float _rate;

		public:
			MeshRendererEx();
			virtual void Draw(D3DXMATRIX const& matrix) override;
            void SetRate(float rate);
	};
}

#endif