//
//		�t�@�C����:Hashira.h
//

#ifndef HEADER_HASHIRA_H
#define HEADER_HASHIRA_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Hashira : public Gimmick
{
    public:
        virtual void Start() override;
        virtual void Update() override;

        // ICollisionHandler ����Čp������܂���
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif