//
//		�t�@�C����:GimmickFactory.h
//

#ifndef HEADER_GIMMICK_FACTORY_H
#define HEADER_GIMMICK_FACTORY_H

//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include <d3dx9math.h>
#include "../../../GameEngine/Behaviour/Behaviour.h"
#include "../../../GameEngine/Behaviour/Collider/BoxCollider.h"
#include "../../../GameEngine/Behaviour/Renderer/MeshRenderer.h"
#include "../../../GameEngine/Behaviour/Collider/ICollisionHandler.h"
#include "../../../GameEngine/Behaviour/Transform.h"

#include "Bell.h"
#include "Douzou.h"
#include "Hashira.h"
#include "Hashira_break.h"
#include "Toge.h"
#include "Toge_move.h"
#include "Yoroi.h"

namespace Game { namespace Behaviour
{

class GimmickFactory
{
    private:
        static void Instantiate(GameEngine::Behaviour::Behaviour*, D3DXVECTOR3*, D3DXVECTOR3*);

    public:
        static void InstantiateBell(D3DXVECTOR3*, D3DXVECTOR3*);
        static void InstantiateDouzou(D3DXVECTOR3*, D3DXVECTOR3*);
        static void GimmickFactory::InstantiateHashira(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
        static void GimmickFactory::InstantiateHashira_break(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
        static void GimmickFactory::InstantiateToge(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
        static void GimmickFactory::InstantiateToge_move(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
        static void GimmickFactory::InstantiateYoroi(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
};

}}

#endif