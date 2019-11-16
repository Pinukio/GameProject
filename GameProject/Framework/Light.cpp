#include "stdafx.h"
#include "Light.h"
#include "Scene.h"

Light::Light(bool isAnimation)
	:GameObject(L"resources/Clicked/light.png")
{
	transform->position.y = 652.0f;
	this->isAnimation = isAnimation;
}

void Light::Update()
{
	renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Clicked/light.png", 0, 0), al);

	if (isAnimation)
	{
		al -= 0.04f;
		if (al > 0.0f)
		{
			transform->position.y -= 3.0f;
			renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Clicked/light.png", 0, 0), al);
		}

		else
		{
			Scene::GetCurrentScene().Destroy(this);
		}
	}
}
