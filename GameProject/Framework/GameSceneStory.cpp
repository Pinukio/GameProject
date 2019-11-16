#include "GameSceneStory.h"
#include "stdafx.h"

void GameSceneStory::Initialize()
{
	GameObject* background = PushBackGameObject(new GameObject(L"resources/background/background.png", Vector2(1920 / 2.0f, 1080 / 2.0f)));

	line_up1 = (UpLine*)PushBackGameObject(new UpLine());
	line_up2 = (UpLine*)PushBackGameObject(new UpLine());
	line_up2->transform->position.x = 896.0f;
	line_up3 = (UpLine*)PushBackGameObject(new UpLine());
	line_up3->transform->position.x = 1026.0f;
	line_up4 = (UpLine*)PushBackGameObject(new UpLine());
	line_up4->transform->position.x = 1156.0f;

	line_under1 = (UnderLine*)PushBackGameObject(new UnderLine());
	line_under2 = (UnderLine*)PushBackGameObject(new UnderLine());
	line_under2->transform->position.x = 896.0f;
	line_under3 = (UnderLine*)PushBackGameObject(new UnderLine());
	line_under3->transform->position.x = 1026.0f;
	line_under4 = (UnderLine*)PushBackGameObject(new UnderLine());
	line_under4->transform->position.x = 1156.0f;

	line1 = (Line*)PushBackGameObject(new Line());
	line2 = (Line*)PushBackGameObject(new Line());
	line2->transform->position.x = 896.0f;
	line3 = (Line*)PushBackGameObject(new Line());
	line3->transform->position.x = 1026.0f;
	line4 = (Line*)PushBackGameObject(new Line());
	line4->transform->position.x = 1156.0f;

	GameObject* bar_under = PushBackGameObject(new GameObject(L"resources/background/bar_under.png", Vector2(960.0f, 986.0f)));
	GameObject* bar_up = PushBackGameObject(new GameObject(L"resources/background/bar_up.png", Vector2(960.0f, 96.0f)));
}

