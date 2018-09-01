//
//		ファイル名:Thorns.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Thorns.h"

namespace Game { namespace Behaviour
{

Thorns::Thorns():Gimmick(Gimmick::defaultDuration)
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
void Thorns::Start(void)
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
void Thorns::Update(void)
{
    Gimmick::Update();
}

}}