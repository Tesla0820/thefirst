//
//		ファイル名: GimmickFactory.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "GimmickFactory.h"

namespace Game { namespace GameScene
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
	D3DXQuaternionRotationYawPitchRoll(&rotation, D3DXToRadian(rotate->y), D3DXToRadian(rotate->x), D3DXToRadian(rotate->z));
	gimmick->GetTransform()->SetRotation(&rotation);

	//メッシュの登録
	auto meshRenderer = new Game::MeshRendererEx();
	meshRenderer->SetMesh(mesh);
	gimmick->AddBehaviour(meshRenderer);

	//当たり判定の付与
	gimmick->AddBehaviour(new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0F, 0.0F, 0.0F), D3DXVECTOR3(1.0F, 1.0F, 1.0F), 0x0102));

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

    gimmick->GetTransform()->Offset(&D3DXVECTOR3(0.0F,50.0F,0.0F));

    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(20.0F, 20.0F, 20.0F));

    gimmick->FindBehaviour<GameEngine::Behaviour::BoxCollider>()->SetScale(&D3DXVECTOR3(1.0F, 13.3F, 0.5F));
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
	GameEngine::GameObject* gimmick;
	gimmick = Instantiate(new Game::Behaviour::Bell(), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/bell.x"))));

	gimmick->GetTransform()->Offset(&D3DXVECTOR3(0.0f, 30.0f, 0.0f));

    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(13.0F, 13.0F, 13.0F));

	auto collider = gimmick->FindBehaviour<GameEngine::Behaviour::BoxCollider>();
	
    collider->SetScale(&D3DXVECTOR3(5.5F, 3.0F, 1.2F));

	collider->SetFlag(0x0108);
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

    gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 35.0F, position->z));

    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(45.0F, 45.0F, 45.0F));

    gimmick->FindBehaviour<GameEngine::Behaviour::BoxCollider>()->SetScale(&D3DXVECTOR3(0.7F, 0.7F, 0.8F));

    D3DXQUATERNION rotation;
    D3DXQuaternionRotationYawPitchRoll(&rotation, D3DXToRadian(rotate->y), D3DXToRadian(rotate->x + 45.0F), D3DXToRadian(rotate->z));
    gimmick->GetTransform()->SetRotation(&rotation);
}

/////////////////////////////////////////////
//関数名：InstantiateBronzeStatue
//
//機能：銅像の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度, (D3DXVECTOR3*)スタート, (D3DXVECTOR3*)折り返し, (float)初期位置割合
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateBronzeStatue(D3DXVECTOR3* position, D3DXVECTOR3* rotate, float distance,float rate)
{
	GameEngine::GameObject* gimmick;
	gimmick = Instantiate(new Game::Behaviour::BronzeStatue(distance, rate,rotate->y), position, rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/bronzeStatue.x"))));

	gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 30.0F, position->z));
    
    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(20.0F, 20.0F, 20.0F));

    gimmick->FindBehaviour<GameEngine::Behaviour::BoxCollider>()->SetScale(&D3DXVECTOR3(1.0F, 2.5F, 1.0F));
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
	
    gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 30.0F, position->z));

    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(8.0F, 8.0F, 8.0F));

    gimmick->FindBehaviour<GameEngine::Behaviour::BoxCollider>()->SetScale(&D3DXVECTOR3(1.4F, 6.0F, 1.4F));
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
    
    gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 35.0F, position->z));

    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(8.0F, 8.0F, 8.0F));

    gimmick->FindBehaviour<GameEngine::Behaviour::BoxCollider>()->SetScale(&D3DXVECTOR3(4.5F, 4.5F, 1.3F));
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

    gimmick->GetTransform()->SetPosition(&D3DXVECTOR3(position->x, position->y + 35.0F, position->z));

    gimmick->GetTransform()->SetScale(&D3DXVECTOR3(8.0F, 8.0F, 8.0F));

    gimmick->FindBehaviour<GameEngine::Behaviour::BoxCollider>()->SetScale(&D3DXVECTOR3(4.5F, 4.5F, 1.3F));

	//当たり判定の付与
    auto collider = new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(0.0F, 0.0F, 0.0F), D3DXVECTOR3(4.5F, 4.5F, 20.0F), 0x0004);
	collider->EnableTrigger(true);
	collider->EnableFreeze(false);
	gimmick->AddBehaviour(collider);
}

}
}