// BoxCollider.h

#ifndef HEADER_BOX_COLLIDER_H 
#define HEADER_BOX_COLLIDER_H

#include <vector>
#include "../../GameEngine_inner.h"
#include "Collider.h"
#include "SphereCollider.h"

class SphereCollider;

namespace GameEngine { namespace Behaviour
{

//�����̂̔�����s���N���X�ł��B
class BoxCollider :public Collider
{
private:
	D3DXVECTOR3 _position;		// ���W
	D3DXVECTOR3 _scale;			// �傫��

public:
	BoxCollider(D3DXVECTOR3 positon, D3DXVECTOR3 scale);
	virtual ~BoxCollider();
	D3DXVECTOR3* GetScale();
	virtual void Hit() override;
	void HitToSphere(SphereCollider* collider);
	void HitToBox(BoxCollider* collider);
};



}
}



#endif