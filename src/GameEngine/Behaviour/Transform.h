//
//		ƒtƒ@ƒCƒ‹–¼:Transform.h
//

#ifndef HEADER_TRANSFORM_H
#define HEADER_TRANSFORM_H

#include "../GameEngine_inner.h"
#include "Behaviour.h"

namespace GameEngine { namespace Behaviour
{
class Transform:public Behaviour
{
	private:
		D3DXVECTOR3 _position;
		D3DXVECTOR3 _scale;
		D3DXQUATERNION _rotation;

	public:
		Transform();
		virtual ~Transform();
		void SetPosition(D3DXVECTOR3 const* position);
		void SetScale(D3DXVECTOR3 const* scale);
		void SetRotation(D3DXQUATERNION const* rotation);
		D3DXVECTOR3 GetPosition();
		D3DXVECTOR3 GetWorldPosition();
		D3DXVECTOR3 GetScale();
		D3DXVECTOR3 Up();
		D3DXVECTOR3 Down();
		D3DXVECTOR3 Left();
		D3DXVECTOR3 Right();
		D3DXVECTOR3 Front();
		D3DXVECTOR3 Back();
		D3DXVECTOR3 CalcDirection(D3DXVECTOR3 const* direction);
		D3DXQUATERNION GetRotation();
		D3DXMATRIX GetMatrix();
		D3DXMATRIX GetWorldMatrix();
		void Offset(D3DXVECTOR3 const* position);
};

}
}
#endif