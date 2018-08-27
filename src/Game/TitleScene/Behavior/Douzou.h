//
//		�t�@�C����:Douzou.h
//

#ifndef HEADER_DOUZOU_H
#define HEADER_DOUZOU_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../GameEngine/Behaviour/Renderer/MeshRenderer.h"
#include "../../../GameEngine/Behaviour/Transform.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
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