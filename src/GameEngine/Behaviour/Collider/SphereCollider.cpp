// SphereCollider.cpp

#include "SphereCollider.h"

#include "../Transform.h"


namespace GameEngine { namespace Behaviour
{
// ���S���W�Ɣ��a���擾
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