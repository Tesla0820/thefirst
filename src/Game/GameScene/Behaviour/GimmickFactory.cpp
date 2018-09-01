//
//		ファイル名: GimmickFactory.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "GimmickFactory.h"

namespace Game { namespace Behaviour
{

//＝＝＝関数定義＝＝＝//
/////////////////////////////////////////////
//関数名：Instantiate
//
//機能：ギミック生成の根幹関数
//
//引数：(GameEngine::Behaviour::Behaviour*)生成物, (D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
GameEngine::GameObject* GimmickFactory::Instantiate(GameEngine::Behaviour::Behaviour* behaviour, D3DXVECTOR3* position, D3DXVECTOR3* rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh> mesh)
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
    return gimmick;
}

/////////////////////////////////////////////
//関数名：InstantiateArmor
//
//機能：鎧の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateArmor(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Armor(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/armor.x"))));
}

/////////////////////////////////////////////
//関数名：InstantiateBell
//
//機能：鐘の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateBell(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Bell(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/gimmick_test.x"))));
}

/////////////////////////////////////////////
//関数名：InstantiateBrokenPillar
//
//機能：壊れた柱の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateBrokenPillar(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::BrokenPillar(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/brokenPillar.x"))));
}

/////////////////////////////////////////////
//関数名：InstantiateBronzeStatue
//
//機能：銅像の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateBronzeStatue(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::BronzeStatue(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/bronzeStatue.x"))));
}

/////////////////////////////////////////////
//関数名：InstantiatePillar
//
//機能：柱の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiatePillar(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Pillar(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/pillar.x"))));
}

/////////////////////////////////////////////
//関数名：InstantiateThorns
//
//機能：トゲの生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateThorns(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Thorns(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/thorns.x"))));
}

/////////////////////////////////////////////
//関数名：InstantiateThornsMove
//
//機能：動くトゲの生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateThornsMove(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    GameEngine::GameObject* gimmick;
    gimmick = Instantiate(new Game::Behaviour::ThornsMove(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/thorns.x"))));
    gimmick->AddBehaviour(gimmick->FindBehaviour<GameEngine::Behaviour::BoxCollider>());
}


}}