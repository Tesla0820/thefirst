//
//		�t�@�C����:Yoroi.h
//

#ifndef HEADER_YOROI_H
#define HEADER_YOROI_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Yoroi : public Gimmick
{
    public:
        virtual void Start(void) override;
        virtual void Update(void) override;

        // ICollisionHandler ����Čp������܂���
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif