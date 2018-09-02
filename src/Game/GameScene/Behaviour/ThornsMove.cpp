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
    Move_Distance = 0.0F;
    Move = { 0.0F, 0.0F, 0.0F };
    Move_Vector = _transform->Front();

    //セットハンドラー
    //GameEngine::Behaviour::BoxCollider::SetHandler(this);
    _move = false;
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

    if(!_move)
    {
        return;
    }

    Move = { 0.0F, 0.0F, 0.0F };
    Move += Move_Vector;
    Move_Distance += 0.1F;

    if (Move_Distance >= MOVE_DISTANCE)
    {
        _move = false;
        return;
    }

    //移動値の反映
    _transform->Offset(&Move);

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
    _move = true;
}

}}