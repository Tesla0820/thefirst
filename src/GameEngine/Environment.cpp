//
//		ファイル名		：Enviroment.cpp
//

#include "Environment.h"
#include "Behaviour/Camera.h"
namespace GameEngine
{

static Environment* _instance;

constexpr int ScreenWidth = 800;
constexpr int ScreenHeight = 600;

Environment::Environment():_window(ScreenWidth + GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYBORDER),ScreenHeight + GetSystemMetrics(SM_CXBORDER)*2)
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

	// レンダーステートパラメータの設定
	_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				// カリングしない
	_device->SetRenderState(D3DRS_ZENABLE, FALSE);						// Zバッファを使用しない
	_device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// αブレンドを行う
	_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// αソースカラーの指定
	_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// αデスティネーションカラーの指定
	
	// サンプラーステートパラメータの設定
	_device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);		// テクスチャアドレッシング方法(U値)を設定
	_device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);		// テクスチャアドレッシング方法(V値)を設定
	_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);		// テクスチャ縮小フィルタモードを設定
	_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);		// テクスチャ拡大フィルタモードを設定
	
	// テクスチャステージステートの設定
	_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	// アルファブレンディング処理
	_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);	// 最初のアルファ引数
	_device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);	// ２番目のアルファ引数

	//ライティングの設定
	_device->SetRenderState(D3DRS_LIGHTING, FALSE);

	_currentScene = -1;
	_newScene = 0;
	_backColor = D3DCOLOR_ARGB(255, 0, 0, 64);
	Scene::SceneManager::Create();
	_sceneManager = Scene::SceneManager::Get();
	_counter.Start();
}
Environment::~Environment()
{
	Scene::SceneManager::Release();
	_device.reset();
	_factory.reset();
}

void Environment::Create()
{
	_instance=new Environment();
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

WPARAM Environment::Run()
{
	MSG msg;
	//実行開始と共に最初のシーン読み込み
	_sceneManager->LoadScene(0);
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

	timeEndPeriod(1);				// 分解能を戻す
	return msg.wParam;
}

void Environment::UpdateFrame()
{
	Update();
	Draw();
}

void Environment::Update()
{
	_sceneManager->Update();
}

void Environment::Draw()
{
	//前フレームの情報をクリア
	_device->Clear(0, NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL), _backColor, 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(_device->BeginScene()))
	{
		_sceneManager->Draw();
		// Direct3Dによる描画の終了
		_device->EndScene();
	}

	// バックバッファとフロントバッファの入れ替え
	_device->Present(NULL, NULL, NULL, NULL);
}


}