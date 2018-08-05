//
//		ƒtƒ@ƒCƒ‹–¼:Environment.h
//

#ifndef HEADER_ENVIRONMENT_H
#define HEADER_ENVIRONMENT_H

#include <vector>
#include <memory>
#include "GameEngine_inner.h"
#include "Scene/SceneManager.h"
#include "GameObject.h"
#include "MainWindow.h"
#include "Time/FPSCounter.h"

namespace GameEngine
{

class Environment
{
	private:
		std::unique_ptr<DXCT::D3D::D3DFactory> _factory;
		std::shared_ptr<DXCT::D3D::D3DDevice> _device;
		Time::FPSCounter _counter;
		Scene::SceneManager *_sceneManager;
		MainWindow _window;
		D3DCOLOR _backColor;
		bool _isWindowMode;
		int _currentScene;
		int _newScene;
		void UpdateFrame();
		void Update();
		void Draw();

	protected:
		Environment();
	public:
		~Environment();
		SIZE GetScreenSize();
		std::shared_ptr<DXCT::D3D::D3DDevice> GetCurrentDevice();
		WPARAM Run();

		static void Create();
		static void Release();
		static Environment* Get();
};

}
#endif