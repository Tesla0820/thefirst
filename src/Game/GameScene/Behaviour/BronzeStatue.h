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
		float _distance;									//�n�_�ƏI�_�Ԃ̋���
		float _currentPos;									//�n�_�ƏI�_�Ԃ̌��݋���
		D3DXVECTOR3 _origin;								//���_
		D3DXVECTOR3 _moveDirection;							//�ړ�����
		float _direction;									//���������̈ړ�����
		float _angle;
		bool _isInverse;										//���]�����ǂ���
    public:
        BronzeStatue(float,float,float);
        virtual void Start() override;
        virtual void Update() override;
};

}}
#endif