//
//		�t�@�C����:BrokenPillar.h
//

#ifndef HEADER_BROKENPILLAR_H
#define HEADER_BROKENPILLAR_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class BrokenPillar : public Gimmick
{
    public:
        BrokenPillar();
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif