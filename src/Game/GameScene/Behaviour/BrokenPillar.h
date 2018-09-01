//
//		ファイル名:BrokenPillar.h
//

#ifndef HEADER_BROKENPILLAR_H
#define HEADER_BROKENPILLAR_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class BrokenPillar : public Gimmick
{
    public:
        BrokenPillar();
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif