#include "stdafx.h"
#include "Black.h"
#include "Scene.h"
#include "FailedScene.h"
#include "StartScene.h"
#include "GameSceneHard.h"
#include "GameSceneStory.h"
#include "SucceededScene.h"
#include <time.h>

Black::Black(unsigned short num, bool isStory)
	:isStory(isStory)
{
	black = new GameObject(L"resources/background/black.png", Vector2(1920 / 2.0f, 1080 / 2.0f));
	Scene::GetCurrentScene().PushBackGameObject(black);
	this->num = num;
	if (num == 3)
	{
		tmp = 0.2f;
		tmp2 = 0.004f;
	}
}

Black::Black(unsigned short perfect, unsigned short great, unsigned short miss, bool isStory)
	:perfect(perfect), great(great), miss(miss), isStory(isStory)
{
	black = new GameObject(L"resources/background/black.png", Vector2(1920 / 2.0f, 1080 / 2.0f));
	Scene::GetCurrentScene().PushBackGameObject(black);
	this->num = 4;
	tmp = 0.2f;
	tmp2 = 0.004f;
}

void Black::Update()
{
	if (al <= tmp)
	{
		black->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/background/black.png", 0, 0), al);
			al += tmp2;
	}
	else
	{
		switch (num)
		{
		case 0:
			Scene::GetCurrentScene().ChangeScene(new StartScene());
			break;
		case 1:
			Scene::GetCurrentScene().ChangeScene(new GameSceneHard());
			break;
		case 2:
			Scene::GetCurrentScene().ChangeScene(new GameSceneStory());
			break;
		case 3:
			Scene::GetCurrentScene().ChangeScene(new FailedScene(isStory));
			break;
		case 4:
			Scene::GetCurrentScene().ChangeScene(new SucceededScene(perfect, great, miss, isStory));
			break;
		case 5:
			exit(0);
			break;
		}
	}
}

