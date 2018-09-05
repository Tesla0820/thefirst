//
//		�t�@�C����:BronzeStatue.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "BronzeStatue.h"

namespace Game { namespace Behaviour
{
BronzeStatue::BronzeStatue(D3DXVECTOR3 start, D3DXVECTOR3 end, float ratio):Gimmick(Gimmick::defaultDuration)
{
    //�ړ������̎Z�o
    _start = start;
    _end = end;
    //D3DXVec3Lerp(&_start_pos, &_start, &_end, ratio);

    _move_Distance = _end - _start;     //������m�肽��
    D3DXVec3Length(&_move_Distance);
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
    _transform->SetPosition(&_start_pos);

    _move = { 0.0F, 0.0F, 0.0F };
    _move_Current_Distance = { 0.0F, 0.0F, 0.0F };
    _move_Vector = _transform->Front();

    _default_Rotation = std::asin(_transform->GetRotation().y) * 2;
    _checkRotate = false;
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
    //�ړ�
    _move = { 0.0F, 0.0F, 0.0F };
    _move += _move_Vector;
    _move_Current_Distance += _move_Vector;

    //�܂�Ԃ�����
    if (_move_Current_Distance >= _move_Distance)
    {
        //---�e��錾---//
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

    //���]����
    //if (_move_Distance >= 100)
    //{
    //    //---�e��錾---//
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

    //�ړ��l�̔��f
    _transform->Offset(&_move);

    Gimmick::Update();
}

}}