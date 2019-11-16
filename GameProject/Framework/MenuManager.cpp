#include "stdafx.h"
#include "MenuManager.h"
#include "InputManager.h"
#include "Scene.h"
#include "GameSceneHard.h"
#include "GameSceneStory.h"
#include "Black.h"

MenuManager::MenuManager()
	:GameObject(L"resources/Scene/Start/selected.png")
{
	transform->SetPosition(1490.0f, 600.0f);
}

void MenuManager::Update()
{
	if (InputManager::GetKeyDown(VK_DOWN))
	{
		if (this->selected != 2)
		{
			transform->SetPosition(1490.0f, this->transform->position.y + 60.0f);
			selected++;
		}
		else
		{
			transform->SetPosition(1490.0f, this->transform->position.y - 120.0f);
			selected = 0;
		}
	}

	else if (InputManager::GetKeyDown(VK_UP))
	{
		if (this->selected != 0)
		{
			transform->SetPosition(1490.0f, this->transform->position.y - 60.0f);
			selected--;
		}
		else
		{
			transform->SetPosition(1490.0f, this->transform->position.y + 120.0f);
			selected = 2;
		}
	}
	else if (InputManager::GetKeyDown(VK_RETURN) || InputManager::GetKeyDown(VK_SPACE))
	{
		switch (selected)
		{
		case 0:
			Scene::GetCurrentScene().PushBackGameObject(new Black(1)); // hard
			break;
		case 1:
			Scene::GetCurrentScene().PushBackGameObject(new Black(2)); // story
			break;
		case 2:
			Scene::GetCurrentScene().PushBackGameObject(new Black(5)); // exit
			break;
		}
	}
}

