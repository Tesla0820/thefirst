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