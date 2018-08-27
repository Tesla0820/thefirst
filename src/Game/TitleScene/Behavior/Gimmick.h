//
//		ファイル名:Gimmick.h
//

#ifndef HEADER_GIMMICK_H
#define HEADER_GIMMICK_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include <d3dx9math.h>
#include "../../../GameEngine/Behaviour/Behaviour.h"

#include "Bell.h"
#include "Douzou.h"
#include "Hashira.h"
#include "Hashira_break.h"
#include "Toge.h"
#include "Toge_move.h"
#include "Yoroi.h"

void InstantiateGimmick(GameEngine::Behaviour::Behaviour* behaviour, D3DXVECTOR3* position, float x, float y, float z)
{
    GameEngine::GameObject* gimmick = GameEngine::GameObject::Instantiate();
    gimmick->AddBehaviour(behaviour);
    gimmick->GetTransform()->SetPosition(position);
    gimmick->GetTransform()->SetRotation(D3DXQuaternionRotationYawPitchRoll(new D3DXQUATERNION, D3DXToRadian(x), D3DXToRadian(y), D3DXToRadian(z)));
}

#endif