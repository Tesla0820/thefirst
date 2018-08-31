//
//		ファイル名:Toge_move.h
//

#ifndef HEADER_TOGE_MOVE_H
#define HEADER_TOGE_MOVE_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Toge_move : public Gimmick
{
    private:
        GameEngine::Behaviour::Transform*    _transform;
        bool _attack;

    public:
		Toge_move();
		virtual void Start(void) override;
        virtual void Update(void) override;

};

}}
#endif