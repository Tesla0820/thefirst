//
//		�t�@�C����:Toge_move.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "ThornsMove.h"

namespace Game { namespace Behaviour
{

ThornsMove::ThornsMove():Gimmick(Gimmick::defaultDuration)
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
void ThornsMove::Start(void)
{
    _transform = GetAttachedObject()->GetTransform();
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
void ThornsMove::Update(void)
{
    //�v���C���[�����̃I�u�W�F�N�g������̋����ɗ���ƕǂ⏰���˂��o��
    if (0/*�˂��o�鋗���܂Ńv���[���[���ڋ�*/)
    {
        _transform->SetPosition(&D3DXVECTOR3(0.0F, 0.0F, 30.0F));
    }

}

}}