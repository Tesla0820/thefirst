//
//		�t�@�C����:Hashira_break.h
//

#ifndef HEADER_HASHIRA_BREAK_H
#define HEADER_HASHIRA_BREAK_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Hashira_break : public Gimmick
{

public:
	Hashira_break();
    virtual void Start() override;
    virtual void Update() override;

};

}}
#endif