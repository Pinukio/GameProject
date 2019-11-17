#include "stdafx.h"
#include "SucceededScene.h"
#include "Appear.h"
#include "SucceededManager.h"

SucceededScene::SucceededScene(unsigned short perfect, unsigned short great, unsigned short miss, bool isStory)
{
	this->perfect = perfect;
	this->great = great;
	this->miss = miss;
	this->isStory = isStory;
}

void SucceededScene::Initialize()
{
	PushBackGameObject(new GameObject(L"resources/background/black.png", Vector2(1920 / 2.0f, 1080 / 2.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/perfect.png", Vector2(500.0f, 325.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/great.png", Vector2(960.0f, 325.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/miss.png", Vector2(1420.0f, 325.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/restart.png", Vector2(1700.0f, 700.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/select.png", Vector2(1700.0f, 800.0f)));
	PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/finish.png", Vector2(1700.0f, 900.0f)));
	PushBackGameObject(new SucceededManager(isStory));
	WriteScore(perfect, 500.0f);
	WriteScore(great, 960.0f);
	WriteScore(miss, 1420.0f);
	PushBackGameObject(new Appear());
}

void SucceededScene::WriteScore(unsigned short num, float x)
{
	Help_Write(num / 100, x - 38.0f);
	Help_Write((num % 100 - num % 10) / 10, x);
	Help_Write(num % 10, x + 38.0f);
}

void SucceededScene::Help_Write(unsigned short num, float x)
{
	switch (num)
	{
	case 0:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/0.png", Vector2(x, 445.0f)));
		break;
	case 1:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/1.png", Vector2(x, 445.0f)));
		break;
	case 2:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/2.png", Vector2(x, 445.0f)));
		break;
	case 3:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/3.png", Vector2(x, 445.0f)));
		break;
	case 4:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/4.png", Vector2(x, 445.0f)));
		break;
	case 5:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/5.png", Vector2(x, 445.0f)));
		break;
	case 6:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/6.png", Vector2(x, 445.0f)));
		break;
	case 7:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/7.png", Vector2(x, 445.0f)));
		break;
	case 8:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/8.png", Vector2(x, 445.0f)));
		break;
	case 9:
		PushBackGameObject(new GameObject(L"resources/Scene/Succeeded/9.png", Vector2(x, 445.0f)));
		break;
	}
}