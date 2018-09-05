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
	private:
		GameEngine::Behaviour::SoundPlay* _bell;
    public:
		Bell();
        virtual void Start(void) override;
        virtual void Update(void) override;
		virtual void OnCollision(GameEngine::Behaviour::Collider* collider) override;
};

}}
#endif