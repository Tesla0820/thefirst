//
//		ファイル名:BronzeStatue.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "BronzeStatue.h"

namespace Game { namespace Behaviour
{
BronzeStatue::BronzeStatue(D3DXVECTOR3 start, D3DXVECTOR3 end, int ratio):Gimmick(Gimmick::defaultDuration)
{
    _start = start;
    _end = end;
    _ratio = ratio;

    //D3DXVec3Lerp(&_start_pos, &_start, &_end, ratio);

    //移動距離の算出
    _move_Distance = _end - _start;
    D3DXVec3Length(&_move_Distance);
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
    
    //座標の代入
    _transform = GetAttachedObject()->GetTransform();

    //移動量の初期化
    _move = { 0.0F, 0.0F, 0.0F };
    _move_Vector = _transform->Front();
    _move_Current_Distance = _move_Vector * (float)_ratio;

    //回転の初期化
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
    //移動
    _move = { 0.0F, 0.0F, 0.0F };
    _move += _move_Vector;
    _move_Current_Distance += _move_Vector;

    //折り返し判定
    if (abs(_move_Current_Distance.x) >= _move_Distance.x)
    {
        //---各種宣言---//
        D3DXQUATERNION rotate;

        _move_Current_Distance = { 0.0F, 0.0F, 0.0F };
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