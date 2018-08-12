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
	//�����蔻�肪�L���ł͂Ȃ��Ȃ�̂ŁA����̔z�񂩂玩���������B
	RemoveActiveCollider(this);
}

//�Q�[���I�u�W�F�N�g��R�Â��܂��B���ۂɕR�Â���̂̓Q�[���I�u�W�F�N�g������Ȃ̂�
//���̊֐��𒼐ڌĂяo���Ȃ��ł��������B
void Collider::Attach(GameObject * object)
{
	_object = object;
	if (object)
	{
		//�����蔻�肪�L���Ȃ̂Ŕz��Ɏ�����ǉ�����B
		AddActiveCollider(this);
	}
	else
	{
		//�����蔻�肪�L���ł͂Ȃ��̂Ŕz�񂩂玩������������B
		RemoveActiveCollider(this);
	}
}

GameObject * Collider::GetGameObject()
{
	return _object;
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