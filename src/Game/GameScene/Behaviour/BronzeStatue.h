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
        GameEngine::Behaviour::Transform*    _transform;    //座標データ
        D3DXVECTOR3 _start;                                 //スタート位置
        D3DXVECTOR3 _end;                                   //折り返し位置
        int         _ratio;                                 //移動済み比率
        D3DXVECTOR3 _move_Current_Distance;                 //累計移動距離
        D3DXVECTOR3 _move_Distance;                         //想定移動距離

        D3DXVECTOR3 _move;                                  //移動量
        D3DXVECTOR3 _move_Vector;                           //移動方向
        FLOAT _default_Rotation;                            //標準方向
        bool _checkRotate;                                  //振り向き済み判定

    public:
        BronzeStatue(D3DXVECTOR3, D3DXVECTOR3, int);
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif