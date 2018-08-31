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
        GameEngine::Behaviour::Transform*    _transform;
        bool _attack;

    public:
		Toge_move();
		virtual void Start(void) override;
        virtual void Update(void) override;

};

}}
#endif