//
//		�t�@�C����:BronzeStatue.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
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

//�������֐���`������//
/////////////////////////////////////////////
//�֐����FStart
//
//�@�\�F�M�~�b�N�̏�����
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void BronzeStatue::Start(void)
{
    Gimmick::Start();
    _transform = GetAttachedObject()->GetTransform();
	_direction = 1.0f;
	_moveDirection = _transform->Front();
	_origin = _transform->GetPosition();
	_isInverse = false;
    //���W�̑��
	_transform->SetPosition(&(_origin + _moveDirection*_currentPos));
}

/////////////////////////////////////////////
//�֐����FUpdate
//
//�@�\�F�M�~�b�N�̍X�V
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
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
    //�ړ�
    Gimmick::Update();
}

}}