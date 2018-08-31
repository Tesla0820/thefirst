//
//		�t�@�C����:Douzou.h
//

#ifndef HEADER_DOUZOU_H
#define HEADER_DOUZOU_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class Douzou : public Gimmick
{
    private:
        float Move_Distance;
        D3DXVECTOR3 Move;
        D3DXVECTOR3 Move_Vector;

    public:
        virtual void Start() override;
        virtual void Update() override;

        // ICollisionHandler ����Čp������܂���
        virtual void OnCollision(GameEngine::Behaviour::Collider*) override;
};

}}
#endif