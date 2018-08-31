//
//		ファイル名:Douzou.h
//

#ifndef HEADER_DOUZOU_H
#define HEADER_DOUZOU_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "Gimmick.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Douzou : public Gimmick
{
    private:
        GameEngine::Behaviour::Transform*    _transform;
        float Move_Distance;
        D3DXVECTOR3 Move;
        D3DXVECTOR3 Move_Vector;

    public:
		Douzou();
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif