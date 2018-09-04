// Collider.h

#ifndef HEADER_COLLIDER_H 
#define HEADER_COLLIDER_H

#include <vector>
#include "../Behaviour.h"
#include "../../GameObject.h"

namespace GameEngine { namespace Behaviour
{
struct ICollisionHandler;

//�����蔻����s�����N���X
class Collider : public Behaviour
{
private:
	ICollisionHandler* _handler;
	bool	_isTrigger;
	bool	_isFreeze;
	int		_flag;
protected:
	static std::vector<Collider*> _colliders;// ���ݗL���ȑS�Ă̔���̔z��
	static void AddActiveCollider(Collider* collider); // �L���Ȕ���z��ɒǉ�����
	static void RemoveActiveCollider(Collider* collider);// �L���Ȕ���z�񂩂�폜����
	virtual void Hit(Collider* collider) = 0;
	void OnCollision(Collider* from);
public:
	Collider(int flag);
	virtual void Enabled() override;
	virtual void Disabled() override;
	void EnableTrigger(bool enable);
	void EnableFreeze(bool enable);
	bool IsTrigger();
	bool IsFreeze();
	void SetHandler(ICollisionHandler* handler);
	void SetFlag(int flag);
	int GetFlag();
	void HitAll(); // �eCollider�ƐڐG���Ă��邩���肵�܂��B

};


}
}



#endif
