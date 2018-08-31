//
//		ファイル名: Bell.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Bell.h"
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
void Bell::Start(void)
{
    GameEngine::GameObject* model = GetAttachedObject();
    _transform = model->GetTransform();
    _renderer = new Game::MeshRendererEx();
    _renderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/gimmick_test.x"))));
    model->AddBehaviour(_renderer);
    _time = 0;
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
void Bell::Update(void)
{
    if (_time)
    {
        _time--;
    }
    _renderer->SetRate((float)_time / SHINE_TIME_BELL);
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
void Bell::OnCollision(GameEngine::Behaviour::Collider* from)
{
    _time = SHINE_TIME_BELL;
    _renderer->SetRate(1.0F);
}

}}