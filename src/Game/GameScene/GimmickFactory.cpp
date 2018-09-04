//
//		�t�@�C����: GimmickFactory.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "GimmickFactory.h"

namespace Game { namespace GameScene
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
GameEngine::GameObject* GimmickFactory::Instantiate(GameEngine::Behaviour::Behaviour* behaviour, D3DXVECTOR3* position, D3DXVECTOR3* rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh> mesh)
{
	//�I�u�W�F�N�g�̓o�^
	GameEngine::GameObject* gimmick = GameEngine::GameObject::Instantiate();
	gimmick->AddBehaviour(behaviour);

	//���W�E�p�x�̐ݒ�
	gimmick->GetTransform()->SetPosition(position);
	D3DXQUATERNION rotation;
	//FLOAT y = D3DXToRadian(rotate->y);
	D3DXQuaternionRotationYawPitchRoll(&rotation, D3DXToRadian(rotate->y), D3DXToRadian(rotate->x), D3DXToRadian(rotate->z));
	gimmick->GetTransform()->SetRotation(&rotation);

	//���b�V���̓o�^
	auto meshRenderer = new Game::MeshRendererEx();
	meshRenderer->SetMesh(mesh);
	gimmick->AddBehaviour(meshRenderer);

	//�����蔻��̕t�^
	gimmick->AddBehaviour(new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0F, 1.0F, 1.0F), 0x0102));

	return gimmick;
}

/////////////////////////////////////////////
//�֐����FInstantiateArmor
//
//�@�\�F�Z�̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateArmor(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
	GameEngine::GameObject* gimmick;
	gimmick = Instantiate(new Game::Behaviour::Armor(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/armor.x"))));

	gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 3.5F, position->z));
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
	GameEngine::GameObject* gimmick;
	gimmick = Instantiate(new Game::Behaviour::Bell(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/bell.x"))));

	gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 3.0F, position->z));
}

/////////////////////////////////////////////
//�֐����FInstantiateBrokenPillar
//
//�@�\�F��ꂽ���̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateBrokenPillar(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
	GameEngine::GameObject* gimmick;
	gimmick = Instantiate(new Game::Behaviour::BrokenPillar(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/brokenPillar.x"))));

	gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 2.3F, position->z));
}

/////////////////////////////////////////////
//�֐����FInstantiateBronzeStatue
//
//�@�\�F�����̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateBronzeStatue(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
	GameEngine::GameObject* gimmick;
	gimmick = Instantiate(new Game::Behaviour::BronzeStatue(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/bronzeStatue.x"))));

	gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 3.0F, position->z));
}

/////////////////////////////////////////////
//�֐����FInstantiatePillar
//
//�@�\�F���̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiatePillar(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
	GameEngine::GameObject* gimmick;
	gimmick = Instantiate(new Game::Behaviour::Pillar(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/brokenPillar.x"))));
	gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 3.0F, position->z));
}

/////////////////////////////////////////////
//�֐����FInstantiateThorns
//
//�@�\�F�g�Q�̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateThorns(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
	Instantiate(new Game::Behaviour::Thorns(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/thorns.x"))));
}

/////////////////////////////////////////////
//�֐����FInstantiateThornsMove
//
//�@�\�F�����g�Q�̐���
//
//�����F(D3DXVECTOR3*)�ʒu, (D3DXVECTOR3*)�p�x
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GimmickFactory::InstantiateThornsMove(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
	GameEngine::GameObject* gimmick;
	gimmick = Instantiate(new Game::Behaviour::ThornsMove(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/thorns.x"))));

	//�����蔻��̕t�^
	auto collider = new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0F, 0.0F, 13.0F), D3DXVECTOR3(1.0F, 1.0F, 5.0F), 0x0004);
	collider->EnableTrigger(true);
	collider->EnableFreeze(false);
	gimmick->AddBehaviour(collider);
}

}
}