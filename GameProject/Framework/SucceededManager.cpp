#include "stdafx.h"
#include "SucceededManager.h"
#include "Scene.h"
#include "InputManager.h"
#include "Black.h"

SucceededManager::SucceededManager()
{
	arrow = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/Scene/Failed/arrow.png", Vector2(1550.0f, 700.0f)));
}

void SucceededManager::Update()
{
	if (InputManager::GetKeyDown(VK_DOWN))
	{
		if (selected != 2)
		{
			selected++;
			arrow->transform->SetPosition(arrow->transform->position.x, arrow->transform->position.y + 100.0f);
		}
		else
		{
			selected = 0;
			arrow->transform->SetPosition(arrow->transform->position.x, arrow->transform->position.y - 200.0f);
		}
	}

	else if (InputManager::GetKeyDown(VK_UP))
	{
		if (selected != 0)
		{
			selected--;
			arrow->transform->SetPosition(arrow->transform->position.x, arrow->transform->position.y - 100.0f);
		}
		else
		{
			selected = 2;
			arrow->transform->SetPosition(arrow->transform->position.x, arrow->transform->position.y + 200.0f);
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
