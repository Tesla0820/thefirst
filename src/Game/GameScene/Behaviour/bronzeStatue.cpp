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
    _move_Distance = 0;
    _move = { 0.0F, 0.0F, 0.0F };
    _move_Vector = _transform->Front();
    _default_Rotation = _transform->GetRotation().y * D3DX_PI;
    _checkRotate = false;
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
    _move = { 0.0F, 0.0F, 0.0F };
    _move += _move_Vector;
    _move_Distance++;
    
    //反転判定
    if (_move_Distance >= 100)
    {
        //---各種宣言---//
        D3DXQUATERNION rotate;

        _move_Distance = 0.0F;
        if (_checkRotate)
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, _default_Rotation, 0.0F, 0.0F);
            _checkRotate = false;
        }
        else
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, _default_Rotation + D3DX_PI, 0.0F, 0.0F);
            _checkRotate = true;
        }
        _transform->SetRotation(&rotate);
        _move_Vector = -_move_Vector;
    }

    //移動値の反映
    _transform->Offset(&_move);

    Gimmick::Update();
}

}}