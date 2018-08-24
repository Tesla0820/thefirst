//
//		ファイル名:Gimmick_01.h
//

#ifndef HEADER_GIMMICK_01_H
#define HEADER_GIMMICK_01_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "../../../GameEngine/Behaviour/Behaviour.h"
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../GameEngine/Behaviour/Renderer/MeshRenderer.h"
#include "../../../GameEngine/Behaviour/Transform.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Gimmick_01 : public GameEngine::Behaviour::Behaviour
{
    private:
        GameEngine::Behaviour::Transform*    _transform;
        GameEngine::Behaviour::BoxCollider*  _collider;
        GameEngine::Behaviour::MeshRenderer* _mesh;

    public:
        virtual void Start(void) override;
        virtual void Update(void) override;
        GameEngine::Behaviour::Transform* Get(void) { return _transform; }
};

}}
#endif