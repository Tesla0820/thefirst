//�������w�b�_�t�@�C���ǂݍ��݁�����//
#include "Input.h"

namespace GameEngine {

//------//
std::shared_ptr<DXCT::DInput::DInputFactory> Input::_factory;	//�Ǘ��C���^�[�t�F�[�X
GameEngine::InputManager::Keyboard           Input::_keyboard;	//�L�[�{�[�h


Input::Input()
{
}

void Input::Release()
{
}

//�������֐���`������//
/////////////////////////////////////////////
//�֐����FCreate
//
//�@�\�F�f�o�C�X�̏�����
//
//�����F(HWND)�n���h��
//
//�߂�l�F(LRESULT)�����̐���
/////////////////////////////////////////////
HRESULT GameEngine::Input::Create(HWND hWnd)
{
	//---�e��錾---//
	HRESULT hr;

	//DirectInput�I�u�W�F�N�g����
	_factory = DXCT::DInput::DInputFactory::Create();
	if (!_factory)
	{
		MessageBoxA(hWnd, "DirectInput�I�u�W�F�N�g�����Ɏ��s���܂����B", "ERROR", MB_ICONSTOP | MB_OK);
		return S_FALSE;
	}

	//�L�[�{�[�h�̏���
	hr = _keyboard.Create(hWnd, _factory);
	if (FAILED(hr))
	{
		End();
		return hr;
	}

	return hr;
}

//////////////////////////////////2///////////
//�֐����FEnd
//
//�@�\�F�f�o�C�X�̏I��
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void  GameEngine::Input::End(void)
{
	_keyboard.End();
	SAFE_RELEASE(_factory);
}

/////////////////////////////////////////////
//�֐����FUpdate
//
//�@�\�F���͏��̍X�V
//
//�����F�Ȃ�
//
//�߂�l�F�Ȃ�
/////////////////////////////////////////////
void GameEngine::Input::Update(void)
{
	_keyboard.Update();
}

/////////////////////////////////////////////
//�֐����FGetKey
//
//�@�\�F�L�[�{�[�h���͔���
//
//�����F(DWORD)���̓{�^��,(PUSH_TYPE)����^�C�v
//
//�߂�l�F(bool)���茋��
/////////////////////////////////////////////
bool GameEngine::Input::GetKey(DWORD button, PUSH_TYPE type)
{
	switch (type)
	{
		case HOLD:
			return _keyboard.GetHold(button);

		case TRIGGER:
			return _keyboard.GetTrigger(button);

		case RELEASE:
			return _keyboard.GetRelease(button);

		default:
			return false;
	}
}

}