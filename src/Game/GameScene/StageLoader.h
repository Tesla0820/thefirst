//
//		ƒtƒ@ƒCƒ‹–¼:StageLoader.h
//

#ifndef HEADER_STAGE_LOADER_H
#define HEADER_STAGE_LOADER_H

#include "../../GameEngine/GameEngine.h"
#include <string>

namespace Game
{
	class StageLoader
	{
		private:
			

		public:
		static void CreateStage(std::unique_ptr<int[]>& stage);
		static void LoadStage(std::string file);

	};
}

#endif