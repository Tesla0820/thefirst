//
//		�t�@�C����:StageManager.cpp
//

#include "StageManager.h"
#include "../../../GameEngine/GameEngine.h"
#include "../../../GameEngine/Input.h"
#include "../../../GameEngine/Scene/SceneManager.h"

namespace Game { namespace GameScene
{

int StageManager::_stage;

//=====================================================
// ���݂̃X�e�[�W�̔ԍ��̃Z�b�g
//=====================================================
void StageManager::SetStage(int stage)
{
	_stage = stage;
}

//=====================================================
// �X�e�[�W�̓ǂݍ��݁i_stage�̔ԍ����g���āj
//=====================================================
void StageManager::LoadStage()
{
	if (_stage >= _maxStage)
	{
		//���݂���X�e�[�W�����z�����Ƃ�
		_stage = 0;
		GameEngine::Scene::SceneManager::LoadScene(6);
		return;
	}
	else
	{
		//���̃X�e�[�W�ɑJ��
		GameEngine::Scene::SceneManager::LoadScene(1 + _stage);
	}
}

//=====================================================
//���̃X�e�[�W�֑J��
//=====================================================
void StageManager::NextStage()
{
	_stage++;
	LoadStage();
}
		
}
}