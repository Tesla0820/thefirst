//
//		ファイル名:ThornsMove.h
//

#ifndef HEADER_THORNS_MOVE_H
#define HEADER_THORNS_MOVE_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"
#include "../../../GameEngine/Behaviour/Collider/ICollisionHandler.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class ThornsMove : public Gimmick
{
    private:
        GameEngine::Behaviour::Transform*    _transform;

        int _move_Distance;
        D3DXVECTOR3 _move;
        D3DXVECTOR3 _move_Vector;
        bool _attack;

    public:
        ThornsMove();
		virtual void Start(void) override;
        virtual void Update(void) override;

        // ICollisionHandler を介して継承されました
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif