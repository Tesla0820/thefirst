//
//		�t�@�C����:Yoroi.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Yoroi.h"
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
    if (_time)
    {
        _time--;
    }
    _renderer->SetRate((float)_time / SHINE_TIME);
}

/////////////////////////////////////////////
//�֐����FOnCollision
//
//�@�\�F�����蔻��ɑ΂��鋓��
//
//�����F(GameEngine::Behaviour::Collider*)����
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void Yoroi::OnCollision(GameEngine::Behaviour::Collider* from)
{
    _time = SHINE_TIME;
    _renderer->SetRate(1.0F);
}

}}