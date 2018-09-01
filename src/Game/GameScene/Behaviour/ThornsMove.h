//
//		ファイル名:ThornsMove.h
//

#ifndef HEADER_THORNS_MOVE_H
#define HEADER_THORNS_MOVE_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class ThornsMove : public Gimmick
{
    private:
        GameEngine::Behaviour::Transform*    _transform;

    public:
        ThornsMove();
		virtual void Start(void) override;
        virtual void Update(void) override;
};

}}
#endif