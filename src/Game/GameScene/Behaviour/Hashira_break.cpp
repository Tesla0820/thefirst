//
//		�t�@�C����:Hashira_break.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Hashira_break.h"
#include "../../../GameEngine/Resource/Mesh/MeshD3DX.h"

namespace Game { namespace Behaviour
{

Hashira_break::Hashira_break()
	:Gimmick(Gimmick::defaultDuration)
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
void Hashira_break::Start(void)
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
void Hashira_break::Update(void)
{
    Gimmick::Update();
}

}}