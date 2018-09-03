//
//		�t�@�C����:ThornsMove.h
//

#ifndef HEADER_THORNS_MOVE_H
#define HEADER_THORNS_MOVE_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"
#include "../../../GameEngine/Behaviour/Collider/ICollisionHandler.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class ThornsMove : public Gimmick
{
    private:
        GameEngine::Behaviour::Transform*    _transform;

        float _move_Distance;
        D3DXVECTOR3 _move;
        D3DXVECTOR3 _move_Vector;
        bool _attack;

    public:
        ThornsMove();
		virtual void Start(void) override;
        virtual void Update(void) override;

        // ICollisionHandler ����Čp������܂���
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif