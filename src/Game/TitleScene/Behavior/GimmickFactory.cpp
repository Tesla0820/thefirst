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
void GimmickFactory::Instantiate(GameEngine::Behaviour::Behaviour* behaviour, D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    GameEngine::GameObject* gimmick = GameEngine::GameObject::Instantiate();
    gimmick->AddBehaviour(behaviour);
    gimmick->GetTransform()->SetPosition(position);
    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, D3DXToRadian(rotate->x), D3DXToRadian(rotate->y), D3DXToRadian(rotate->z));
    gimmick->GetTransform()->SetRotation(&rotation);
    gimmick->AddBehaviour(new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0F, 0.0F,40.0F), D3DXVECTOR3(0.0F,0.0F,0.0F),0));
}

void GimmickFactory::InstantiateBell(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Bell(), position, rotate);
}

void GimmickFactory::InstantiateDouzou(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Douzou(), position, rotate);
}

void GimmickFactory::InstantiateHashira(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Hashira(), position, rotate);
}

void GimmickFactory::InstantiateHashira_break(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Hashira_break(), position, rotate);
}

void GimmickFactory::InstantiateToge(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Toge(), position, rotate);
}

void GimmickFactory::InstantiateToge_move(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Toge_move(), position, rotate);
}

void GimmickFactory::InstantiateYoroi(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Yoroi(), position, rotate);
}

}}