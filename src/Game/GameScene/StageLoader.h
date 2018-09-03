//
//		ƒtƒ@ƒCƒ‹–¼:StageLoader.h
//

#ifndef HEADER_STAGE_LOADER_H
#define HEADER_STAGE_LOADER_H

#include "../../GameEngine/GameEngine.h"
#include <string>

namespace Game
{

enum StageDirection
{
	StageDirectionBottom,
	StageDirectionUp,
	StageDirectionFront,
	StageDirectionBack,
	StageDirectionLeft,
	StageDirectionRight,

};



struct StageVertex
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 normal;
};

class StageLoader
{
	private:
		static constexpr float _scale = 15.0f;
		static constexpr float _multiplyY = 7.0f;
		static void CreateStage(std::vector<int>& stage,int width,int depth);
		static void AddSideWalls(std::vector<StageVertex>& verticies, std::vector<int>& stage, int width, int depth, int x, int z);
		static void AddWall(std::vector<StageVertex>& verticies, StageDirection direction, int x, int z);

	public:
		static void LoadStage(std::string file);

};

}

#endif