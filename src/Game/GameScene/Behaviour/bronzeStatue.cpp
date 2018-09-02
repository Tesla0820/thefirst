//
//		ファイル名:BronzeStatue.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "BronzeStatue.h"

namespace Game { namespace Behaviour
{
BronzeStatue::BronzeStatue():Gimmick(Gimmick::defaultDuration)
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
void BronzeStatue::Start(void)
{
    Gimmick::Start();

    _transform = GetAttachedObject()->GetTransform();
    Move_Distance = 0.0F;
    Move = { 0.0F, 0.0F, 0.0F };
    Move_Vector = _transform->Front();
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
void BronzeStatue::Update(void)
{
    //移動
    Move = { 0.0F, 0.0F, 0.0F };
    Move += Move_Vector;
    Move_Distance += 0.1F;

    //反転判定
    if (Move_Distance >= 10.0F)
    {
        //---各種宣言---//
        D3DXQUATERNION rotate;

        Move_Distance = 0.0F;
        //if (Move_Vector == _transform->Front())
        //{
        //    D3DXQuaternionRotationYawPitchRoll(&rotate, 0.0F, 0.0F, 0.0F);
        //}
        //else
        //{
        //    D3DXQuaternionRotationYawPitchRoll(&rotate, D3DX_PI, 0.0F, 0.0F);
        //}

        D3DXQuaternionRotationYawPitchRoll(&rotate, D3DX_PI, 0.0F, 0.0F);
        _transform->SetRotation(&rotate);
    }

    //移動値の反映
    _transform->Offset(&Move);

    Gimmick::Update();
}

}}