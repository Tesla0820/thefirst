//
//		ファイル名:GimmickFactory.h
//

#ifndef HEADER_GIMMICK_FACTORY_H
#define HEADER_GIMMICK_FACTORY_H

//＝＝＝ヘッダファイル読み込み＝＝＝//
#include <d3dx9math.h>
#include "../../../GameEngine/Behaviour/Behaviour.h"
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../GameEngine/Behaviour/Renderer/MeshRenderer.h"
#include "../../../GameEngine/Behaviour/Collider/ICollisionHandler.h"
#include "../../../GameEngine/Behaviour/Transform.h"

#include "Armor.h"
#include "Bell.h"
#include "BrokenPillar.h"
#include "BronzeStatue.h"
#include "Pillar.h"
#include "Thorns.h"
#include "ThornsMove.h"

namespace Game { namespace Behaviour
{

class GimmickFactory
{
    private:
        static GameEngine::GameObject* Instantiate(GameEngine::Behaviour::Behaviour* behaviour, D3DXVECTOR3* position, D3DXVECTOR3* rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh> mesh);

    public:
        static void InstantiateArmor(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
        static void InstantiateBell(D3DXVECTOR3*, D3DXVECTOR3*);
        static void InstantiateBrokenPillar(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
        static void InstantiateBronzeStatue(D3DXVECTOR3*, D3DXVECTOR3*);
        static void InstantiatePillar(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
        static void InstantiateThorns(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
        static void InstantiateThornsMove(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
};

}}

#endif