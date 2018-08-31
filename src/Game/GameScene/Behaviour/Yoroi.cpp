//
//		ファイル名:Yoroi.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Yoroi.h"
#include "../../../GameEngine/Resource/Mesh/MeshD3DX.h"

namespace Game { namespace Behaviour
{

Yoroi::Yoroi()
	:Gimmick(Gimmick::defaultDuration)
{
}


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
void Game::Behaviour::Yoroi::Start(void)
{

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
void Game::Behaviour::Yoroi::Update(void)
{
    Gimmick::Update();
}


}}