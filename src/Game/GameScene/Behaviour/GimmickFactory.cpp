//
//		�t�@�C����: GimmickFactory.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "GimmickFactory.h"

namespace Game { namespace Behaviour
{

//�������֐���`������//
/////////////////////////////////////////////
//�֐����FInstantiate
//
//�@�\�F�M�~�b�N�����̍����֐�
//
//�����F(GameEngine::Behaviour::Behaviour*)������, (D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::Instantiate(GameEngine::Behaviour::Behaviour* behaviour, D3DXVECTOR3* position, D3DXVECTOR3* rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh> mesh)
{
    GameEngine::GameObject* gimmick = GameEngine::GameObject::Instantiate();
    gimmick->AddBehaviour(behaviour);
    gimmick->GetTransform()->SetPosition(position);
    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, D3DXToRadian(rotate->x), D3DXToRadian(rotate->y), D3DXToRadian(rotate->z));
    gimmick->GetTransform()->SetRotation(&rotation);
    auto meshRenderer = new Game::MeshRendererEx();
    meshRenderer->SetMesh(mesh);
    gimmick->AddBehaviour(new GameEngine::Behaviour::BoxCollider(*position, D3DXVECTOR3(1.0F, 1.0F, 1.0F), 0));
}

/////////////////////////////////////////////
//�֐����FInstantiateBell
//
//�@�\�F���̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateBell(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Bell(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//�֐����FInstantiateDouzou
//
//�@�\�F�����̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateDouzou(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Douzou(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//�֐����FInstantiateHashira
//
//�@�\�F���̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateHashira(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Hashira(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//�֐����FInstantiateHashira_break
//
//�@�\�F��ꂽ���̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateHashira_break(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Hashira_break(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//�֐����FInstantiateToge
//
//�@�\�F�g�Q�̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateToge(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Toge(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//�֐����FInstantiateToge_move
//
//�@�\�F�����g�Q�̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateToge_move(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Toge_move(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//�֐����FInstantiateYoroi
//
//�@�\�F�Z�̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateYoroi(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Yoroi(), position, rotate,nullptr);
}

}}