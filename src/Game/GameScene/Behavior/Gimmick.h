//
//		ファイル名:Gimmick.h
//

#ifndef HEADER_GIMMICK_H
#define HEADER_GIMMICK_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include <d3dx9math.h>
#include "../../../GameEngine/Behaviour/Behaviour.h"
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../Game/Common/MeshRendererEx.h"
#include "../../../GameEngine/Behaviour/Collider/ICollisionHandler.h"
#include "../../../GameEngine/Behaviour/Transform.h"

//＝＝＝定数・マクロ定義＝＝＝//
#define SHINE_TIME 120.0F

//＝＝＝クラス宣言＝＝＝//
namespace Game { namespace Behaviour
{

class Gimmick : public GameEngine::Behaviour::Behaviour, public GameEngine::Behaviour::ICollisionHandler
{

    protected:
		bool _isShining;
		int _duration;
        GameEngine::Behaviour::Transform*    _transform;
        GameEngine::Behaviour::BoxCollider*  _collider;
        Game::MeshRendererEx*                _renderer;

		virtual void Start() override;
		virtual void Update() override;
		virtual void OnCollision(GameEngine::Behaviour::Collider * from) override;
		static constexpr int maxDuration = 300;
};

}}
#endif