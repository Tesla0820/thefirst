//
//		ファイル名:Pillar.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Pillar.h"

namespace Game { namespace Behaviour
{

Pillar::Pillar():Gimmick(Gimmick::defaultDuration)
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
void Pillar::Start(void)
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
void Pillar::Update(void)
{
    Gimmick::Update();
}

}}