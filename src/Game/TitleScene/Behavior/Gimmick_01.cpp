//
//		ファイル名:Gimmick_01.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick_01.h"
#include "../../../GameEngine/Resource/Mesh/MeshD3DX.h"

namespace Game { namespace Behaviour
{

//＝＝＝関数定義＝＝＝//
/////////////////////////////////////////////
//関数名：Start
//
//機能：ギミックの初期化
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void Game::Behaviour::Gimmick_01::Start(void)
{
    GameEngine::GameObject* model = GetAttachedObject();
    _transform = model->GetTransform();
    _mesh = new GameEngine::Behaviour::MeshRenderer();
    _mesh->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/gimmick_test.x"))));
    model->AddBehaviour(_mesh);
    //model->AddBehaviour(_collider);
}

/////////////////////////////////////////////
//関数名：Update
//
//機能：ギミックの更新
//
//引数：なし
//
//戻り値：なし
/////////////////////////////////////////////
void Game::Behaviour::Gimmick_01::Update(void)
{
    static float move_distance = 0;
    static float move_vector = -0.1F;

    D3DXVECTOR3 position;
    D3DXQUATERNION rotate;

    position = _transform->GetPosition();
    rotate = _transform->GetRotation();
    position.z += move_vector;
    move_distance += 0.1F;
    if (move_distance >= 10.0F)
    {
        move_distance = 0;
        if (move_vector == 0.1F)
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, 0.0F, 0.0F, 0.0F);
        }
        else
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, D3DX_PI, 0.0F, 0.0F);
        }
        move_vector = -move_vector;
    }
    _transform->SetPosition(&position);
    _transform->SetRotation(&rotate);
    _collider->HitToBox(_collider);
}

}}