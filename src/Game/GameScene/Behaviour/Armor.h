//
//		�t�@�C����:Armor.h
//

#ifndef HEADER_ARMOR_H
#define HEADER_ARMOR_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Armor : public Gimmick
{
    public:
        Armor();
        virtual void Start(void) override;
        virtual void Update(void) override;
};

}}
#endif