//
//		ƒtƒ@ƒCƒ‹–¼:Texture.h
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
		std::shared_ptr<DXCT::D3D::D3DTexture> _texture;

	public:
		static constexpr char* ResourceType = "Texture";
		Texture(std::string path);
		// IResourceBase ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
		virtual std::string GetResourceType() override;

		// IResource ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
		virtual get_result Get() override;
};
}
}
#endif