//
//		ファイル名:BronzeStatue.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "BronzeStatue.h"

namespace Game { namespace Behaviour
{
BronzeStatue::BronzeStatue(D3DXVECTOR3 left_end, D3DXVECTOR3 right_end, float position):Gimmick(Gimmick::defaultDuration)
{
    _left_end = left_end;
    _right_end = right_end;
    D3DXVec3Lerp(&_start_pos, &_left_end, &_right_end, position);
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
    _transform->SetPosition(&_start_pos);
    _move_Distance = 0;
    _move = { 0.0F, 0.0F, 0.0F };
    _move_Vector = _transform->Front();
    _default_Rotation = std::asin(_transform->GetRotation().y) * 2;
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
    if(_move_Distance >= )
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

    //移動
    _move = { 0.0F, 0.0F, 0.0F };
    _move += _move_Vector;
    _move_Distance++;
    
    //反転判定
    //if (_move_Distance >= 100)
    //{
    //    //---各種宣言---//
    //    D3DXQUATERNION rotate;
    //
    //    _move_Distance = 0.0F;
    //    if (_checkRotate)
    //    {
    //        D3DXQuaternionRotationYawPitchRoll(&rotate, _default_Rotation, 0.0F, 0.0F);
    //        _checkRotate = false;
    //    }
    //    else
    //    {
    //        D3DXQuaternionRotationYawPitchRoll(&rotate, _default_Rotation + D3DX_PI, 0.0F, 0.0F);
    //        _checkRotate = true;
    //    }
    //    _transform->SetRotation(&rotate);
    //    _move_Vector = -_move_Vector;
    //}

    //移動値の反映
    _transform->Offset(&_move);

    Gimmick::Update();
}

}}