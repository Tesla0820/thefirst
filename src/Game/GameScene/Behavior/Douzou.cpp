//
//		ファイル名:Douzou.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Douzou.h"
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
void Douzou::Start(void)
{
    GameEngine::GameObject* model = GetAttachedObject();
    _transform = model->GetTransform();
    _renderer = new Game::MeshRendererEx();
    _renderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/gimmick_test.x"))));
    model->AddBehaviour(_renderer);
    _time = 0;

    Move_Distance = 0.0F;
    Move = { 0.0F, 0.0F, 0.0F };
    Move_Vector = _transform->Front();
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
void Douzou::Update(void)
{
    //---各種宣言---//
    D3DXVECTOR3 position;
    D3DXQUATERNION rotate;

    Move += Move_Vector;
    Move_Distance += 0.1F;
    if (Move_Distance >= 10.0F)
    {
        Move_Distance = 0.0F;
        if (Move_Vector == _transform->Front())
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, 0.0F, 0.0F, 0.0F);
            Move_Vector = _transform->Front();
        }
        else
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, D3DX_PI, 0.0F, 0.0F);
            Move_Vector = _transform->Back();
        }
    }
    _transform->Offset(&position);
    _transform->SetRotation(&rotate);

    if (_time)
    {
        _time--;
    }
    _renderer->SetRate((float)_time / SHINE_TIME);
}

/////////////////////////////////////////////
//関数名：OnCollision
//
//機能：当たり判定に対する挙動
//
//引数：(GameEngine::Behaviour::Collider*)判定
//
//戻り値：なし
/////////////////////////////////////////////
void Douzou::OnCollision(GameEngine::Behaviour::Collider* from)
{
    _time = SHINE_TIME;
    _renderer->SetRate(1.0F);
}

}}