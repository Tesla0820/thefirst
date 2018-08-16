// Collider.h

#ifndef HEADER_COLLIDER_H 
#define HEADER_COLLIDER_H

#include <vector>
#include "../Behaviour.h"
#include "../../GameObject.h"

namespace GameEngine { namespace Behaviour
{

//当たり判定を行う基底クラス
class Collider : public Behaviour
{
private:
	GameObject* _object;//適用されているオブジェクトへのポインタ

protected:
	static std::vector<Collider*> _colliders;// 現在有効な全ての判定の配列
	static void AddActiveCollider(Collider* collider); // 有効な判定配列に追加する
	static void RemoveActiveCollider(Collider* collider);// 有効な判定配列から削除する
public:
	Collider();
	virtual void Enabled() override;
	virtual void Disabled() override;
	virtual void Hit() = 0; // 判定します。純粋仮想関数です。

};


}
}



#endif
