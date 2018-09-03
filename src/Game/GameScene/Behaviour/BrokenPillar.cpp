//
//		ファイル名:BrokenPillar.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "BrokenPillar.h"

namespace Game { namespace Behaviour
{

BrokenPillar::BrokenPillar():Gimmick(Gimmick::defaultDuration)
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
void BrokenPillar::Start(void)
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
void BrokenPillar::Update(void)
{
    Gimmick::Update();
}

}}