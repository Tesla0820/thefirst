//
//		�t�@�C����:Bell.h
//

#ifndef HEADER_BELL_H
#define HEADER_BELL_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../GameEngine/Behaviour/Renderer/MeshRenderer.h"
#include "../../../GameEngine/Behaviour/Transform.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Bell : public GameEngine::Behaviour::Behaviour
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