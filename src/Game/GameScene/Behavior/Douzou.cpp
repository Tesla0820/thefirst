//
//		�t�@�C����:Douzou.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Douzou.h"
#include "../../../GameEngine/Resource/Mesh/MeshD3DX.h"

namespace Game { namespace Behaviour
{

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
void Douzou::Start(void)
{
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
void Douzou::Update(void)
{
    //---�e��錾---//
    D3DXQUATERNION rotate;

    //�ړ�
    Move = { 0.0F, 0.0F, 0.0F };
    Move += Move_Vector;
    Move_Distance += 0.1F;

    //���]����
    if (Move_Distance >= 10.0F)
    {
        Move_Distance = 0.0F;
        if (Move_Vector == _transform->Front())
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, 0.0F, 0.0F, 0.0F);
        }
        else
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, D3DX_PI, 0.0F, 0.0F);
        }
    }

    //�ړ��l�̔��f
    _transform->Offset(&Move);
    _transform->SetRotation(&rotate);
}

}}