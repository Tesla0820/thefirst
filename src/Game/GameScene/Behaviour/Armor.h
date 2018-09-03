//
//		ファイル名:Armor.h
//

#ifndef HEADER_ARMOR_H
#define HEADER_ARMOR_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Armor : public Gimmick
{
    public:
        Armor();
        virtual void Start(void) override;
        virtual void Update(void) override;
};

}}
#endif