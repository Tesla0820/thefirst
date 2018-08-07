//
//		ファイル名:dxct_inner.h
//		作成日時:2018/06/25 14:26:50
//

#ifndef HEADER_DXCT_INNER_H
#define HEADER_DXCT_INNER_H

//共通インクルードヘッダ
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

//内部定義
#ifndef DXCT_INTERFACE
#	define DXCT_INTERFACE	struct
#endif
#ifndef DXCT_ABSTRACT
#	define DXCT_ABSTRACT	class
#endif 

//セーフリリースマクロ
#ifndef SAFE_DELETE
#	define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#	define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#	define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif

#endif
