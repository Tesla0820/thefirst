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
    //オブジェクトの登録
    GameEngine::GameObject* gimmick = GameEngine::GameObject::Instantiate();
    gimmick->AddBehaviour(behaviour);

    //座標・角度の設定
    gimmick->GetTransform()->SetPosition(position);
    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, D3DXToRadian(rotate->x), D3DXToRadian(rotate->y), D3DXToRadian(rotate->z));
    gimmick->GetTransform()->SetRotation(&rotation);

    //メッシュの登録
    auto meshRenderer = new Game::MeshRendererEx();
    meshRenderer->SetMesh(mesh);
    gimmick->AddBehaviour(meshRenderer);

    //当たり判定の付与
    gimmick->AddBehaviour(new GameEngine::Behaviour::BoxCollider(*position, D3DXVECTOR3(1.0F, 1.0F, 1.0F), 0x0102));

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
    GameEngine::GameObject* gimmick;
    gimmick = Instantiate(new Game::Behaviour::Armor(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/armor.x"))));

    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, 0.0F, D3DXToRadian(270.0F), 0.0F);
    gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 5.0F, position->z));
    gimmick->GetTransform()->SetRotation(&rotation);

    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(0.05F, 0.05F, 0.05F));
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
    Instantiate(new Game::Behaviour::Bell(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/bell.x"))));
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
    GameEngine::GameObject* gimmick;
    gimmick = Instantiate(new Game::Behaviour::BrokenPillar(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/brokenPillar.x"))));
    
    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, D3DXToRadian(90.0F), 0.0F, 0.0F);
    gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 1.0F, position->z));
    gimmick->GetTransform()->SetRotation(&rotation);
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
    GameEngine::GameObject* gimmick;
    gimmick = Instantiate(new Game::Behaviour::BronzeStatue(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/bronzeStatue.x"))));

    gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 0.0F, position->z - 0.0F));

    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, D3DXToRadian(180.0F), D3DXToRadian(0.0F), D3DXToRadian(0.0F));
    gimmick->GetTransform()->SetRotation(&rotation);

    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(4.0F, 4.0F, 4.0F));
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
    GameEngine::GameObject* gimmick;
    gimmick = Instantiate(new Game::Behaviour::Pillar(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/pillar.x"))));
    gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 3.0F, position->z));
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
    GameEngine::GameObject* gimmick;
    gimmick = Instantiate(new Game::Behaviour::Thorns(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/thorns.x"))));
    
    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, 0.0F, D3DXToRadian(180.0F), 0.0F);
    gimmick->GetTransform()->SetRotation(&rotation);
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

    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, 0.0F, D3DXToRadian(180.0F), 0.0F);
    gimmick->GetTransform()->SetRotation(&rotation);

    //当たり判定の付与
    gimmick->AddBehaviour(new GameEngine::Behaviour::BoxCollider(*position, D3DXVECTOR3(1.2F, 1.2F, 1.2F), 0x0001));
}

}}