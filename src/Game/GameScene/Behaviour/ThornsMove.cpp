//
//		ファイル名:Toge_move.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "ThornsMove.h"

namespace Game { namespace Behaviour
{

ThornsMove::ThornsMove():Gimmick(Gimmick::defaultDuration)
{

}
//＝＝＝関数定義＝＝＝//
/////////////////////////////////////////////
//関数名：Start
//
//機能：ギミックの初期化
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void ThornsMove::Start(void)
{
    Gimmick::Start();

    _transform = GetAttachedObject()->GetTransform();
    _move_Distance = 0.0F;
    _move = { 0.0F, 0.0F, 0.0F };
    _move_Vector = _transform->Front() * 0.2F;
    _attack = false;
}

/////////////////////////////////////////////
//関数名：Update
//
//機能：ギミックの更新
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void ThornsMove::Update(void)
{
    if(!_attack)
    {
        return;
    }

    _move = { 0.0F, 0.0F, 0.0F };
    _move += _move_Vector * _move_Distance;
    _move_Distance += 0.1F;

    if (_move_Distance >= 5.0F)
    {
        _attack = false;
        return;
    }

    //移動値の反映
    _transform->Offset(&_move);
}

/////////////////////////////////////////////
//関数名：OnCollision
//
//機能：ギミックの更新
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void ThornsMove::OnCollision(GameEngine::Behaviour::Collider* from)
{
    Gimmick::OnCollision(from);
    if (from->GetFlag() & 0x00ff);
    _attack = true;
}

}}