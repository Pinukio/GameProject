#include "NoteManager.h"
#include "stdafx.h"
#include "InputManager.h"
#include "GameSceneHard.h"
#include "Scene.h"
#include <time.h>
#include <iostream>
#include "MenuManager.h"
#include "SideNote.h"
#include "CenterNote.h"
#include <stdlib.h>
#include <algorithm>
#include "Black.h"

NoteManager::NoteManager(bool isStory)
	:GameObject()
{
	line_up1 = (UpLine*)Scene::GetCurrentScene().PushBackGameObject(new UpLine());
	line_up2 = (UpLine*)Scene::GetCurrentScene().PushBackGameObject(new UpLine());
	line_up2->transform->position.x = 896.0f;
	line_up3 = (UpLine*)Scene::GetCurrentScene().PushBackGameObject(new UpLine());
	line_up3->transform->position.x = 1026.0f;
	line_up4 = (UpLine*)Scene::GetCurrentScene().PushBackGameObject(new UpLine());
	line_up4->transform->position.x = 1156.0f;

	line_under1 = (UnderLine*)Scene::GetCurrentScene().PushBackGameObject(new UnderLine());
	line_under2 = (UnderLine*)Scene::GetCurrentScene().PushBackGameObject(new UnderLine());
	line_under2->transform->position.x = 896.0f;
	line_under3 = (UnderLine*)Scene::GetCurrentScene().PushBackGameObject(new UnderLine());
	line_under3->transform->position.x = 1026.0f;
	line_under4 = (UnderLine*)Scene::GetCurrentScene().PushBackGameObject(new UnderLine());
	line_under4->transform->position.x = 1156.0f;

	line1 = (Line*)Scene::GetCurrentScene().PushBackGameObject(new Line());
	line2 = (Line*)Scene::GetCurrentScene().PushBackGameObject(new Line());
	line2->transform->position.x = 896.0f;
	line3 = (Line*)Scene::GetCurrentScene().PushBackGameObject(new Line());
	line3->transform->position.x = 1026.0f;
	line4 = (Line*)Scene::GetCurrentScene().PushBackGameObject(new Line());
	line4->transform->position.x = 1156.0f;

	key1 = (Key1*)Scene::GetCurrentScene().PushBackGameObject(new Key1());
	key2 = (Key2*)Scene::GetCurrentScene().PushBackGameObject(new Key2());
	key3 = (Key3*)Scene::GetCurrentScene().PushBackGameObject(new Key3());
	key4 = (Key4*)Scene::GetCurrentScene().PushBackGameObject(new Key4());

	keyManager = (KeyManager*)Scene::GetCurrentScene().PushBackGameObject(new KeyManager(isStory));

	keyManager->key1 = key1;
	keyManager->key2 = key2;
	keyManager->key3 = key3;
	keyManager->key4 = key4;

	keyManager->line_up1 = line_up1;
	keyManager->line_up2 = line_up2;
	keyManager->line_up3 = line_up3;
	keyManager->line_up4 = line_up4;

	keyManager->line1 = line1;
	keyManager->line2 = line2;
	keyManager->line3 = line3;
	keyManager->line4 = line4;

	keyManager->line_under1 = line_under1;
	keyManager->line_under2 = line_under2;
	keyManager->line_under3 = line_under3;
	keyManager->line_under4 = line_under4;

	startTime = clock();
}

void NoteManager::Update()
{
	currentTime = clock();
	if (currentTime - startTime >= 600 && keyManager->scoreManager->hp > 0)
	{
		if ((currentTime - pastTime >= 180) && count_note < maxCount)
		{
			srand((unsigned int)time(0));

			if (temp1 != 10 && temp2 != 10)
			{
				while (random == temp1 || random == temp2) random = rand() % 4;
				temp2 = temp1;
				temp1 = random;
			}
			else if (temp1 == 10)
			{
				random = rand() % 4;
				temp1 = random;
			}

			else if (temp2 == 10)
			{
				while (temp1 == random) random = rand() % 4;
				temp2 = temp1;
				temp1 = random;
			}

			if (count_note == 250)
			{
				reversed1 = rand() % 4;
				reverseNote(reversed1);
				keyManager->reversed1 = reversed1;
			}
			else if (count_note == 500)
			{
				reversed2 = reversed1;
				while (reversed2 == reversed1) reversed2 = rand() % 4;
				reverseNote(reversed2);
				keyManager->reversed2 = reversed2;
			}

			createNote(random);
			count_note++;
			pastTime = currentTime;
		}
	}
}

