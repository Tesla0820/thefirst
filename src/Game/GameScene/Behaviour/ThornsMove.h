//
//		�t�@�C����:ThornsMove.h
//

#ifndef HEADER_THORNS_MOVE_H
#define HEADER_THORNS_MOVE_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class ThornsMove : public Gimmick
{
    private:
        GameEngine::Behaviour::Transform*    _transform;

    public:
        ThornsMove();
		virtual void Start(void) override;
        virtual void Update(void) override;
};

}}
#endif