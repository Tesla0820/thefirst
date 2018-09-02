//
//		ファイル名:ThornsMove.h
//

#ifndef HEADER_THORNS_MOVE_H
#define HEADER_THORNS_MOVE_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"
#include "../../../GameEngine/Behaviour/Collider/ICollisionHandler.h"

//＝＝＝定数・マクロ定義＝＝＝//
#define MOVE_DISTANCE 5.0F

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class ThornsMove : public Gimmick, GameEngine::Behaviour::ICollisionHandler
{
    private:
        GameEngine::Behaviour::Transform*    _transform;
        GameEngine::Behaviour::BoxCollider*  _collider;

        float Move_Distance;
        D3DXVECTOR3 Move;
        D3DXVECTOR3 Move_Vector;
        bool _move;

    public:
        ThornsMove();
		virtual void Start(void) override;
        virtual void Update(void) override;

        // ICollisionHandler を介して継承されました
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif