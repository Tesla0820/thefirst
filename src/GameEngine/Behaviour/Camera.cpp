//
//		ƒtƒ@ƒCƒ‹–¼:Camera.cpp
//

#include "Camera.h"
#include "Transform.h"

namespace GameEngine { namespace Behaviour
{
Camera* Camera::_currentCamera;

Camera::Camera()
{
	Environment* environment = Environment::Get();
	SIZE screen=environment->GetScreenSize();
	_isPerspective = true;
	_zn=1.0f;
	_zf=1000000.0f;

	//“§Ž‹“Š‰e
	_fovy =D3DX_PI/4;
	_aspect =(float)screen.cx/(float)screen.cy;
	//•Às“Š‰e
	_width = (float)screen.cx;
	_height = (float)screen.cy;
}

Camera::~Camera()
{
}

void Camera::SetCurrent()
{
	_currentCamera = this;
}

bool Camera::IsCurrent()
{
	return _currentCamera == this;
}

void Camera::EnablePerspectiveMode(bool _enable)
{
	_isPerspective = _enable;
}

void Camera::SetPerspective(float fovy, float aspect)
{
	_fovy = fovy;
	_aspect = aspect;
}

void Camera::SetOrtho(float width, float height)
{
	_width = width;
	_height = height;
}

void Camera::Start()
{
	_transform = GetAttachedObject()->GetTransform();
}

void Camera::BeforeDraw(D3DXMATRIX const & matrix)
{
	D3DXVECTOR3 pos;
	D3DXQUATERNION rot;
	D3DXMATRIX posMtx, rotMtx;
	D3DXMATRIX camera,view, projection;
	if (!IsCurrent())return;
	Environment* environment = Environment::Get();
	auto device = environment->GetCurrentDevice();
	if (_isPerspective)
	{
		D3DXMatrixPerspectiveFovLH(&projection, _fovy, _aspect, _zn, _zf);
	}
	else
	{
		D3DXMatrixOrthoLH(&projection, _width, _height, _zn, _zf);
	}
	_transform = GetAttachedObject()->GetTransform();
	pos = _transform->GetPosition();
	rot = _transform->GetRotation();
	D3DXMatrixTranslation(&posMtx, pos.x, pos.y, pos.z);
	D3DXMatrixRotationQuaternion(&rotMtx, &rot);
	D3DXMatrixMultiply(&camera, &rotMtx, &posMtx);
	D3DXMatrixInverse(&view,NULL,&camera);



	device->SetTransform(D3DTS_VIEW, &view);
	device->SetTransform(D3DTS_PROJECTION, &projection);
	Environment::Get()->OnSetCamera(view, projection);
}

Camera * Camera::GetCurrent()
{
	return _currentCamera;
}

}
}