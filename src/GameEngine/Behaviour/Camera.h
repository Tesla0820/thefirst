//
//		ファイル名:Camera.h
//

#ifndef HEADER_CAMERA_H
#define HEADER_CAMERA_H

#include "../GameEngine_inner.h"
#include "../GameObject.h"
#include "../Environment.h"
#include "Behaviour.h"

namespace GameEngine { namespace Behaviour
{

class Camera :public Behaviour
{
	private:
	Transform* _transform;
	bool _isPerspective;
	float _zn;
	float _zf;

	//透視投影
	float _fovy;
	float _aspect;
	//並行投影
	float _width;
	float _height;

	static Camera* _currentCamera;

	public:
	Camera();
	virtual ~Camera();
	void SetCurrent();
	bool IsCurrent();
	void EnablePerspectiveMode(bool _enable);
	void SetPerspective(float fovy, float aspect);
	void SetOrtho(float width, float height);
	virtual void Start() override;
	virtual void BeforeDraw(D3DXMATRIX const &matrix) override;

	static Camera* GetCurrent();
};

}
}
#endif