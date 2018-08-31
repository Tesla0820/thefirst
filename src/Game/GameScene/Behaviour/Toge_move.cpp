//
//		ファイル名:Toge_move.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Toge_move.h"

namespace Game { namespace Behaviour
{

Toge_move::Toge_move()
	:Gimmick(Gimmick::defaultDuration)
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
void Toge_move::Start(void)
{
    _transform = GetAttachedObject()->GetTransform();
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
void Toge_move::Update(void)
{
    //プレイヤーがこのオブジェクトから一定の距離に来ると壁や床より突き出る
    if (0/*突き出る距離までプレーヤーが接近*/)
    {
        _transform->SetPosition(&D3DXVECTOR3(0.0F, 0.0F, 30.0F));
        _attack = true;
    }

    if (_attack)
    {

    }
}

}}