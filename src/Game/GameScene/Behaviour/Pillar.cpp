//
//		�t�@�C����:Pillar.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Pillar.h"

namespace Game { namespace Behaviour
{

Pillar::Pillar():Gimmick(Gimmick::defaultDuration)
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
void Pillar::Start(void)
{

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
void Pillar::Update(void)
{
    Gimmick::Update();
}

}}