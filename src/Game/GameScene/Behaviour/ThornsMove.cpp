//
//		�t�@�C����:Toge_move.cpp
//

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "ThornsMove.h"

namespace Game { namespace Behaviour
{

ThornsMove::ThornsMove():Gimmick(Gimmick::defaultDuration)
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
void ThornsMove::Start(void)
{
    Gimmick::Start();

    _transform = GetAttachedObject()->GetTransform();
    Move_Distance = 0.0F;
    Move = { 0.0F, 0.0F, 0.0F };
    Move_Vector = _transform->Front();

    //�Z�b�g�n���h���[
    //GameEngine::Behaviour::BoxCollider::SetHandler(this);
    _move = false;
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
void ThornsMove::Update(void)
{

    if(!_move)
    {
        return;
    }

    Move = { 0.0F, 0.0F, 0.0F };
    Move += Move_Vector;
    Move_Distance += 0.1F;

    if (Move_Distance >= MOVE_DISTANCE)
    {
        _move = false;
        return;
    }

    //�ړ��l�̔��f
    _transform->Offset(&Move);

}

/////////////////////////////////////////////
//�֐����FOnCollision
//
//�@�\�F�M�~�b�N�̍X�V
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void ThornsMove::OnCollision(GameEngine::Behaviour::Collider* from)
{
    _move = true;
}

}}