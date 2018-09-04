// BoxCollider.cpp

#include "BoxCollider.h"
#include "SphereCollider.h"
#include "../Transform.h"

namespace GameEngine { namespace Behaviour
{
// 中心座標と大きさを取得
BoxCollider::BoxCollider(D3DXVECTOR3 position, D3DXVECTOR3 scale,int flag)
	:Collider(flag)
{
	_position = position;
	_scale = scale;
}

BoxCollider::~BoxCollider()
{
}

D3DXVECTOR3 BoxCollider::GetPosition()
{
	return _position;
}

D3DXVECTOR3 BoxCollider::GetScale()
{
	return _scale;
}

void BoxCollider::Hit(Collider* collider)
{
	BoxCollider *box = dynamic_cast<BoxCollider*>(collider);// 動的にキャスト、もしBoxColliderじゃなかったらNULL(nullptr)が帰ってくる
	if (box)
	{
		this->HitToBox(box);
		return;
	}

	SphereCollider *sphere = dynamic_cast<SphereCollider*>(collider);// 動的にキャスト、もしSphereColliderじゃなかったらNULL(nullptr)が帰ってくる
	if (sphere)
	{
		sphere->HitToBox(this);
		return;
	}
}

void BoxCollider::HitToBox(BoxCollider* collider)
{

}

void BoxCollider::SetScale(D3DXVECTOR3* scale)
{
    _scale = *scale;
}

}
}