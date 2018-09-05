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
		float _distance;									//始点と終点間の距離
		float _currentPos;									//始点と終点間の現在距離
		D3DXVECTOR3 _moveDirection;							//移動方向
		float _direction;									//距離判定上の移動方向
		float _angle;
		bool _isInverse;										//反転中かどうか
    public:
        BronzeStatue(float,float,float);
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif