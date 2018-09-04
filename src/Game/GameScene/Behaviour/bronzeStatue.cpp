//
//		�t�@�C����:BronzeStatue.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "BronzeStatue.h"

namespace Game { namespace Behaviour
{
BronzeStatue::BronzeStatue():Gimmick(Gimmick::defaultDuration)
{

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
    _move_Distance = 0;
    _move = { 0.0F, 0.0F, 0.0F };
    _move_Vector = _transform->Front();
    _default_Rotation = _transform->GetRotation().y * D3DX_PI;
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
    _move_Distance++;
    
    //���]����
    if (_move_Distance >= 100)
    {
        //---�e��錾---//
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

    //�ړ��l�̔��f
    _transform->Offset(&_move);

    Gimmick::Update();
}

}}