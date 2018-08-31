//
//		ファイル名:Hashira.h
//

#ifndef HEADER_HASHIRA_H
#define HEADER_HASHIRA_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Hashira : public Gimmick
{
    public:
		Hashira();
        virtual void Start() override;
        virtual void Update() override;

};

}}
#endif