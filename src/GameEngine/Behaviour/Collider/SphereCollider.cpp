// SphereCollider.cpp

#include "SphereCollider.h"
#include "BoxCollider.h"
#include "../Transform.h"


namespace GameEngine { namespace Behaviour
{
SphereCollider::SphereCollider()
	:	_center(0.0f, 0.0f, 0.0f),
		_radius(0.5f)
{

}

// 中心座標と半径を取得
SphereCollider::SphereCollider(D3DXVECTOR3 center, float radius)
{
	_center = center;
	_radius = radius;
}

D3DXVECTOR3 SphereCollider::GetCenterPosition()
{
	return _center;
}

float SphereCollider::GetRadius()
{
	return _radius;
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
	D3DXVECTOR3 direction[3] =
	{
		D3DXVECTOR3(1.0f,0.0,0.0f),//x
		D3DXVECTOR3(0.0f,1.0,0.0f),//y
		D3DXVECTOR3(0.0f,0.0,1.0f),//z
	};

	Transform* me = GetAttachedObject()->GetTransform();
	Transform* target = collider->GetAttachedObject()->GetTransform();

	D3DXMATRIX meMatrix = me->GetWorldMatrix();
	D3DXMATRIX targetMatrix = target->GetWorldMatrix();

	D3DXVECTOR3 distance = D3DXVECTOR3(meMatrix._41 - targetMatrix._41, meMatrix._42 - targetMatrix._42, meMatrix._43 - targetMatrix._43);
	D3DXVECTOR3 distanceNormalized;
	D3DXVec3Normalize(&distanceNormalized, &distance);
	D3DXVECTOR3 targetScale = target->GetScale();
	D3DXVECTOR3 targetColliderScale = collider->GetScale();
	//進度
	D3DXVECTOR3 penetration(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 outer(0.0f, 0.0f, 0.0f);
	float half[3] =
	{
		targetScale.x*targetColliderScale.x,
		targetScale.y*targetColliderScale.y,
		targetScale.z*targetColliderScale.z
	};
	D3DXVECTOR3 angle;
	for (int i = 0; i < 3; i++)
	{
		angle = D3DXVECTOR3(
			targetMatrix._11 * direction[i].x + targetMatrix._12 * direction[i].y + targetMatrix._13 * direction[i].z,
			targetMatrix._21 * direction[i].x + targetMatrix._22 * direction[i].y + targetMatrix._23 * direction[i].z,
			targetMatrix._31 * direction[i].x + targetMatrix._32 * direction[i].y + targetMatrix._33 * direction[i].z
		);
		float a = D3DXVec3Dot(&angle, &distanceNormalized);
		float s = D3DXVec3Dot(&angle, &distance);
		float sign = (s > 0) - (s < 0);
		if (fabs(s)> fabs(half[i])+_radius)
		{
			//軸側の面外側にいる
			return;
		}

		if(fabs(a)>=0.7071)
		{
			//軸側の面内側にいる
			//進度計算
			penetration += sign*(fabs(half[i])-fabs(s)+_radius)*angle;
		}
	}

	if (!IsTrigger() && !IsFreeze()) 
	{
		//判定内にいる
		me->Offset(&(penetration));
	}
}

}
}