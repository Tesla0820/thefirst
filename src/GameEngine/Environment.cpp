//
//		ファイル名		：Enviroment.cpp
//

#include "Environment.h"
#include "Behaviour/Camera.h"
#include "Input.h"
#include "Sound/SoundManager.h"
#include "Resource/ResourceManager.h"

namespace GameEngine
{

using GameEngine::Scene::SceneManager;

static Environment* _instance;

constexpr int ScreenWidth = 1600;
constexpr int ScreenHeight = 1200;

Environment::Environment():
	_window(ScreenWidth + GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYBORDER),ScreenHeight + GetSystemMetrics(SM_CXBORDER)*2)
{
	D3DDEVTYPE devTypes[] =
	{
		D3DDEVTYPE_HAL,
		D3DDEVTYPE_HAL,
		D3DDEVTYPE_REF
	};

	DWORD behaviorType[] = 
	{
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING
	};
	constexpr DWORD adapter = D3DADAPTER_DEFAULT;
	D3DDISPLAYMODE dm;
	D3DPRESENT_PARAMETERS pp;
	
	_window.Show();

	_factory = std::make_unique<DXCT::D3D::D3DFactory>();

	//ディスプレイモード取得
	_factory->GetAdapterDisplayMode(adapter,&dm);

	ZeroMemory(&pp, sizeof(pp));				// ワークをゼロクリア
	pp.BackBufferCount = 1;						// バックバッファの数
	pp.BackBufferWidth = ScreenWidth;			// ゲーム画面サイズ(幅)
	pp.BackBufferHeight = ScreenHeight;			// ゲーム画面サイズ(高さ)
	pp.BackBufferFormat = dm.Format;			// バックバッファフォーマットはディスプレイモードに合わせて設定
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// 映像信号に同期してフリップする
	pp.Windowed = true;							// ウィンドウモード
	pp.EnableAutoDepthStencil = TRUE;			// デプスバッファ（Ｚバッファ）とステンシルバッファを作成
	pp.AutoDepthStencilFormat = D3DFMT_D24S8;	// デプスバッファとして24bit、ステンシルバッファとして8bitを使う
	// ウィンドウモード
	pp.FullScreen_RefreshRateInHz = 0;								// リフレッシュレート
	pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// 垂直同期信号に同期しない

	for (int i = 0; i < 3; i++)
	{
		_device = _factory->CreateDevice(D3DADAPTER_DEFAULT, devTypes[i], &_window, behaviorType[i], &pp);
		if ( _device ) break;
	}
	if (!_device)
	{
		throw std::runtime_error("can't construct a device.");
	}

	AttachPipeline(new Pipeline::DefaultPipeline());
	_currentScene = -1;
	_newScene = 0;
	_backColor = D3DCOLOR_ARGB(255, 0, 0, 64);
	//シーンマネージャの構築
	SceneManager::Create();

	//入力マネージャの構築
    Input::Create(_window.GetHandle());

	//サウンドマネージャの構築
	Sound::SoundManager::Create();

	//リソースマネージャの構築
	Resource::ResourceManager::Create();

	//FPSカウンター開始
	_counter.Start();
}
Environment::~Environment()
{
	//リソースマネージャの解放
	Resource::ResourceManager::Release();

	//サウンドマネージャの解放
	Sound::SoundManager::Release();

    //入力マネージャの解放
    Input::End();

	//シーンマネージャの解放
	SceneManager::Release();
	_device.reset();
	_factory.reset();
}



void Environment::Create()
{
	_instance = new Environment();
}

Environment* Environment::Get()
{
	return _instance;
}

void Environment::Release()
{
	delete _instance;
}

SIZE Environment::GetScreenSize()
{
	RECT rect;
	_window.GetPosition(&rect);
	SIZE size;
	size.cx = rect.right - rect.left;
	size.cy = rect.bottom - rect.top;
	return size;
}

std::shared_ptr<DXCT::D3D::D3DDevice> Environment::GetCurrentDevice()
{
	return _device;
}

int Environment::Run()
{
	MSG msg;
	//実行開始と共に最初のシーン読み込み
	SceneManager::LoadScene(0);
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{// PostQuitMessage()が呼ばれたらループ終了
				break;
			}
			else
			{
				// メッセージの翻訳とディスパッチ
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			_counter.Update();
			if (_counter.IsFrameChanged()) 
			{
				UpdateFrame();
			}
		}
	}
	return (int)msg.wParam;
}

void Environment::AttachPipeline(Pipeline::IModefier * modefier)
{
	if (_pipeline)
	{
		_pipeline->OnDetach(_device);
	}
	_pipeline.reset(modefier);

	if (_pipeline)
	{
		_pipeline->OnAttach(_device);
	}

}

Pipeline::IModefier * Environment::GetCurrentPipeline()
{
	return _pipeline.get();
}

void Environment::OnBeforeRenderer(D3DXMATRIX const & world)
{
	if (_pipeline)_pipeline->BeforeRenderer(_device,world);
}

void Environment::OnSetCamera(D3DXMATRIX const & view, D3DXMATRIX const & projection)
{
	if (_pipeline)_pipeline->OnSetCamera(_device, view, projection);
}

void Environment::SetBackColor(D3DCOLOR backColor)
{
	_backColor = backColor;
}

void Environment::UpdateFrame()
{
	Update();
	Draw();
}

void Environment::Update()
{
  Input::Update();
	SceneManager::Update();
}

void Environment::Draw()
{
	//前フレームの情報をクリア
	_device->Clear(0, NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL), _backColor, 1.0f, 0);
	// Direct3Dによる描画の開始
	if (_pipeline)_pipeline->BeforeScene(_device);
	if (SUCCEEDED(_device->BeginScene()))
	{
		SceneManager::Draw();
		// Direct3Dによる描画の終了
		_device->EndScene();
	}
	if (_pipeline)_pipeline->AfterScene(_device);
	// バックバッファとフロントバッファの入れ替え
	_device->Present(NULL, NULL, NULL, NULL);
}


}