//
//		ファイル名:BronzeStatue.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "BronzeStatue.h"

namespace Game { namespace Behaviour
{
BronzeStatue::BronzeStatue(float distance,float rate,float angleY)
	:Gimmick(Gimmick::defaultDuration)
{
	_distance = std::floorf(distance);
	_currentPos = std::floorf(distance*rate);
	_angle = D3DXToRadian(angleY);
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
	_direction = 1.0f;
	_moveDirection = _transform->Front();
	_isInverse = false;
    //座標の代入
	_transform->SetPosition(&(_transform->GetPosition() + _moveDirection*_currentPos));
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
	_currentPos += _direction;
	_transform->Offset(&_moveDirection);
	if (_currentPos >= _distance || _currentPos<=0.0f)
	{
		_isInverse = !_isInverse;
		_direction *= -1.0f;
		_moveDirection *= -1.0f;
		D3DXQUATERNION rot;
		D3DXQuaternionRotationYawPitchRoll(&rot,_angle+_isInverse * D3DX_PI ,0.0f ,0.0f);
		_transform->SetRotation(&rot);
	}
    //移動
    Gimmick::Update();
}

}}