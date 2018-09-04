// Collider.h

#include "Collider.h"
#include "ICollisionHandler.h"

namespace GameEngine { namespace Behaviour
{

std::vector<Collider*> Collider::_colliders;//現在有効な全ての判定の配列

Collider::Collider(int flag)
{
	_handler = nullptr;
	_isTrigger = true;
	_isFreeze = false;
	_flag = flag;
}

void Collider::Enabled()
{
	AddActiveCollider(this);	//コライダーを判定可能とする
}

void Collider::Disabled()
{
	RemoveActiveCollider(this);	//コライダーを判定不可とする
}

void Collider::EnableTrigger(bool enable)
{
	_isTrigger = enable;
}

void Collider::EnableFreeze(bool enable)
{
	_isFreeze = enable;
}

bool Collider::IsTrigger()
{
	return _isTrigger;
}

bool Collider::IsFreeze()
{
	return _isFreeze;
}

void Collider::SetHandler(ICollisionHandler * handler)
{
	_handler = handler;
}

void Collider::SetFlag(int flag)
{
	_flag = flag;
}

int Collider::GetFlag()
{
	return _flag;
}

void Collider::HitAll()
{
	for (auto iterator = _colliders.begin(); iterator != _colliders.end(); ++iterator)
	{
		if (*iterator == this) continue;//自分は除く
		if (!(_flag & (*iterator)->GetFlag())) continue;//マスクで除外
		Hit(*iterator);
	}
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

void Collider::OnCollision(Collider * from)
{
	if (_handler)
	{
		_handler->OnCollision(from);
	}
	if (from->_handler)
	{
		from->_handler->OnCollision(this);
	}
}


}
}