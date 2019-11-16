#include "stdafx.h"
#include "FailedScene.h"
#include "FailedManager.h"
#include "Appear.h"
#include <time.h>

void FailedScene::Initialize()
{
	PushBackGameObject(new GameObject(L"resources/background/black.png", Vector2(1920 / 2.0f, 1080 / 2.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Failed/restart.png", Vector2(990.0f, 340.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Failed/select.png", Vector2(990.0f, 540.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Failed/finish.png", Vector2(990.0f, 740.0)));
	PushBackGameObject(new FailedManager());
	PushBackGameObject(new Appear());
}
