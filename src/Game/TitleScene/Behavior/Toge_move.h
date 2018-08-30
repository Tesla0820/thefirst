//
//		�t�@�C����:Toge_move.h
//

#ifndef HEADER_TOGE_MOVE_H
#define HEADER_TOGE_MOVE_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Toge_move : public Gimmick
{
    private:
        bool _attack;

    public:
        virtual void Start(void) override;
        virtual void Update(void) override;

        // ICollisionHandler ����Čp������܂���
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif