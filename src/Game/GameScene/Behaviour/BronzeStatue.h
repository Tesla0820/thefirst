//
//		ファイル名:BronzeStatue.h
//

#ifndef HEADER_BROZE_SUTATUE_H
#define HEADER_BROZE_SUTATUE_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class BronzeStatue : public Gimmick
{
    private:
        GameEngine::Behaviour::Transform*    _transform;
        float _move_Distance;
        D3DXVECTOR3 _move;
        D3DXVECTOR3 _move_Vector;
        bool _checkRotate;

    public:
        BronzeStatue();
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif