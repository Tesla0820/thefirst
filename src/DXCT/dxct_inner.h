//
//		�t�@�C����:dxct_inner.h
//		�쐬����:2018/06/25 14:26:50
//

#ifndef HEADER_DXCT_INNER_H
#define HEADER_DXCT_INNER_H

//���ʃC���N���[�h�w�b�_
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

//������`
#ifndef DXCT_INTERFACE
#	define DXCT_INTERFACE	struct
#endif
#ifndef DXCT_ABSTRACT
#	define DXCT_ABSTRACT	class
#endif 

//�Z�[�t�����[�X�}�N��
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
