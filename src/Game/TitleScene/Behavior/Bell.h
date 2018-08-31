//
//		�t�@�C����:Bell.h
//

#ifndef HEADER_BELL_H
#define HEADER_BELL_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������萔�E�}�N����`������//
#define SHINE_TIME_BELL SHINE_TIME * 2


//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Bell : public Gimmick
{
    public:
        virtual void Start(void) override;
        virtual void Update(void) override;
        //GameEngine::Behaviour::Transform* Get(void) { return _transform; }

        // ICollisionHandler ����Čp������܂���
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif