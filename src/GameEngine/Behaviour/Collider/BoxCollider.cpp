// BoxCollider.cpp

#include "BoxCollider.h"

#include "../Transform.h"

namespace GameEngine { namespace Behaviour
{
// ���S���W�Ƒ傫�����擾
BoxCollider::BoxCollider(D3DXVECTOR3 position, D3DXVECTOR3 scale) :Collider()
{
	_position = position;
	_scale = scale;
}

BoxCollider::~BoxCollider()
{
}

D3DXVECTOR3* BoxCollider::GetScale()
{
	return &_scale;
}

void BoxCollider::Hit()
{
	//�C�e���[�^�[���g�������[�v vector���g�����Ƃ��͊�{������
	for (auto iterator = _colliders.begin(); iterator != _colliders.end(); ++iterator)
	{
		if (*iterator == this) continue;//�����͏���
		BoxCollider *box = dynamic_cast<BoxCollider*>(*iterator);// ���I�ɃL���X�g�A����BoxCollider����Ȃ�������NULL(nullptr)���A���Ă���
		if (box)
		{
			this->HitToBox(box);
			continue;
		}

		SphereCollider *sphere = dynamic_cast<SphereCollider*>(*iterator);// ���I�ɃL���X�g�A����SphereCollider����Ȃ�������NULL(nullptr)���A���Ă���
		if (box)
		{
			this->HitToSphere(sphere);
			continue;
		}
	}
}

void BoxCollider::HitToSphere(SphereCollider* collider)
{
	GameObject* me;			// �������̃Q�[���I�u�W�F�N�g
	GameObject* other;		// ���葤�I�u�W�F�N�g
	float range;			// �����蔻��͈̔�
	float magnitude;		// �������瑊��܂ł̋����̓��
	D3DXVECTOR3 mePos[8], otherPos;	// �����Ƒ���(���_�z��)�̈ʒu
	D3DXVECTOR3 meScale;	// �����̑傫��
	float* otherRadius;		// ����̋��̔��a

	
	for (int i = 0; i < 8; i++)
		mePos[i] = this->_position;// �W�ɒ����̂̒��S���W���i�[
	meScale = this->_scale;
	otherPos = collider->GetAttachedObject()->GetTransform()->GetPosition;
	otherRadius = collider->GetRadius();

																		 // �����̂̏�̒��_�i�������玞�v���j
	mePos[0].x -= meScale.x / 2.0f;
	mePos[0].y += meScale.y / 2.0f;
	mePos[0].z -= meScale.z / 2.0f;
	mePos[1].x -= meScale.x / 2.0f;
	mePos[1].y += meScale.y / 2.0f;
	mePos[1].z += meScale.z / 2.0f;
	mePos[2].x += meScale.x / 2.0f;
	mePos[2].y += meScale.y / 2.0f;
	mePos[2].z += meScale.z / 2.0f;
	mePos[3].x += meScale.x / 2.0f;
	mePos[3].y += meScale.y / 2.0f;
	mePos[3].z -= meScale.z / 2.0f;
	// �����̂̉��̒��_�i�������玞�v���j
	mePos[4].x -= meScale.x / 2.0f;
	mePos[4].y -= meScale.y / 2.0f;
	mePos[4].z -= meScale.z / 2.0f;
	mePos[5].x -= meScale.x / 2.0f;
	mePos[5].y -= meScale.y / 2.0f;
	mePos[5].z += meScale.z / 2.0f;
	mePos[6].x += meScale.x / 2.0f;
	mePos[6].y -= meScale.y / 2.0f;
	mePos[6].z += meScale.z / 2.0f;
	mePos[7].x += meScale.x / 2.0f;
	mePos[7].y -= meScale.y / 2.0f;
	mePos[7].z -= meScale.z / 2.0f;

	range = 0.0f + *otherRadius;			// ����͈̔͂��擾 ���_�Ȃ̂Ŕ��a0.0f

	for (int i = 0; i < 8; i++)
	{
		magnitude = (mePos[i].x - otherPos.x)*(mePos[i].x - otherPos.x) + (mePos[i].y - otherPos.y)*(mePos[i].y - otherPos.y) + (mePos[i].z - otherPos.z)*(mePos[i].z - otherPos.z);
		if (magnitude <= range*range)
		{
			// �����̂̂W�̒��_�̂����ꂩ�ɓ�������
		}
	}

	D3DXVECTOR3 mePosSurface[24];		// �S�łP�̖ʂɂȂ�
	//��̖�
	mePosSurface[0] = mePos[0];
	mePosSurface[1] = mePos[1];
	mePosSurface[2] = mePos[2];
	mePosSurface[3] = mePos[3];
	// ���ʂ̖�		  
	mePosSurface[4] = mePos[4];
	mePosSurface[5] = mePos[0];
	mePosSurface[6] = mePos[3];
	mePosSurface[7] = mePos[7];
	// ���̖�		   
	mePosSurface[8] = mePos[5];
	mePosSurface[9] = mePos[1];
	mePosSurface[10] = mePos[0];
	mePosSurface[11] = mePos[4];
	// ���̖�		   
	mePosSurface[12] = mePos[5];
	mePosSurface[13] = mePos[1];
	mePosSurface[14] = mePos[2];
	mePosSurface[15] = mePos[6];
	// �E�̖�			
	mePosSurface[16] = mePos[7];
	mePosSurface[17] = mePos[3];
	mePosSurface[18] = mePos[2];
	mePosSurface[19] = mePos[6];
	// ���̖�			
	mePosSurface[20] = mePos[4];
	mePosSurface[21] = mePos[5];
	mePosSurface[22] = mePos[6];
	mePosSurface[23] = mePos[7];

	if (mePosSurface[0].z <= otherPos.z && mePosSurface[1].z >= otherPos.z && mePosSurface[1].x <= otherPos.x && mePosSurface[2].x >= otherPos.x && mePosSurface[2].z >= otherPos.z && mePosSurface[3].z <= otherPos.z && mePosSurface[3].x >= otherPos.x && mePosSurface[0].x <= otherPos.x && (mePosSurface[0].y <= otherPos.y + *otherRadius || mePosSurface[0].y >= otherPos.y + *otherRadius))
	{
		// ��ʂɓ�������
	}
	else if (mePosSurface[4].y <= otherPos.y && mePosSurface[5].y >= otherPos.y && mePosSurface[5].x <= otherPos.x && mePosSurface[6].x >= otherPos.x && mePosSurface[6].y >= otherPos.y && mePosSurface[7].y <= otherPos.y && mePosSurface[7].x >= otherPos.x && mePosSurface[4].x <= otherPos.x && (mePosSurface[4].z <= otherPos.z + *otherRadius || mePosSurface[4].z >= otherPos.z + *otherRadius))
	{
		// ���ʂ̖ʂɓ�������
	}
	else if (mePosSurface[8].y <= otherPos.y && mePosSurface[9].y >= otherPos.y && mePosSurface[9].z <= otherPos.z && mePosSurface[10].z >= otherPos.z && mePosSurface[10].y >= otherPos.y && mePosSurface[11].y <= otherPos.y && mePosSurface[11].z >= otherPos.z && mePosSurface[8].z <= otherPos.z && (mePosSurface[8].x <= otherPos.x + *otherRadius || mePosSurface[8].x >= otherPos.x + *otherRadius))
	{
		// ���̖ʂɓ�������
	}
	else if (mePosSurface[12].y <= otherPos.y && mePosSurface[13].y >= otherPos.y && mePosSurface[13].x <= otherPos.x && mePosSurface[14].x >= otherPos.x && mePosSurface[14].y >= otherPos.y && mePosSurface[15].y <= otherPos.y && mePosSurface[15].x >= otherPos.x && mePosSurface[12].x <= otherPos.x && (mePosSurface[12].z <= otherPos.z + *otherRadius || mePosSurface[12].z >= otherPos.z + *otherRadius))
	{
		// ���̖ʂɓ�������
	}
	else if (mePosSurface[16].y <= otherPos.y && mePosSurface[17].y >= otherPos.y && mePosSurface[17].z <= otherPos.z && mePosSurface[18].z >= otherPos.z && mePosSurface[18].y >= otherPos.y && mePosSurface[19].y <= otherPos.y && mePosSurface[19].z >= otherPos.z && mePosSurface[16].z <= otherPos.z && (mePosSurface[16].x <= otherPos.x + *otherRadius || mePosSurface[16].x >= otherPos.x + *otherRadius))
	{
		// �E�̖ʂɓ�������
	}
	else if (mePosSurface[20].z <= otherPos.z && mePosSurface[21].z >= otherPos.z && mePosSurface[21].x <= otherPos.x && mePosSurface[22].x >= otherPos.x && mePosSurface[22].z >= otherPos.z && mePosSurface[23].z <= otherPos.z && mePosSurface[23].x >= otherPos.x && mePosSurface[20].x <= otherPos.x && (mePosSurface[20].y <= otherPos.y + *otherRadius || mePosSurface[20].y >= otherPos.y + *otherRadius))
	{
		// ��ʂɓ�������
	}
}

void BoxCollider::HitToBox(BoxCollider* collider)
{

}


}
}