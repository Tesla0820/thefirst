//
//		�t�@�C����: Bell.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Bell.h"
#include "../../../GameEngine/Resource/Mesh/MeshD3DX.h"

namespace Game { namespace Behaviour
{

Bell::Bell()
	:Gimmick(Gimmick::defaultDuration*2)
{
}
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

}}