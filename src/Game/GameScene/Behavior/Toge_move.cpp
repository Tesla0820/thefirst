//
//		�t�@�C����:Toge_move.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Toge_move.h"
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
void Toge_move::Start(void)
{
    GameEngine::GameObject* model = GetAttachedObject();
    _transform = model->GetTransform();
    _renderer = new Game::MeshRendererEx();
    _renderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/gimmick_test.x"))));
    model->AddBehaviour(_renderer);
    _attack = false;
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
void Toge_move::Update(void)
{
    //�v���C���[�����̃I�u�W�F�N�g������̋����ɗ���ƕǂ⏰���˂��o��
    if (0/*�˂��o�鋗���܂Ńv���[���[���ڋ�*/)
    {
        _transform->SetPosition(&D3DXVECTOR3(0.0F, 0.0F, 30.0F));
        _attack = true;
    }

    if (_attack)
    {

    }
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
void Toge_move::OnCollision(GameEngine::Behaviour::Collider* from)
{
    _time = SHINE_TIME;
    _renderer->SetRate(1.0F);
}

}}