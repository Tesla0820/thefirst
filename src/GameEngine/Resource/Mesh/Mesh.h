//
//		ƒtƒ@ƒCƒ‹–¼:Mesh.h
//		ì¬“ú:2018/09/01 18:34:10
//

#ifndef HEADER_MESH_H
#define HEADER_MESH_H

#include "../../GameEngine_inner.h"
#include "../../Environment.h"
#include <memory>
#include "IMesh.h"

namespace GameEngine { namespace Resource { namespace Mesh
{

template<typename T>
class Mesh:public IMesh
{
	private:
		std::unique_ptr<T[]> _verticies;
		D3DPRIMITIVETYPE _primtiveType;
		unsigned long _fvf;
		unsigned int _primitiveCount;
	public:
		Mesh(std::vector<T>& verticies, unsigned long fvf, D3DPRIMITIVETYPE primitiveType);


		// IMesh ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
		virtual void Setup() override;
		virtual void Draw() override;
};

template<typename T>
Mesh<T>::Mesh(std::vector<T>& verticies,unsigned long fvf,D3DPRIMITIVETYPE primitiveType)
{
	int size =verticies.size();
	_verticies.reset(new T[size]);
	for (int i=0;i<size;i++)
	{
		_verticies[i] = verticies[i];
	}

	_fvf = fvf;
	_primtiveType = primitiveType;
	switch (primitiveType)
	{
		case D3DPT_POINTLIST:
			_primitiveCount = size;
			break;
		case D3DPT_LINELIST:
			_primitiveCount = size / 2;
			break;
		case D3DPT_LINESTRIP:
			_primitiveCount = size - 1;
			break;
		case D3DPT_TRIANGLELIST:
			_primitiveCount = size / 3;
			break;
		case D3DPT_TRIANGLESTRIP:
		case D3DPT_TRIANGLEFAN:
			_primitiveCount = size - 2;
			break;
	}
}

template<typename T>
void Mesh<T>::Setup()
{
	auto device = GameEngine::Environment::Get()->GetCurrentDevice();
	device->SetFVF(_primtiveType);
}

template<typename T>
void Mesh<T>::Draw()
{
	auto device = GameEngine::Environment::Get()->GetCurrentDevice();
	device->DrawPrimitiveUP(_primtiveType, _primitiveCount, _verticies.get(), sizeof(T));
}

}
}
}
#endif