//
//		ファイル名:Thorns.h
//

#ifndef HEADER_THORNS_H
#define HEADER_THORNS_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Thorns : public Gimmick
{
    public:
        Thorns();
        virtual void Start(void) override;
        virtual void Update(void) override;
};

}}
#endif