//
//		�t�@�C����:Douzou.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Douzou.h"
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
void Douzou::Start(void)
{
    GameEngine::GameObject* model = GetAttachedObject();
    _transform = model->GetTransform();
    _renderer = new Game::MeshRendererEx();
    _renderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/gimmick_test.x"))));
    model->AddBehaviour(_renderer);
    _time = 0;

    Move_Distance = 0.0F;
    Move = { 0.0F, 0.0F, 0.0F };
    Move_Vector = _transform->Front();
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
void Douzou::Update(void)
{
    //---�e��錾---//
    D3DXVECTOR3 position;
    D3DXQUATERNION rotate;

    //�ړ�
    Move = { 0.0F, 0.0F, 0.0F };
    Move += Move_Vector;
    Move_Distance += 0.1F;

    //���]����
    if (Move_Distance >= 10.0F)
    {
        Move_Distance = 0.0F;
        if (Move_Vector == _transform->Front())
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, 0.0F, 0.0F, 0.0F);
            Move_Vector = _transform->Back();
        }
        else
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, D3DX_PI, 0.0F, 0.0F);
            Move_Vector = _transform->Front();
        }
    }

    //�ړ��l�̔��f
    _transform->Offset(&Move);
    _transform->SetRotation(&rotate);

    if (_time)
    {
        _time--;
    }
    _renderer->SetRate((float)_time / SHINE_TIME);
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
void Douzou::OnCollision(GameEngine::Behaviour::Collider* from)
{
    _time = SHINE_TIME;
    _renderer->SetRate(1.0F);
}

}}