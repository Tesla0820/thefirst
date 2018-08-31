//
//		ファイル名:Hashira.cpp
//

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Hashira.h"

namespace Game { namespace Behaviour
{

Hashira::Hashira()
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
void Hashira::Start(void)
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
void Hashira::Update(void)
{
    Gimmick::Update();
}

}}