// BoxCollider.h

#ifndef HEADER_BOX_COLLIDER_H 
#define HEADER_BOX_COLLIDER_H

#include <vector>
#include "../../GameEngine_inner.h"
#include "Collider.h"



namespace GameEngine { namespace Behaviour
{

class SphereCollider;

//直方体の判定を行うクラスです。
class BoxCollider :public Collider
{
private:
	D3DXVECTOR3 _position;		// 座標
	D3DXVECTOR3 _scale;			// 大きさ

public:
	BoxCollider(D3DXVECTOR3 positon, D3DXVECTOR3 scale,int flag);
	virtual ~BoxCollider();
	D3DXVECTOR3 GetPosition();
	D3DXVECTOR3 GetScale();
	virtual void Hit(Collider* collider) override;
	void HitToSphere(SphereCollider* collider);
	void HitToBox(BoxCollider* collider);
};



}
}



#endif