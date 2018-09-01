//
//		ファイル名:Yoroi.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Armor.h"

namespace Game { namespace Behaviour
{

Armor::Armor():Gimmick(Gimmick::defaultDuration)
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
void Armor::Start(void)
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
void Armor::Update(void)
{
    Gimmick::Update();
}

}}