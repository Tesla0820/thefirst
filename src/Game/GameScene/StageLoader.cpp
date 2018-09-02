//
//		ÉtÉ@ÉCÉãñº:StageLoader.cpp
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
	//â°ïùéÊìæ
	stageFile.getline(temp, sizeof(temp));
	std::sscanf(temp, "%d", &width);
	//ècïù
	stageFile.getline(temp, sizeof(temp));
	std::sscanf(temp, "%d", &height);
	std::vector<int> stage(width*height);
	for (int z = 0; z < height; z++)
	{
		stageFile.getline(temp, sizeof(temp));
		char *current = temp;
		for (int x = 0; x < width; x++)
		{
			std::sscanf(current, "%d", &stage[width*z+x]);
			current = std::strstr(current, ",")+1;
		}
	}
	stageFile.close();
	CreateStage(stage,width,height);
}

void StageLoader::CreateStage(std::vector<int>& stage, int width, int depth)
{
	std::vector<StageVertex> verticies;
	//create mesh
	for (int y = 1; y < depth-1; y++)
	{
		for (int x = 1; x < width-1; x++)
		{
			int index = width*y + x;
			switch (stage[index])
			{
				case 0:
					AddSideWalls(verticies, stage, width, depth, x, y);
					break;

				case 1:
					break;
				case 2:
					break;
			}


		}
	}

	GameEngine::GameObject* stageObject = GameEngine::GameObject::Instantiate();
	auto renderer = new GameEngine::Behaviour::MeshRenderer();
	renderer->SetMesh(std::shared_ptr<GameEngine::Resource::Mesh::IMesh>(new GameEngine::Resource::Mesh::Mesh<StageVertex>(verticies, D3DFVF_XYZ | D3DFVF_NORMAL, D3DPT_TRIANGLELIST)));
	stageObject->AddBehaviour(renderer);

	//create collider
	stageObject->AddBehaviour(new GameEngine::Behaviour::BoxCollider(D3DXVECTOR3(width*_scale/2.0f,1.0f,depth*_scale/2.0f), D3DXVECTOR3(width*_scale/2.0f, -0.5f, depth*_scale/2.0f), 0x0004));
}

void StageLoader::AddSideWalls(std::vector<StageVertex>& verticies, std::vector<int>& stage, int width, int depth, int x, int z)
{
	AddWall(verticies, StageDirectionBottom, x, z);
	if (stage[width*z + x + 1] == 1)
	{
		AddWall(verticies, StageDirectionLeft, x, z);
	}
	if (stage[width*z + x - 1] == 1)
	{
		AddWall(verticies, StageDirectionRight, x, z);
	}
	if (stage[width*(z + 1) + x] == 1)
	{
		AddWall(verticies, StageDirectionBack, x, z);
	}
	if (stage[width*(z - 1) + x ] == 1)
	{
		AddWall(verticies, StageDirectionFront, x, z);
	}
}

void StageLoader::AddWall(std::vector<StageVertex>& verticies, StageDirection direction, int x, int y)
{
	constexpr int verticiesCount = 6;
	StageVertex quads[verticiesCount] = 
	{
		{ D3DXVECTOR3( 0.5f,-0.5f, 0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f) },
		{ D3DXVECTOR3( 0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f) },
		{ D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f) },
		{ D3DXVECTOR3(-0.5f,-0.5f, 0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f) },
		{ D3DXVECTOR3( 0.5f,-0.5f, 0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f) },
		{ D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0.0f,1.0f,0.0f) }
	};

	D3DXMATRIX world;
	D3DXMatrixIdentity(&world);
	world._11 = _scale;
	world._22 = _scale*_multiplyY;
	world._33 = _scale;
	world._41 = x*_scale;
	world._42 = _scale*_multiplyY/2.0f;
	world._43 = y*_scale;
	D3DXMATRIX rot;
	switch (direction)
	{
		case StageDirectionBottom:
			D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, 0.0f, 0.0f);
			break;
		case StageDirectionUp:
			D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, D3DXToRadian(180.0f), 0.0f);
			break;
		case StageDirectionFront:
			D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, D3DXToRadian(90.0f), 0.0f);
			break;
		case StageDirectionBack:
			D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, D3DXToRadian(-90.0f), 0.0f);
			break;
		case StageDirectionLeft:
			D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, 0.0f, D3DXToRadian(90.0f));
			break;
		case StageDirectionRight:
			D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, 0.0f, D3DXToRadian(-90.0f));
			break;
	}

	D3DXMatrixMultiply(&world, &rot, &world);
	for (int i = 0; i < verticiesCount; i++)
	{
		StageVertex vertex = quads[i];
		D3DXVec3TransformCoord(&vertex.pos, &vertex.pos, &world);
		D3DXVec3TransformNormal(&vertex.normal, &vertex.normal, &rot);
		verticies.push_back(vertex);
	}
}

}