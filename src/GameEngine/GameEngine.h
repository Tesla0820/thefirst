//
//		�t�@�C����:GameEngine.h
//

#ifndef HEADER_GAME_ENGINE_H
#define HEADER_GAME_ENGINE_H

//Core
#include "GameEngine_inner.h"
#include "Environment.h"
#include "GameObject.h"
#include "MainWindow.h"

//Behaviours
#include "Behaviour/Behaviour.h"
#include "Behaviour/Transform.h"
#include "Behaviour/Camera.h"
#include "Behaviour/SoundPlay.h"

//Behaviour/Renderer
#include "Behaviour/Renderer/RendererBase.h"
#include "Behaviour/Renderer/MeshRenderer.h"
#include "Behaviour/Renderer/UIRenderer.h"

//Behaviour/Collider
#include "Behaviour/Collider/Collider.h"
#include "Behaviour/Collider/BoxCollider.h"
#include "Behaviour/Collider/SphereCollider.h"

//Resource
#include "Resource/ResourceManager.h"
#include "Resource/Mesh/IMesh.h"
#include "Resource/Mesh/MeshD3DX.h"
#include "Resource/Texture.h"

//Sound
#include "Sound/Sound.h"
#include "Sound/SoundManager.h"
#endif