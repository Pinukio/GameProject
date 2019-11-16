#include "stdafx.h"
#include "FailedManager.h"
#include "Scene.h"
#include "InputManager.h"
#include "GameSceneHard.h"
#include "StartScene.h"
#include "Black.h"

FailedManager::FailedManager()
{
	arrow = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/Scene/Failed/arrow.png", Vector2(790.0f, 340.0f)));
}

void FailedManager::Update()
{
	if (InputManager::GetKeyDown(VK_DOWN))
	{
		if (selected != 2)
		{
			selected++;
			arrow->transform->SetPosition(arrow->transform->position.x, arrow->transform->position.y + 200.0f);
		}
		else
		{
			selected = 0;
			arrow->transform->SetPosition(arrow->transform->position.x, arrow->transform->position.y - 400.0f);
		}
	}

	else if (InputManager::GetKeyDown(VK_UP))
	{
		if (selected != 0)
		{
			selected--;
			arrow->transform->SetPosition(arrow->transform->position.x, arrow->transform->position.y - 200.0f);
		}
		else
		{
			selected = 2;
			arrow->transform->SetPosition(arrow->transform->position.x, arrow->transform->position.y + 400.0f);
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
			Scene::GetCurrentScene().PushBackGameObject(new Black(0)); // start
			break;
		case 2:
			Scene::GetCurrentScene().PushBackGameObject(new Black(5)); // exit
			break;
		}
	}
}