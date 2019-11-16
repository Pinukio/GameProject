#include "stdafx.h"
#include "StartScene.h"
#include "MenuManager.h"
#include "Appear.h"

void StartScene::Initialize()
{
	PushBackGameObject(new GameObject(L"resources/Scene/Start/startScene.png", Vector2(1920 / 2.0f, 1080 / 2.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Start/hard.png", Vector2(1584.0f, 600.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Start/story.png", Vector2(1584.0f, 660.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Start/finish.png", Vector2(1584.0f, 720.0f)));
	PushBackGameObject(new MenuManager());
	PushBackGameObject(new Appear());
}
