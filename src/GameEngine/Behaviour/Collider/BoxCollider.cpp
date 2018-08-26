// BoxCollider.cpp

#include "BoxCollider.h"
#include "SphereCollider.h"
#include "../Transform.h"

namespace GameEngine { namespace Behaviour
{
// 中心座標と大きさを取得
BoxCollider::BoxCollider(D3DXVECTOR3 position, D3DXVECTOR3 scale)
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

void BoxCollider::Hit()
{
	//イテレーターを使ったループ vectorを使ったときは基本こっち
	for (auto iterator = _colliders.begin(); iterator != _colliders.end(); ++iterator)
	{
		if (*iterator == this) continue;//自分は除く
		BoxCollider *box = dynamic_cast<BoxCollider*>(*iterator);// 動的にキャスト、もしBoxColliderじゃなかったらNULL(nullptr)が帰ってくる
		if (box)
		{
			this->HitToBox(box);
			continue;
		}

		SphereCollider *sphere = dynamic_cast<SphereCollider*>(*iterator);// 動的にキャスト、もしSphereColliderじゃなかったらNULL(nullptr)が帰ってくる
		if (box)
		{
			this->HitToSphere(sphere);
			continue;
		}
	}
}

void BoxCollider::HitToSphere(SphereCollider* collider)
{

}

void BoxCollider::HitToBox(BoxCollider* collider)
{

}


}
}