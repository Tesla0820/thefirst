// BoxCollider.cpp

#include "BoxCollider.h"
#include "SphereCollider.h"
#include "../Transform.h"

namespace GameEngine { namespace Behaviour
{
// ���S���W�Ƒ傫�����擾
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
	BoxCollider *box = dynamic_cast<BoxCollider*>(collider);// ���I�ɃL���X�g�A����BoxCollider����Ȃ�������NULL(nullptr)���A���Ă���
	if (box)
	{
		this->HitToBox(box);
		return;
	}

	SphereCollider *sphere = dynamic_cast<SphereCollider*>(collider);// ���I�ɃL���X�g�A����SphereCollider����Ȃ�������NULL(nullptr)���A���Ă���
	if (sphere)
	{
		sphere->HitToBox(this);
		return;
	}
}

void BoxCollider::HitToBox(BoxCollider* collider)
{

}


}
}