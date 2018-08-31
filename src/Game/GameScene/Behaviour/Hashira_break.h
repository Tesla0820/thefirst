//
//		ファイル名:Hashira_break.h
//

#ifndef HEADER_HASHIRA_BREAK_H
#define HEADER_HASHIRA_BREAK_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Hashira_break : public Gimmick
{

public:
	Hashira_break();
    virtual void Start() override;
    virtual void Update() override;

};

}}
#endif