//
//		�t�@�C����:Hashira.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Hashira.h"

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
void Hashira::Start(void)
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
void Hashira::Update(void)
{
    Gimmick::Update();
}

}}