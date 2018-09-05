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
    _move_Distance = 0;
    _move = { 0.0F, 0.0F, 0.0F };
    _move_Vector = _transform->Back() * 0.1F;
    _attack = false;
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
    if(!_attack)
    {
        return;
    }

    _move = { 0.0F, 0.0F, 0.0F };
    _move += _move_Vector * (_move_Distance * 0.1F);
    _move_Distance++;

    if (_move_Distance >= 100)
    {
        _attack = false;
        return;
    }

    //�ړ��l�̔��f
    _transform->Offset(&_move);

    Gimmick::Update();
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
    Gimmick::OnCollision(from);
    _attack = true;
}

}
}