// Collider.h

#include "Collider.h"


namespace GameEngine { namespace Behaviour
{
std::vector<Collider*> Collider::_colliders;//���ݗL���ȑS�Ă̔���̔z��


Collider::Collider()
{
	_object = nullptr;
}

void Collider::Enabled()
{
	AddActiveCollider(this);	//�R���C�_�[�𔻒�\�Ƃ���
}

void Collider::Disabled()
{
	RemoveActiveCollider(this);	//�R���C�_�[�𔻒�s�Ƃ���
}


//�L���ȓ����蔻��̔z��ɑΏۂ�ǉ�����B
//�z����Ɏ��������݂��Ȃ��Ƃ������ǉ����������s����
void Collider::AddActiveCollider(Collider * collider)
{	
	//�L���Ȕ���̔z��ɑΏۂ�ǉ�
	auto iterator = std::find(_colliders.begin(), _colliders.end(), collider);
	if (iterator != _colliders.end())return; 
	_colliders.push_back(collider);				
}

//�L���ȓ����蔻��̔z�񂩂�Ώۂ���������
//�z����Ɏ��������݂���Ƃ������폜���������s����B
void Collider::RemoveActiveCollider(Collider * collider)
{	
	//�z�������Ώۂ��폜
	auto iterator = std::find(_colliders.begin(), _colliders.end(), collider);
	if (iterator == _colliders.end())return;
	_colliders.erase(iterator);				 
}


}
}