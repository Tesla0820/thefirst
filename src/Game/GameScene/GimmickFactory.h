//
//		ファイル名:GimmickFactory.h
//

#ifndef HEADER_GIMMICK_FACTORY_H
#define HEADER_GIMMICK_FACTORY_H

//＝＝＝ヘッダファイル読み込み＝＝＝//

#include "../../GameEngine/GameEngine.h"

#include "Behaviour/Armor.h"
#include "Behaviour/Bell.h"
#include "Behaviour/BrokenPillar.h"
#include "Behaviour/BronzeStatue.h"
#include "Behaviour/Pillar.h"
#include "Behaviour/Thorns.h"
#include "Behaviour/ThornsMove.h"

namespace Game { namespace GameScene 
{

class GimmickFactory
{
	private:
	static GameEngine::GameObject* Instantiate(GameEngine::Behaviour::Behaviour* behaviour, D3DXVECTOR3* position, D3DXVECTOR3* rotate, std::shared_ptr<GameEngine::Resource::Mesh::IMesh> mesh);

	public:
	static void InstantiateArmor(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
	static void InstantiateBell(D3DXVECTOR3*, D3DXVECTOR3*);
	static void InstantiateBrokenPillar(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
    static void InstantiateBronzeStatue(D3DXVECTOR3* position, D3DXVECTOR3* rotate, float distance,float rate);
    static void InstantiatePillar(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
	static void InstantiateThorns(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
	static void InstantiateThornsMove(D3DXVECTOR3* position, D3DXVECTOR3* rotate);
};

}
}

#endif