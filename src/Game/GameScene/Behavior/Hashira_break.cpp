//
//		�t�@�C����:Hashira_break.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Hashira_break.h"
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
void Hashira_break::Start(void)
{
    GameEngine::GameObject* model = GetAttachedObject();
    _transform = model->GetTransform();
    _renderer = new Game::MeshRendererEx();
    _renderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/gimmick_test.x"))));
    model->AddBehaviour(_renderer);
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
void Hashira_break::OnCollision(GameEngine::Behaviour::Collider* from)
{
    _time = SHINE_TIME;
    _renderer->SetRate(1.0F);
}

}}