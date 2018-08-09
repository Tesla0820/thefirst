//
//		ファイル名:GameObject.cpp
//

#include "GameObject.h"
#include "Scene/SceneManager.h"
namespace GameEngine
{

GameObject::GameObject()
{
	_parent = nullptr;
	_name = "";
	_enable = true;
	auto transform = new GameEngine::Behaviour::Transform();
	AddBehaviour(transform);
}

GameObject::~GameObject()
{

	for (auto behaviour : _behaviours)
	{
		delete behaviour;
	}
	for (auto object : _children)
	{
		object->Destroy();
	}
}

void GameObject::BindGameObject(GameObject * parent, GameObject * child)
{
	if (!child)return;
	if (child->_parent == parent)return;
	if (child->_parent)
	{
		//旧親からの参照を解除する
		child->_parent->RemoveChild(child);

	}
	else
	{
		//ルートからの参照を解除する
		Scene::SceneManager::RemoveObject(child);
	}
	//_child->_parentはnullptrのため親が存在するか、のみ判定する
	if (_parent)
	{
		//親はオブジェクト
		child->_parent = parent;
		_parent->_children.push_back(child);
	}
	else
	{	//親はルート
		child->_parent = nullptr;
		Scene::SceneManager::AddObject(child);
	}
	
}

void GameObject::SetEnable(bool enable)
{
	_enable = false;
}

void GameObject::SetParent(GameObject * object)
{
	BindGameObject(object, this);
}

void GameObject::AddChild(GameObject * object)
{
	BindGameObject(this, object);
}

void GameObject::RemoveChild(GameObject * object)
{
	auto iterator = std::find(_children.begin(), _children.end(), object);
	if (iterator == _children.end()) return; //一致する子オブジェクトが存在しなった。
	_children.erase(iterator);
	object->_parent = nullptr;
}

bool GameObject::GetEnable()
{
	return _enable;
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
	Binder::BindBehaviourToGameObject(this, behaviour);
}

GameEngine::Behaviour::Transform * GameObject::GetTransform()
{
	return FindBehaviour<GameEngine::Behaviour::Transform>();
}

std::vector<GameObject*> GameObject::GetChildren()
{
	return _children;
}

//子オブジェクトとアタッチされているビヘイビアの更新処理を実行します。
void GameObject::Update()
{
	if (!_enable) return;
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
	if (!_enable) return;
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
	if (!_enable) return;
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

void GameObject::Destroy()
{
	if (_parent)
	{
		_parent->RemoveChild(this);
	}

	delete this;
}

GameObject * GameObject::Instantiate()
{
	GameObject *object = new GameObject();
	Scene::SceneManager::AddObject(object);
	return object;
}

}