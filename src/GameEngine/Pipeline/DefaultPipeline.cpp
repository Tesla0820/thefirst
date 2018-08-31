#include "DefaultPipeline.h"
namespace GameEngine { namespace Pipeline
{

void DefaultPipeline::OnAttach(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
	
}

void DefaultPipeline::OnDetach(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{

}

void DefaultPipeline::OnSetCamera(std::shared_ptr<DXCT::D3D::D3DDevice> const & device, D3DXMATRIX const & view, D3DXMATRIX const & projection)
{
}

void DefaultPipeline::BeforeScene(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{

	// �����_�[�X�e�[�g�p�����[�^�̐ݒ�
	device->SetRenderState(D3DRS_LIGHTING,FALSE);						// ���C�g����
	device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				// �J�����O���Ȃ�
	device->SetRenderState(D3DRS_ZENABLE, TRUE);						// Z�o�b�t�@���g�p���Ȃ�
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// ���u�����h���s��
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);			// ���\�[�X�J���[�̎w��
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// ���f�X�e�B�l�[�V�����J���[�̎w��

	// �T���v���[�X�e�[�g�p�����[�^�̐ݒ�
	device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);		// �e�N�X�`���A�h���b�V���O���@(U�l)��ݒ�
	device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);		// �e�N�X�`���A�h���b�V���O���@(V�l)��ݒ�
	device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);		// �e�N�X�`���k���t�B���^���[�h��ݒ�
	device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);		// �e�N�X�`���g��t�B���^���[�h��ݒ�

	// �e�N�X�`���X�e�[�W�X�e�[�g�̐ݒ�
	device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	// �A���t�@�u�����f�B���O����
	device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);	// �ŏ��̃A���t�@����
	device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);	// �Q�Ԗڂ̃A���t�@����
	
	//���C�e�B���O�̐ݒ�
	device->SetRenderState(D3DRS_LIGHTING, FALSE);						
}

void DefaultPipeline::BeforeRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const & device, D3DXMATRIX const & world)
{
}

void DefaultPipeline::AfterRenderer(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
}

void DefaultPipeline::AfterScene(std::shared_ptr<DXCT::D3D::D3DDevice> const & device)
{
}

}
}