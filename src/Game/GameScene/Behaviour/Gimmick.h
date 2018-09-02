//
//		�t�@�C����:Gimmick.h
//

#ifndef HEADER_GIMMICK_H
#define HEADER_GIMMICK_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include <d3dx9math.h>
#include "../../../GameEngine/Behaviour/Behaviour.h"
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../Game/Common/MeshRendererEx.h"
#include "../../../GameEngine/Behaviour/Collider/ICollisionHandler.h"
#include "../../../GameEngine/Behaviour/Transform.h"

//�������萔�E�}�N����`������//
#define SHINE_TIME 120

//�������N���X�錾������//
namespace Game { namespace Behaviour
{

class Gimmick : public GameEngine::Behaviour::Behaviour, public GameEngine::Behaviour::ICollisionHandler
{
    protected:
		bool _isShining;
		int _duration;
        int _maxDuration;

        GameEngine::Behaviour::BoxCollider*  _collider;
        Game::MeshRendererEx*                _renderer;

        Gimmick(int maxDuration);
		virtual void Start() override;
		virtual void Update() override;
		virtual void OnCollision(GameEngine::Behaviour::Collider * from) override;
	public:
		static constexpr int defaultDuration = 200;
};

}}
#endif