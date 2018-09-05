//
//		ファイル名: Bell.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Bell.h"

namespace Game { namespace Behaviour
{

Bell::Bell():Gimmick(Gimmick::defaultDuration * 2)
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
void Bell::Start(void)
{
	Gimmick::Start();
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
    Gimmick::Update();

}

void Bell::OnCollision(GameEngine::Behaviour::Collider * collider)
{
	Gimmick::OnCollision(collider);
	if (collider->GetFlag() & 0x00ff) return;
}

}}