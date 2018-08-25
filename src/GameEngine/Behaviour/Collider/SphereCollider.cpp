// SphereCollider.cpp

#include "SphereCollider.h"

#include "../Transform.h"


namespace GameEngine { namespace Behaviour
{
// 中心座標と半径を取得
SphereCollider::SphereCollider(D3DXVECTOR3 center, float radius)
{
	_center = center;
	_radius = radius;
}

SphereCollider::~SphereCollider()
{
}

float* SphereCollider::GetRadius()
{
	return &_radius;
}

void SphereCollider::Hit()
{
	//イテレーターを使ったループ vectorを使ったときは基本こっち
	for (auto iterator = _colliders.begin(); iterator != _colliders.end(); ++iterator)
	{
		if (*iterator == this) continue;//自分は除く
		SphereCollider *sphere = dynamic_cast<SphereCollider*>(*iterator);//動的にキャスト、もしCircleColliderじゃなかったらNULL(nullptr)が帰ってくる
		if (sphere)
		{
			this->HitToSphere(sphere);
			continue;
		}

		BoxCollider *box = dynamic_cast<BoxCollider*>(*iterator);//動的にキャスト、もしCircleColliderじゃなかったらNULL(nullptr)が帰ってくる
		if (box)
		{
			this->HitToBox(box);
			continue;
		}
	}
}

void SphereCollider::HitToSphere(SphereCollider* collider)
{
	float range;			// 当たり判定の範囲
	float magnitude;		// 自分から相手までの距離の二乗
	D3DXVECTOR3 mePos, otherPos;	// 自分と相手の位置
	mePos = this->_center;
	otherPos = collider->GetAttachedObject()->GetTransform()->GetPosition();
	range = _radius + collider->_radius;	// 判定の範囲を取得

	magnitude = (mePos.x - otherPos.x)*(mePos.x - otherPos.x) + (mePos.y - otherPos.y)*(mePos.y - otherPos.y) + (mePos.z - otherPos.z)*(mePos.z - otherPos.z);
	if (magnitude <= range*range)
	{
		// 当たった
	}

}

void SphereCollider::HitToBox(BoxCollider* collider)
{
	Transform* me;
	Transform* target;
	D3DXVECTOR3 direction[3] =
	{
		D3DXVECTOR3(1.0f,0.0,0.0f),
		D3DXVECTOR3(0.0f,1.0,0.0f),
		D3DXVECTOR3(0.0f,0.0,1.0f),
	};


	me = GetAttachedObject()->GetTransform();
	target = GetAttachedObject()->GetTransform();
	D3DXMATRIX meMatrix =target->GetWorldMatrix();
	D3DXMATRIX targetMatrix = target->GetWorldMatrix();
	D3DXVECTOR3 distance(offset._41, offset._42, offset._43);
	for (int i = 0; i < 3; i++)
	{

	}

}


}
}