// Collider.h

#include "Collider.h"


namespace GameEngine { namespace Behaviour
{
std::vector<Collider*> Collider::_colliders;//現在有効な全ての判定の配列


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


//有効な当たり判定の配列に対象を追加する。
//配列内に自分が存在しないときだけ追加処理を実行する
void Collider::AddActiveCollider(Collider * collider)
{
	auto iterator = std::find(_colliders.begin(), _colliders.end(), collider);//対象を配列内から探す
	if (iterator != _colliders.end())return; //対象が配列内に存在しているので以降の処理をしない
	_colliders.push_back(collider);				//有効な判定の配列に対象を追加
}

//有効な当たり判定の配列から対象を消去する
//配列内に自分が存在するときだけ削除処理を実行する。
void Collider::RemoveActiveCollider(Collider * collider)
{
	auto iterator = std::find(_colliders.begin(), _colliders.end(), collider);//対象を配列内から探す
	if (iterator == _colliders.end())return; //対象が配列内に存在しないので以降の処理をしない
	_colliders.erase(iterator);				 //配列内から対象を削除
}


}
}