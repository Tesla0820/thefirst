//
//		ファイル名:Pillar.h
//

#ifndef HEADER_PILLAR_H
#define HEADER_PILLAR_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Pillar : public Gimmick
{
    public:
        Pillar();
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif