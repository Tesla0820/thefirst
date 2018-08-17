//
//		ƒtƒ@ƒCƒ‹–¼:D3DXConstantTable.h
//

#ifndef HEADER_D3DXCONSTANT_TABLE_H
#define HEADER_D3DXCONSTANT_TABLE_H

#include "../D3D/D3DObject.h"


namespace DXCT
{
	namespace D3D
	{
		class D3DDevice;
	}
	namespace D3DX
	{

	class D3DXConstantTable : public D3D::D3DObject<ID3DXConstantTable>
	{
		private:
		D3DXConstantTable() = delete;


		public:
		D3DXConstantTable(ID3DXConstantTable* constantTable);
		HRESULT SetFloat(std::shared_ptr<D3D::D3DDevice> device, char* name,float value);
		HRESULT SetFloatArray(std::shared_ptr<D3D::D3DDevice> device, char* name,float const* value,unsigned int count);
		HRESULT SetMatrix(std::shared_ptr<D3D::D3DDevice> device, char* name,D3DXMATRIX const* matrix);
	};

	}
}
#endif