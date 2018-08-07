//
//		�t�@�C����:IRecoveryable.h
//

#ifndef HEADER_IRECOVERABLE_H
#define HEADER_IRECOVERABLE_H

#include "../dxct_inner.h"

namespace DXCT { namespace D3D 
{

//Direct3D9�Ŕ�������f�o�C�X���X�g�̕��A���J�j�Y����񋟂��܂��B
DXCT_INTERFACE IRecoverable
{
	virtual void Recovery(IRecoverable * origin) = 0;	//�f�o�C�X���X�g���畜�A���܂��B
	virtual void BackUp() = 0;							//���A�̂��߂̏����������s���܂��B
};

}
}
#endif