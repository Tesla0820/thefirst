//
//		ファイル名:Douzou.h
//

#ifndef HEADER_DOUZOU_H
#define HEADER_DOUZOU_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../GameEngine/Behaviour/Renderer/MeshRenderer.h"
#include "../../../GameEngine/Behaviour/Transform.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Douzou : public GameEngine::Behaviour::Behaviour
{
    private:
        GameEngine::Behaviour::Transform*    _transform;
        GameEngine::Behaviour::BoxCollider*  _collider;
        GameEngine::Behaviour::MeshRenderer* _mesh;

        float Move_Distance;
        float Move_Vector;

    public:
        virtual void Start() override;
        virtual void Update() override;
        GameEngine::Behaviour::Transform* Get() { return _transform; }
};

}}
#endif