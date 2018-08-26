// BoxCollider.cpp

#include "BoxCollider.h"
#include "SphereCollider.h"
#include "../Transform.h"

namespace GameEngine { namespace Behaviour
{
// ���S���W�Ƒ傫�����擾
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
	//�C�e���[�^�[���g�������[�v vector���g�����Ƃ��͊�{������
	for (auto iterator = _colliders.begin(); iterator != _colliders.end(); ++iterator)
	{
		if (*iterator == this) continue;//�����͏���
		BoxCollider *box = dynamic_cast<BoxCollider*>(*iterator);// ���I�ɃL���X�g�A����BoxCollider����Ȃ�������NULL(nullptr)���A���Ă���
		if (box)
		{
			this->HitToBox(box);
			continue;
		}

		SphereCollider *sphere = dynamic_cast<SphereCollider*>(*iterator);// ���I�ɃL���X�g�A����SphereCollider����Ȃ�������NULL(nullptr)���A���Ă���
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