#include "GameSceneHard.h"
#include "stdafx.h"
#include "NoteManager_hard.h"
#include "Appear.h"
void GameSceneHard::Initialize()
{
	PushBackGameObject(new GameObject(L"resources/background/background.png", Vector2(1920 / 2.0f, 1080 / 2.0f)));
	PushBackGameObject(new GameObject(L"resources/background/bar_under.png", Vector2(960.0f, 986.0f)));
	PushBackGameObject(new GameObject(L"resources/background/bar_up.png", Vector2(960.0f, 96.0f)));
	PushBackGameObject(new NoteManager_hard());
	PushBackGameObject(new Appear());
}

