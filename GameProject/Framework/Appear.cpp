#include "stdafx.h"
#include "Appear.h"
#include "Scene.h"
#include <time.h>

Appear::Appear()
{
	black = new GameObject(L"resources/background/black.png", Vector2(1920 / 2.0f, 1080 / 2.0f));
	Scene::GetCurrentScene().PushBackGameObject(black);
}

void Appear::Update()
{
	if (al >= 0.0f)
	{
		black->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/background/black.png", 0, 0), al);
		al -= 0.02f;
	}
	else
	{
		Scene::GetCurrentScene().Destroy(this);
	}
}

