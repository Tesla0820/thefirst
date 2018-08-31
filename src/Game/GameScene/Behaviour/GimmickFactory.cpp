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
    Instantiate(new Game::Behaviour::Bell(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//関数名：InstantiateDouzou
//
//機能：銅像の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateDouzou(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Douzou(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//関数名：InstantiateHashira
//
//機能：柱の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateHashira(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Hashira(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//関数名：InstantiateHashira_break
//
//機能：壊れた柱の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateHashira_break(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Hashira_break(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//関数名：InstantiateToge
//
//機能：トゲの生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateToge(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Toge(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//関数名：InstantiateToge_move
//
//機能：動くトゲの生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateToge_move(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Toge_move(), position, rotate, nullptr);
}

/////////////////////////////////////////////
//関数名：InstantiateYoroi
//
//機能：鎧の生成
//
//引数：(D3DXVECTOR3*)位置, (D3DXVECTOR3*)角度
//
//戻り値：なし
/////////////////////////////////////////////
void GimmickFactory::InstantiateYoroi(D3DXVECTOR3* position, D3DXVECTOR3* rotate)
{
    Instantiate(new Game::Behaviour::Yoroi(), position, rotate,nullptr);
}

}}