void NoteManager::createNote(unsigned short position)
{
	switch (position)
	{
	case 0:
	{
		SideNote* note = (SideNote*)Scene::GetCurrentScene().PushBackGameObject(new SideNote());
		note->transform->position.x = 766.0f;
		if(reversed1 != 0 && reversed2 != 0) note->transform->position.y = 1080.0f;
		else 
		{
			note->transform->position.y = 0.0f;
			note->moveSpeed *= -1;
		}
		keyManager->list_note1.push_back(note);
		break;
	}
		
	case 1:
	{
		CenterNote* note = (CenterNote*)Scene::GetCurrentScene().PushBackGameObject(new CenterNote());
		note->transform->position.x = 896.0f;
		if(reversed1 != 1 && reversed2 != 1) note->transform->position.y = 1080.0f;
		else
		{
			note->transform->position.y = 0.0f;
			note->moveSpeed *= -1;
		}
		keyManager->list_note2.push_back(note);
		break;
	}
		
	case 2:
	{
		CenterNote* note = (CenterNote*)Scene::GetCurrentScene().PushBackGameObject(new CenterNote());
		note->transform->position.x = 1026.0f;
		if(reversed1 != 2 && reversed2 != 2) note->transform->position.y = 1080.0f;
		else
		{
			note->transform->position.y = 0.0f;
			note->moveSpeed *= -1;
		}
		keyManager->list_note3.push_back(note);
		break;
	}
		
	case 3:
	{
		SideNote* note = (SideNote*)Scene::GetCurrentScene().PushBackGameObject(new SideNote());
		note->transform->position.x = 1156.0f;
		if (reversed1 != 3 && reversed2 != 3) note->transform->position.y = 1080.0f;
		else
		{
			note->transform->position.y = 0.0f;
			note->moveSpeed *= -1;
		}
		keyManager->list_note4.push_back(note);
		break;
	}
	}
}

void NoteManager::reverseNote(unsigned short position)
{
	switch (position)
	{
		
	case 0:
	{
		line_up1->transform->position.y = 1080.0f - line_up1->transform->position.y;
		line_up1->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/up_line_part_reversed.png", 0, 0));

		line1->transform->position.y = 1080.0f - line1->transform->position.y;
		line1->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/line_part.png", 0, 0));

		line_under1->transform->position.y = 1080.0f - line_under1->transform->position.y;
		line_under1->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/under_line_part_reversed.png", 0, 0));

		key1->transform->position.y = 1080.0f - key1->transform->position.y;
		key1->renderer = 
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_reversed.png", 0, 0));

		if (keyManager->list_note1.size() > 0)
			for (int i = 0; i < keyManager->list_note1.size(); i++)
				keyManager->list_note1[i]->moveSpeed *= -1;

		if (keyManager->list_note1.size() > 1) 
			std::reverse(keyManager->list_note1.begin(), keyManager->list_note1.end());

		break;
	}

	case 1:
	{
		line_up2->transform->position.y = 1080.0f - line_up2->transform->position.y;
		line_up2->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/up_line_part_reversed.png", 0, 0));

		line2->transform->position.y = 1080.0f - line2->transform->position.y;
		line2->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/line_part.png", 0, 0));

		line_under2->transform->position.y = 1080.0f - line_under2->transform->position.y;
		line_under2->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/under_line_part_reversed.png", 0, 0));

		key2->transform->position.y = 1080.0f - key2->transform->position.y;
		key2->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_reversed.png", 0, 0));

		if (keyManager->list_note2.size() > 0)
			for (int i = 0; i < keyManager->list_note2.size(); i++)
				keyManager->list_note2[i]->moveSpeed *= -1;

		if (keyManager->list_note2.size() > 1) 
			std::reverse(keyManager->list_note2.begin(), keyManager->list_note2.end());

		break;
	}

	case 2:
	{
		line_up3->transform->position.y = 1080.0f - line_up3->transform->position.y;
		line_up3->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/up_line_part_reversed.png", 0, 0));

		line3->transform->position.y = 1080.0f - line3->transform->position.y;
		line3->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/line_part.png", 0, 0));

		line_under3->transform->position.y = 1080.0f - line_under3->transform->position.y;
		line_under3->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/under_line_part_reversed.png", 0, 0));

		key3->transform->position.y = 1080.0f - key3->transform->position.y;
		key3->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_reversed.png", 0, 0));

		if (keyManager->list_note3.size() > 0)
			for (int i = 0; i < keyManager->list_note3.size(); i++)
				keyManager->list_note3[i]->moveSpeed *= -1;

		if (keyManager->list_note3.size() > 1)
			std::reverse(keyManager->list_note3.begin(), keyManager->list_note3.end());

		break;
	}

	case 3:
	{
		line_up4->transform->position.y = 1080.0f - line_up4->transform->position.y;
		line_up4->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/up_line_part_reversed.png", 0, 0));

		line4->transform->position.y = 1080.0f - line4->transform->position.y;
		line4->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/line_part.png", 0, 0));

		line_under4->transform->position.y = 1080.0f - line_under4->transform->position.y;
		line_under4->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Line/under_line_part_reversed.png", 0, 0));

		key4->transform->position.y = 1080.0f - key4->transform->position.y;
		key4->renderer =
			new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_reversed.png", 0, 0));

		if (keyManager->list_note4.size() > 0)
			for (int i = 0; i < keyManager->list_note4.size(); i++)
				keyManager->list_note4[i]->moveSpeed *= -1;

		if (keyManager->list_note4.size() > 1)
			std::reverse(keyManager->list_note4.begin(), keyManager->list_note4.end());

		break;
	}
	}
}

