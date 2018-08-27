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
void Game::Behaviour::Douzou::Start(void)
{
    GameEngine::GameObject* model = GetAttachedObject();
    _transform = model->GetTransform();
    _mesh = new GameEngine::Behaviour::MeshRenderer();
    _mesh->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::MeshD3DX(TEXT("./data/model/gimmick_test.x"))));
    model->AddBehaviour(_mesh);
    //model->AddBehaviour(_collider);

    Move_Distance = 0.0F;
    Move_Vector = -0.1F;
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
void Game::Behaviour::Douzou::Update(void)
{
    //---�e��錾---//
    D3DXVECTOR3 position;
    D3DXQUATERNION rotate;

    position = _transform->GetPosition();
    rotate = _transform->GetRotation();
    position.z += Move_Vector;
    Move_Distance += 0.1F;
    if (Move_Distance >= 10.0F)
    {
        Move_Distance = 0;
        if (Move_Vector == 0.1F)
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, 0.0F, 0.0F, 0.0F);
        }
        else
        {
            D3DXQuaternionRotationYawPitchRoll(&rotate, D3DX_PI, 0.0F, 0.0F);
        }
        Move_Vector = -Move_Vector;
    }
    _transform->SetPosition(&position);
    _transform->SetRotation(&rotate);
    _collider->HitToBox(_collider);
}

}}