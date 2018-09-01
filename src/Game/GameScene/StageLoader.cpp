//
//		ƒtƒ@ƒCƒ‹–¼:StageLoader.cpp
//

#include <memory>
#include <fstream>
#include "StageLoader.h"

namespace Game
{

void StageLoader::LoadStage(std::string file)
{
	int width;
	int height;
	char temp[1024];
	std::ifstream stageFile;
	stageFile.open(file, std::ios::in);
	//‰¡•æ“¾
	stageFile.getline(temp, sizeof(temp));
	std::sscanf(temp, "%d", &width);
	//c•
	stageFile.getline(temp, sizeof(temp));
	std::sscanf(temp, "%d", &height);
	std::unique_ptr<int[]> stage(new int[width*height]);
	int currentIndex = 0;
	for (int y = 0; y < height; y++)
	{
		stageFile.getline(temp, sizeof(temp));
		char *current = temp;
		for (int x = 0; x < width; x++, currentIndex++)
		{
			std::sscanf(current, "%d", &stage[currentIndex]);
			current = std::strstr(current, ",")+1;
		}
	}
	stageFile.close();


	CreateStage(stage);
}

void StageLoader::CreateStage(std::unique_ptr<int[]>& stage)
{
	
}

}