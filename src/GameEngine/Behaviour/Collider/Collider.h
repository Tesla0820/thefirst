// Collider.h

#ifndef HEADER_COLLIDER_H 
#define HEADER_COLLIDER_H

#include <vector>
#include "../Behaviour.h"
#include "../../GameObject.h"

namespace GameEngine { namespace Behaviour
{

//�����蔻����s�����N���X
class Collider : public Behaviour
{
private:
	GameObject* _object;//�K�p����Ă���I�u�W�F�N�g�ւ̃|�C���^

protected:
	static std::vector<Collider*> _colliders;// ���ݗL���ȑS�Ă̔���̔z��
	static void AddActiveCollider(Collider* collider); // �L���Ȕ���z��ɒǉ�����
	static void RemoveActiveCollider(Collider* collider);// �L���Ȕ���z�񂩂�폜����
public:
	Collider();
	virtual ~Collider();
	void Attach(GameObject* object);	// �Q�[���I�u�W�F�N�g��R�Â��܂��B
	GameObject* GetGameObject();		// �K�p����Ă���Q�[���I�u�W�F�N�g���擾���܂��B
	virtual void Hit() = 0; // ���肵�܂��B�������z�֐��ł��B

};


}
}



#endif
