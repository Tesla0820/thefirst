//
//		�t�@�C����:BronzeStatue.h
//

#ifndef HEADER_BROZE_SUTATUE_H
#define HEADER_BROZE_SUTATUE_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Gimmick.h"

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

//�������N���X�錾������//
class BronzeStatue : public Gimmick
{
    private:
        GameEngine::Behaviour::Transform*    _transform;    //���W�f�[�^
        D3DXVECTOR3 _start;                                 //�X�^�[�g�ʒu
        D3DXVECTOR3 _end;                                   //�܂�Ԃ��ʒu
        int         _ratio;                                 //�ړ��ςݔ䗦
        D3DXVECTOR3 _move_Current_Distance;                 //�݌v�ړ�����
        D3DXVECTOR3 _move_Distance;                         //�z��ړ�����

        D3DXVECTOR3 _move;                                  //�ړ���
        D3DXVECTOR3 _move_Vector;                           //�ړ�����
        FLOAT _default_Rotation;                            //�W������
        bool _checkRotate;                                  //�U������ςݔ���

    public:
        BronzeStatue(D3DXVECTOR3, D3DXVECTOR3, int);
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif