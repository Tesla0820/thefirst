//
//		�t�@�C����:BrokenPillar.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "BrokenPillar.h"

namespace Game { namespace Behaviour
{

BrokenPillar::BrokenPillar():Gimmick(Gimmick::defaultDuration)
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
void BrokenPillar::Start(void)
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
void BrokenPillar::Update(void)
{
    Gimmick::Update();
}

}}