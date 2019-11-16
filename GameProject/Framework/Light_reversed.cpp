#include "stdafx.h"
#include "Light_reversed.h"
#include "Scene.h"

Light_reversed::Light_reversed(bool isAnimation)
	:GameObject(L"resources/Clicked/light_reversed.png")
{
	transform->position.y = 428.0f;
	this->isAnimation = isAnimation;
}

void Light_reversed::Update()
{
	renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Clicked/light_reversed.png", 0, 0), al);

	if (isAnimation)
	{
		al -= 0.04f;
		if (al > 0.0f)
		{
			transform->position.y += 3.0f;
			renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Clicked/light_reversed.png", 0, 0), al);
		}
		else
		{
			Scene::GetCurrentScene().Destroy(this);
		}
	}
}
