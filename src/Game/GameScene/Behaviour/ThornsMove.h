//
//		�t�@�C����:ThornsMove.h
//

#ifndef HEADER_THORNS_MOVE_H
#define HEADER_THORNS_MOVE_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"
#include "../../../GameEngine/Behaviour/Collider/ICollisionHandler.h"

//�������萔�E�}�N����`������//
#define MOVE_DISTANCE 5.0F

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class ThornsMove : public Gimmick, GameEngine::Behaviour::ICollisionHandler
{
    private:
        GameEngine::Behaviour::Transform*    _transform;
        GameEngine::Behaviour::BoxCollider*  _collider;

        float Move_Distance;
        D3DXVECTOR3 Move;
        D3DXVECTOR3 Move_Vector;
        bool _move;

    public:
        ThornsMove();
		virtual void Start(void) override;
        virtual void Update(void) override;

        // ICollisionHandler ����Čp������܂���
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif