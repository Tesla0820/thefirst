// Collider.h

#include "Collider.h"


namespace GameEngine { namespace Behaviour
{
std::vector<Collider*> Collider::_colliders;//現在有効な全ての判定の配列


Collider::Collider()
{
	_object = nullptr;
}

void Collider::Enabled()
{
	AddActiveCollider(this);	//コライダーを判定可能とする
}

void Collider::Disabled()
{
	RemoveActiveCollider(this);	//コライダーを判定不可とする
}


//有効な当たり判定の配列に対象を追加する。
//配列内に自分が存在しないときだけ追加処理を実行する
void Collider::AddActiveCollider(Collider * collider)
{	
	//有効な判定の配列に対象を追加
	auto iterator = std::find(_colliders.begin(), _colliders.end(), collider);
	if (iterator != _colliders.end())return; 
	_colliders.push_back(collider);				
}

//有効な当たり判定の配列から対象を消去する
//配列内に自分が存在するときだけ削除処理を実行する。
void Collider::RemoveActiveCollider(Collider * collider)
{	
	//配列内から対象を削除
	auto iterator = std::find(_colliders.begin(), _colliders.end(), collider);
	if (iterator == _colliders.end())return;
	_colliders.erase(iterator);				 
}


}
}