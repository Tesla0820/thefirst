//
//		�t�@�C����:Yoroi.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Armor.h"

namespace Game { namespace Behaviour
{

Armor::Armor():Gimmick(Gimmick::defaultDuration)
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
void Armor::Start(void)
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
void Armor::Update(void)
{
    Gimmick::Update();
}

}}