//
//		�t�@�C����:Thorns.h
//

#ifndef HEADER_THORNS_H
#define HEADER_THORNS_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Thorns : public Gimmick
{
    public:
        Thorns();
        virtual void Start(void) override;
        virtual void Update(void) override;
};

}}
#endif