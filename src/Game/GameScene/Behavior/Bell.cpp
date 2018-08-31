//
//		�t�@�C����: Bell.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Bell.h"
#include "../../../GameEngine/Resource/Mesh/MeshD3DX.h"

namespace Game { namespace Behaviour
{

//�������֐���`������//
/////////////////////////////////////////////
//�֐����FStart
//
//�@�\�F�M�~�b�N�̏�����
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void Bell::Start(void)
{

}

/////////////////////////////////////////////
//�֐����FUpdate
//
//�@�\�F�M�~�b�N�̍X�V
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void Bell::Update(void)
{
    Gimmick::Update();
}

/////////////////////////////////////////////
//�֐����FOnCollision
//
//�@�\�F�����蔻��ɑ΂��鋓��
//
//�����F(GameEngine::Behaviour::Collider*)����
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void Bell::OnCollision(GameEngine::Behaviour::Collider* from)
{
    _time = SHINE_TIME_BELL;
    _renderer->SetRate(1.0F);
}

}}