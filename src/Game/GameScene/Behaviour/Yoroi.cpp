//
//		�t�@�C����:Yoroi.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Yoroi.h"
#include "../../../GameEngine/Resource/Mesh/MeshD3DX.h"

namespace Game { namespace Behaviour
{

Yoroi::Yoroi()
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
void Game::Behaviour::Yoroi::Start(void)
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
void Game::Behaviour::Yoroi::Update(void)
{
    Gimmick::Update();
}


}}