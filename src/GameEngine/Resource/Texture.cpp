//
//		ƒtƒ@ƒCƒ‹–¼:Texture.cpp
//

#include "../Environment.h"
#include "Texture.h"

namespace GameEngine { namespace Resource
{


Texture::Texture(std::string path)
{
	auto device = Environment::Get()->GetCurrentDevice();
#ifdef UNICODE
	wchar_t widePath[1024];
	setlocale(LC_ALL,"");
	mbstowcs(widePath, path.c_str(), sizeof(widePath));

	_texture = device->CreateTextureFromFile(widePath);

#else
	_texture=device->CreateTextureFromFile(path.c_str());
#endif
}

std::string Texture::GetResourceType()
{
	return std::string(_resourceType);
}

Texture::get_shared_ptr Texture::Get()
{
	return _texture;
}

}
}