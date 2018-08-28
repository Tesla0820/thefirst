//
//		�t�@�C����:Texture.h
//

#ifndef HEADER_TEXTURE_H
#define HEADER_TEXTURE_H

#include "../GameEngine_inner.h"
#include "IResource.h"


namespace GameEngine { namespace Resource
{
class Texture : public IResource<DXCT::D3D::D3DTexture>
{
	private:
		static constexpr char* _resourceType = "Texture";
		std::shared_ptr<DXCT::D3D::D3DTexture> _texture;

	public:
		Texture(std::string path);
		// IResourceBase ����Čp������܂���
		virtual std::string GetResourceType() override;

		// IResource ����Čp������܂���
		virtual get_shared_ptr Get() override;
};
}
}
#endif