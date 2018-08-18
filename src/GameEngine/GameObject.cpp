//
//		�t�@�C����:GameObject.cpp
//

#include "GameObject.h"
#include "Scene/SceneManager.h"
#include "Behaviour/Behaviour.h"
#include "Behaviour/Transform.h"

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
	Destroy();
}

void GameObject::BindGameObject(GameObject * parent, GameObject * child)
{
	if (!child)return;
	if (child->_parent == parent)return;
	if (child->_parent)
	{
		//���e����̎Q�Ƃ���������
		child->_parent->RemoveChild(child);

	}
	else
	{
		//���[�g����̎Q�Ƃ���������
		Scene::SceneManager::RemoveObject(child);
	}
	//_child->_parent��nullptr�̂��ߐe�����݂��邩�A�̂ݔ��肷��
	if (_parent)
	{
		//�e�̓I�u�W�F�N�g
		child->_parent = parent;
		_parent->_children.push_back(child);
	}
	else
	{	//�e�̓��[�g
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
	if (iterator == _children.end()) return; //��v����q�I�u�W�F�N�g�����݂��Ȃ����B
	_children.erase(iterator);
	object->_parent = nullptr;
}

bool GameObject::GetEnable()
{
	bool result = _enable;
	if (_parent)
	{
		result &= _parent->GetEnable();
	}
	return result;
}

bool GameObject::GetEnableThis()
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

//�q�I�u�W�F�N�g�ƃA�^�b�`����Ă���r�w�C�r�A�̍X�V���������s���܂��B
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
	D3DXMATRIX currentMatrix = transform->GetWorldMatrix();
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
	D3DXMATRIX currentMatrix = transform->GetWorldMatrix();

	for (auto behavior : _behaviours)
	{

		behavior->Draw(currentMatrix);
	}

	for (auto object : _children)
	{
		object->Draw(currentMatrix);
	}
}

void GameObject::Destroy()
{
	if (_parent)
	{
		SetParent(nullptr);
	}
	while (!_behaviours.empty())
	{
		delete _behaviours.back();
		_behaviours.pop_back();
	}
}

GameObject * GameObject::Instantiate()
{
	GameObject *object = new GameObject();
	Scene::SceneManager::AddObject(object);
	return object;
}

}