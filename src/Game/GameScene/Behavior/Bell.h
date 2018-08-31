//
//		ファイル名:Bell.h
//

#ifndef HEADER_BELL_H
#define HEADER_BELL_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝定数・マクロ定義＝＝＝//
#define SHINE_TIME_BELL SHINE_TIME * 2


//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Bell : public Gimmick
{
    public:
        virtual void Start(void) override;
        virtual void Update(void) override;
        //GameEngine::Behaviour::Transform* Get(void) { return _transform; }

        // ICollisionHandler を介して継承されました
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif