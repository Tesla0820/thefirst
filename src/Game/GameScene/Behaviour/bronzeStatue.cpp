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
    Move_Distance = 0.0F;
    Move = { 0.0F, 0.0F, 0.0F };
    Move_Vector = _transform->Front();
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
    Move = { 0.0F, 0.0F, 0.0F };
    Move += Move_Vector;
    Move_Distance += 0.1F;

    //���]����
    if (Move_Distance >= 10.0F)
    {
        //---�e��錾---//
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

    //�ړ��l�̔��f
    _transform->Offset(&Move);

    Gimmick::Update();
}

}}