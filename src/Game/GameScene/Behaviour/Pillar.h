//
//		�t�@�C����:Pillar.h
//

#ifndef HEADER_PILLAR_H
#define HEADER_PILLAR_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Pillar : public Gimmick
{
    public:
        Pillar();
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif