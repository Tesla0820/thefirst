//
//		ファイル名:Hashira.h
//

#ifndef HEADER_HASHIRA_H
#define HEADER_HASHIRA_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../GameEngine/Behaviour/Renderer/MeshRenderer.h"
#include "../../../GameEngine/Behaviour/Transform.h"

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

//＝＝＝クラス宣言＝＝＝//
class Hashira : public GameEngine::Behaviour::Behaviour
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