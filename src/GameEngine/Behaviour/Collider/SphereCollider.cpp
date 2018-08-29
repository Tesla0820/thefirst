// SphereCollider.cpp

#include "SphereCollider.h"
#include "BoxCollider.h"
#include "../Transform.h"


namespace GameEngine { namespace Behaviour
{
SphereCollider::SphereCollider(int flag)
	:	Collider(flag),
		_center(0.0f, 0.0f, 0.0f),
		_radius(0.5f)
{

}

// 中心座標と半径を取得
SphereCollider::SphereCollider(D3DXVECTOR3 center, float radius, int flag)
	:Collider(flag)
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

void SphereCollider::Start()
{
	_oldPosition = GetAttachedObject()->GetTransform()->GetWorldPosition();
}

void SphereCollider::Hit(Collider* collider)
{
	SphereCollider *sphere = dynamic_cast<SphereCollider*>(collider);//動的にキャスト、もしCircleColliderじゃなかったらNULL(nullptr)が帰ってくる
	if (sphere)
	{
		this->HitToSphere(sphere);
		return;
	}

	BoxCollider *box = dynamic_cast<BoxCollider*>(collider);//動的にキャスト、もしCircleColliderじゃなかったらNULL(nullptr)が帰ってくる
	if (box)
	{
		this->HitToBox(box);
		return;
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
		OnCollision(collider);
	}

}

void SphereCollider::HitToBox(BoxCollider* collider)
{
	bool isHit = true;
	Transform* me = GetAttachedObject()->GetTransform();
	Transform* target = collider->GetAttachedObject()->GetTransform();

	D3DXVECTOR3 mePosition = me->GetWorldPosition()+_center;
	D3DXVECTOR3 targetPosition = target->GetWorldPosition()+collider->GetPosition();
	D3DXVECTOR3 distance = mePosition - targetPosition;
	D3DXVECTOR3 entryAngle;
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
	D3DXVec3Normalize(&entryAngle, &(_oldPosition + _center - targetPosition));
	
	D3DXVECTOR3 direction[3] =
	{
		target->CalcDirection(&D3DXVECTOR3(1.0f,0.0,0.0f)),//x
		target->CalcDirection(&D3DXVECTOR3(0.0f,1.0,0.0f)),//y
		target->CalcDirection(&D3DXVECTOR3(0.0f,0.0,1.0f)),//z
	};

	for (int i = 0; i < 3; i++)
	{
		D3DXVECTOR2 entry0(entryAngle[i], entryAngle[(i + 1) % 3]);
		D3DXVECTOR2 entry1(entryAngle[i], entryAngle[(i + 2) % 3]);
		D3DXVECTOR2 normal0(direction[(i + 1) % 3][i], direction[(i + 1) % 3][(i + 1) % 3]);
		D3DXVECTOR2 normal1(direction[(i + 2) % 3][i], direction[(i + 2) % 3][(i + 2) % 3]);
		D3DXVec2Normalize(&entry0, &entry0);
		D3DXVec2Normalize(&entry1, &entry1);
		D3DXVec2Normalize(&normal0, &normal0);
		D3DXVec2Normalize(&normal1, &normal1);
		float cos0 = half[(i + 1) % 3] / D3DXVec2Length(&D3DXVECTOR2(half[i], half[(i + 1) % 3]));
		float cos1 = half[(i + 2) % 3] / D3DXVec2Length(&D3DXVECTOR2(half[i], half[(i + 2) % 3]));
		float dot0	= D3DXVec2Dot(&entry0, &normal0);
		float dot1	= D3DXVec2Dot(&entry1, &normal1);
		float s		= D3DXVec3Dot(&direction[i], &distance);
		if (fabs(s)>= fabs(half[i])+_radius)
		{
			//軸側の面外側にいる
			isHit = false;
			break;
		}

		if(fabs(dot0)<=cos0 && fabs(dot1)<=cos1)
		{
			float sign = (s > 0) - (s < 0);
			//軸側の面内側かつ計算方向側にいる
			//進度計算
			penetration += sign*(fabs(half[i])-fabs(s)+_radius)*direction[i];
		}
	}

	if (isHit && !IsTrigger() && !IsFreeze()) 
	{
		//判定内にいる
		me->Offset(&(penetration));
	}
	_oldPosition = GetAttachedObject()->GetTransform()->GetWorldPosition();
	if (isHit)
	{
		OnCollision(collider);
	}
}

}
}