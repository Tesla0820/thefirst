// Collider.h

#include "Collider.h"


namespace GameEngine { namespace Behaviour
{
std::vector<Collider*> Collider::_colliders;//���ݗL���ȑS�Ă̔���̔z��


Collider::Collider()
{
	_object = nullptr;
}

Collider::~Collider()
{
}

void Collider::Enabled()
{
	AddActiveCollider(this);
}

void Collider::Disabled()
{
	RemoveActiveCollider(this);
}


//�L���ȓ����蔻��̔z��ɑΏۂ�ǉ�����B
//�z����Ɏ��������݂��Ȃ��Ƃ������ǉ����������s����
void Collider::AddActiveCollider(Collider * collider)
{
	auto iterator = std::find(_colliders.begin(), _colliders.end(), collider);//�Ώۂ�z�������T��
	if (iterator != _colliders.end())return; //�Ώۂ��z����ɑ��݂��Ă���̂ňȍ~�̏��������Ȃ�
	_colliders.push_back(collider);				//�L���Ȕ���̔z��ɑΏۂ�ǉ�
}

//�L���ȓ����蔻��̔z�񂩂�Ώۂ���������
//�z����Ɏ��������݂���Ƃ������폜���������s����B
void Collider::RemoveActiveCollider(Collider * collider)
{
	auto iterator = std::find(_colliders.begin(), _colliders.end(), collider);//�Ώۂ�z�������T��
	if (iterator == _colliders.end())return; //�Ώۂ��z����ɑ��݂��Ȃ��̂ňȍ~�̏��������Ȃ�
	_colliders.erase(iterator);				 //�z�������Ώۂ��폜
}


}
}