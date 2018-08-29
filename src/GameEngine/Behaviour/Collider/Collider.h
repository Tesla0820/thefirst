// Collider.h

#ifndef HEADER_COLLIDER_H 
#define HEADER_COLLIDER_H

#include <vector>
#include "../Behaviour.h"
#include "../../GameObject.h"

namespace GameEngine { namespace Behaviour
{
struct ICollisionHandler;

//当たり判定を行う基底クラス
class Collider : public Behaviour
{
private:
	ICollisionHandler* _handler;
	bool	_isTrigger;
	bool	_isFreeze;
	int		_flag;
protected:
	static std::vector<Collider*> _colliders;// 現在有効な全ての判定の配列
	static void AddActiveCollider(Collider* collider); // 有効な判定配列に追加する
	static void RemoveActiveCollider(Collider* collider);// 有効な判定配列から削除する
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
	int GetFlag();
	void HitAll(); // 各Colliderと接触しているか判定します。

};


}
}



#endif
