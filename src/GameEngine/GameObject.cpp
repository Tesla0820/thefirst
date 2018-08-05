//
//		ƒtƒ@ƒCƒ‹–¼:GameObject.cpp
//

#include "GameObject.h"
#include "Scene/SceneManager.h"
namespace GameEngine
{

GameObject::GameObject()
{
	_name = "";
	auto transform = new GameEngine::Behaviour::Transform();
	_behaviours.push_back(transform);
}

GameObject::~GameObject()
{

	for (auto behaviour : _behaviours)
	{
		delete behaviour;
	}
	for (auto object : _children)
	{
		delete object;
	}
}

GameObject* GameObject::GetParent()
{
	return _parent;
}

GameObject* GameObject::GetChild(int index)
{
	return _children[index];

}

void GameObject::AddBehaviour(Behaviour::Behaviour * behaviour)
{
	GameObject* object = behaviour->GetTarget();
	if (object)return;
	behaviour->SetTarget(this);
	_behaviours.push_back(behaviour);
}

GameEngine::Behaviour::Transform * GameObject::GetTransform()
{
	return FindBehaviour<GameEngine::Behaviour::Transform>();
}

std::vector<GameObject*> GameObject::GetChildren()
{
	return _children;
}

void GameObject::Start()
{
	for (auto behaviour : _behaviours)
	{
		behaviour->Start();
	}
	for (auto object : _children)
	{
		object->Start();
	}
}

void GameObject::Update()
{
	for (auto behaviour : _behaviours)
	{
		behaviour->Update();
	}
	for (auto object : _children)
	{
		object->Update();
	}
}

void GameObject::BeforeDraw(D3DXMATRIX const& mtx)
{
	GameEngine::Behaviour::Transform* transform = FindBehaviour<GameEngine::Behaviour::Transform>();
	D3DXMATRIX currentMatrix = transform->GetMatrix();
	D3DXMATRIX temp;
	D3DXMatrixMultiply(&temp, &mtx, &currentMatrix);

	for (auto behavior : _behaviours)
	{

		behavior->BeforeDraw(temp);
	}

	for (auto object : _children)
	{
		object->BeforeDraw(temp);
	}
}

void GameObject::Draw(D3DXMATRIX const& mtx)
{
	GameEngine::Behaviour::Transform* transform = FindBehaviour<GameEngine::Behaviour::Transform>();
	D3DXMATRIX currentMatrix = transform->GetMatrix();
	D3DXMATRIX temp;
	D3DXMatrixMultiply(&temp, &mtx, &currentMatrix);

	for (auto behavior : _behaviours)
	{

		behavior->Draw(temp);
	}

	for (auto object : _children)
	{
		object->Draw(temp);
	}
}

void GameObject::End()
{
}

void GameObject::Destroy()
{


}

GameObject * GameObject::Instantiate()
{
	GameObject *object = new GameObject();
	Scene::SceneManager::Get()->AddObject(object);
	return object;
}

}