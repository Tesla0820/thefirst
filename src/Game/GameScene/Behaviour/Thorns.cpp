//
//		�t�@�C����:Thorns.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Thorns.h"

namespace Game { namespace Behaviour
{

Thorns::Thorns():Gimmick(Gimmick::defaultDuration)
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
void Thorns::Start(void)
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
void Thorns::Update(void)
{
    Gimmick::Update();
}

}}