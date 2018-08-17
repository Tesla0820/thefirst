//
//		�t�@�C����		�FEnviroment.cpp
//

#include "Environment.h"
#include "Behaviour/Camera.h"
namespace GameEngine
{

using GameEngine::Scene::SceneManager;

static Environment* _instance;

constexpr int ScreenWidth = 800;
constexpr int ScreenHeight = 600;

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

	//�f�B�X�v���C���[�h�擾
	_factory->GetAdapterDisplayMode(adapter,&dm);

	ZeroMemory(&pp, sizeof(pp));				// ���[�N���[���N���A
	pp.BackBufferCount = 1;						// �o�b�N�o�b�t�@�̐�
	pp.BackBufferWidth = ScreenWidth;			// �Q�[����ʃT�C�Y(��)
	pp.BackBufferHeight = ScreenHeight;			// �Q�[����ʃT�C�Y(����)
	pp.BackBufferFormat = dm.Format;			// �o�b�N�o�b�t�@�t�H�[�}�b�g�̓f�B�X�v���C���[�h�ɍ��킹�Đݒ�
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// �f���M���ɓ������ăt���b�v����
	pp.Windowed = true;							// �E�B���h�E���[�h
	pp.EnableAutoDepthStencil = TRUE;			// �f�v�X�o�b�t�@�i�y�o�b�t�@�j�ƃX�e���V���o�b�t�@���쐬
	pp.AutoDepthStencilFormat = D3DFMT_D24S8;	// �f�v�X�o�b�t�@�Ƃ���24bit�A�X�e���V���o�b�t�@�Ƃ���8bit���g��
	// �E�B���h�E���[�h
	pp.FullScreen_RefreshRateInHz = 0;								// ���t���b�V�����[�g
	pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// ���������M���ɓ������Ȃ�

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
	//�V�[���}�l�[�W���̍\�z
	SceneManager::Create();
	_counter.Start();
}
Environment::~Environment()
{
	//�V�[���}�l�[�W���̉��
	SceneManager::Release();
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
	//���s�J�n�Ƌ��ɍŏ��̃V�[���ǂݍ���
	SceneManager::LoadScene(0);
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{// PostQuitMessage()���Ă΂ꂽ�烋�[�v�I��
				break;
			}
			else
			{
				// ���b�Z�[�W�̖|��ƃf�B�X�p�b�`
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

	timeEndPeriod(1);				// ����\��߂�
	return msg.wParam;
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

void Environment::OnBeforeRenderer(D3DXMATRIX const & world)
{
	if (_pipeline)_pipeline->BeforeRenderer(_device,world);
}

void Environment::OnSetCamera(D3DXMATRIX const & view, D3DXMATRIX const & projection)
{
	if (_pipeline)_pipeline->OnSetCamera(_device, view, projection);
}

void Environment::UpdateFrame()
{
	Update();
	Draw();
}

void Environment::Update()
{

	SceneManager::Update();
}

void Environment::Draw()
{
	//�O�t���[���̏����N���A
	_device->Clear(0, NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL), _backColor, 1.0f, 0);
	// Direct3D�ɂ��`��̊J�n
	if (_pipeline)_pipeline->BeforeScene(_device);
	if (SUCCEEDED(_device->BeginScene()))
	{
		SceneManager::Draw();
		// Direct3D�ɂ��`��̏I��
		_device->EndScene();
	}
	if (_pipeline)_pipeline->AfterScene(_device);
	// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�̓���ւ�
	_device->Present(NULL, NULL, NULL, NULL);
}


}