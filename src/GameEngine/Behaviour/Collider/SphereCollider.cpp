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

// ���S���W�Ɣ��a���擾
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
	//�C�e���[�^�[���g�������[�v vector���g�����Ƃ��͊�{������
	for (auto iterator = _colliders.begin(); iterator != _colliders.end(); ++iterator)
	{
		if (*iterator == this) continue;//�����͏���
		SphereCollider *sphere = dynamic_cast<SphereCollider*>(*iterator);//���I�ɃL���X�g�A����CircleCollider����Ȃ�������NULL(nullptr)���A���Ă���
		if (sphere)
		{
			this->HitToSphere(sphere);
			continue;
		}

		BoxCollider *box = dynamic_cast<BoxCollider*>(*iterator);//���I�ɃL���X�g�A����CircleCollider����Ȃ�������NULL(nullptr)���A���Ă���
		if (box)
		{
			this->HitToBox(box);
			continue;
		}
	}
}

void SphereCollider::HitToSphere(SphereCollider* collider)
{
	float range;			// �����蔻��͈̔�
	float magnitude;		// �������瑊��܂ł̋����̓��
	D3DXVECTOR3 mePos, otherPos;	// �����Ƒ���̈ʒu
	mePos = this->_center;
	otherPos = collider->GetAttachedObject()->GetTransform()->GetPosition();
	range = _radius + collider->_radius;	// ����͈̔͂��擾

	magnitude = (mePos.x - otherPos.x)*(mePos.x - otherPos.x) + (mePos.y - otherPos.y)*(mePos.y - otherPos.y) + (mePos.z - otherPos.z)*(mePos.z - otherPos.z);
	if (magnitude <= range*range)
	{
		// ��������
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
	//�i�x
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
			//�����̖ʊO���ɂ���
			return;
		}

		if(fabs(a)>=0.7071)
		{
			//�����̖ʓ����ɂ���
			//�i�x�v�Z
			penetration += sign*(fabs(half[i])-fabs(s)+_radius)*angle;
		}
	}

	if (!IsTrigger() && !IsFreeze()) 
	{
		//������ɂ���
		me->Offset(&(penetration));
	}
}

}
}