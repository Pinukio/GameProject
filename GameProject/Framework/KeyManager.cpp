#include "stdafx.h"
#include "KeyManager.h"
#include "InputManager.h"
#include "Scene.h"
#include "Light.h"
#include "Light_reversed.h"
#include "ClearedAnimation.h"
#include "Black.h"
#include "FailedScene.h"
#include "SucceededScene.h"
#include <time.h>

KeyManager::KeyManager(bool isStory)
	:GameObject(animRenderer = new AnimationRenderer())
{
	scoreManager = (ScoreManager*) (Scene::GetCurrentScene().PushBackGameObject(new ScoreManager()));
	scoreManager->hp = 100;

	this->isStory = isStory;
}

void KeyManager::Update()
{
	if (scoreManager->hp == 0)
	{
		StopNote();
		Scene::GetCurrentScene().PushBackGameObject(new Black(3, isStory));
	}

	else if (count_hit == maxCount)
	{
		StopNote();
		Scene::GetCurrentScene().PushBackGameObject(new Black(perfect, great, miss, isStory));
	}

	if (list_note1.size() > 0)
	{
		if(isStory && count_hit >= tmp)
		HideNote(list_note1, 0);

		if (list_note1[0]->transform->position.y < 0.0f || list_note1[0]->transform->position.y > 1080.0f)
			DestroyNote(list_note1);
	}
	
	if (list_note2.size() > 0)
	{
		if (isStory && count_hit >= tmp)
			HideNote(list_note2, 1);

		if (list_note2[0]->transform->position.y < 0.0f || list_note2[0]->transform->position.y > 1080.0f)
			DestroyNote(list_note2);
	}

	if (list_note3.size() > 0)
	{
		if (isStory && count_hit >= tmp)
			HideNote(list_note3, 2);

		if (list_note3[0]->transform->position.y < 0.0f || list_note3[0]->transform->position.y > 1080.0f)
			DestroyNote(list_note3);
	}

	if (list_note4.size() > 0)
	{
		if (isStory && count_hit >= tmp)
			HideNote(list_note4, 3);

		if (list_note4[0]->transform->position.y < 0.0f || list_note4[0]->transform->position.y > 1080.0f)
			DestroyNote(list_note4);
	}

	if (scoreManager->hp > 0 && count_hit < maxCount)
	{
		if (InputManager::GetKeyDown(0x44)) // d
		{
			if (reversed1 != 0 && reversed2 != 0)
				light1 = Scene::GetCurrentScene().PushBackGameObject(new Light(false));
			else
				light1 = Scene::GetCurrentScene().PushBackGameObject(new Light_reversed(false));

			light1->transform->position.x = 766.0f;
		}

		else if (InputManager::GetKeyPressed(0x44))
		{
			if (reversed1 != 0 && reversed2 != 0)
				key1->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_clicked.png", 0, 0));
			else
				key1->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_clicked_reversed.png", 0, 0));
		}

		else if (InputManager::GetKeyUp(0x44))
		{
			if (reversed1 != 0 && reversed2 != 0)
				key1->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key.png", 0, 0));
			else
				key1->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_reversed.png", 0, 0));

			Scene::GetCurrentScene().Destroy(light1);

			if (reversed1 != 0 && reversed2 != 0)
				light1 = Scene::GetCurrentScene().PushBackGameObject(new Light(true));
			else
				light1 = Scene::GetCurrentScene().PushBackGameObject(new Light_reversed(true));

			light1->transform->position.x = 766.0f;
		}

		if (InputManager::GetKeyDown(0x46)) // f
		{
			if (reversed1 != 1 && reversed2 != 1)
				light2 = Scene::GetCurrentScene().PushBackGameObject(new Light(false));
			else
				light2 = Scene::GetCurrentScene().PushBackGameObject(new Light_reversed(false));

			light2->transform->position.x = 896.0f;
		}

		else if (InputManager::GetKeyPressed(0x46))
		{
			if (reversed1 != 1 && reversed2 != 1)
				key2->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_clicked.png", 0, 0));

			else
				key2->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_clicked_reversed.png", 0, 0));
		}

		else if (InputManager::GetKeyUp(0x46))
		{
			if (reversed1 != 1 && reversed2 != 1)
				key2->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key.png", 0, 0));
			else
				key2->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_reversed.png", 0, 0));

			Scene::GetCurrentScene().Destroy(light2);

			if (reversed1 != 1 && reversed2 != 1)
				light2 = Scene::GetCurrentScene().PushBackGameObject(new Light(true));
			else
				light2 = Scene::GetCurrentScene().PushBackGameObject(new Light_reversed(true));

			light2->transform->position.x = 896.0f;
		}

		if (InputManager::GetKeyDown(0x4A)) // j
		{
			if (reversed1 != 2 && reversed2 != 2)
				light3 = Scene::GetCurrentScene().PushBackGameObject(new Light(false));
			else
				light3 = Scene::GetCurrentScene().PushBackGameObject(new Light_reversed(false));

			light3->transform->position.x = 1026.0f;
		}

		else if (InputManager::GetKeyPressed(0x4A))
		{
			if (reversed1 != 2 && reversed2 != 2)
				key3->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_clicked.png", 0, 0));
			else
				key3->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_clicked_reversed.png", 0, 0));
		}

		else if (InputManager::GetKeyUp(0x4A))
		{
			if (reversed1 != 2 && reversed2 != 2)
				key3->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key.png", 0, 0));
			else
				key3->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_reversed.png", 0, 0));

			Scene::GetCurrentScene().Destroy(light3);

			if (reversed1 != 2 && reversed2 != 2)
				light3 = Scene::GetCurrentScene().PushBackGameObject(new Light(true));
			else
				light3 = Scene::GetCurrentScene().PushBackGameObject(new Light_reversed(true));

			light3->transform->position.x = 1026.0f;
		}

		if (InputManager::GetKeyDown(0x4B)) // k
		{
			if (reversed1 != 3 && reversed2 != 3)
				light4 = Scene::GetCurrentScene().PushBackGameObject(new Light(false));
			else
				light4 = Scene::GetCurrentScene().PushBackGameObject(new Light_reversed(false));

			light4->transform->position.x = 1156.0f;
		}

		else if (InputManager::GetKeyPressed(0x4B))
		{
			if (reversed1 != 3 && reversed2 != 3)
				key4->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_clicked.png", 0, 0));
			else
				key4->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_clicked_reversed.png", 0, 0));
		}

		else if (InputManager::GetKeyUp(0x4B))
		{
			if (reversed1 != 3 && reversed2 != 3)
				key4->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key.png", 0, 0));
			else
				key4->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Key/key_reversed.png", 0, 0));

			Scene::GetCurrentScene().Destroy(light4);

			if (reversed1 != 3 && reversed2 != 3)
				light4 = Scene::GetCurrentScene().PushBackGameObject(new Light(true));
			else
				light4 = Scene::GetCurrentScene().PushBackGameObject(new Light_reversed(true));

			light4->transform->position.x = 1156.0f;
		}
	}
}

void KeyManager::LateUpdate()
{
	if (list_note1.size() > 0) // d
	{
		if (list_note1[0]->col.Intersected(line_up1->col) && !(list_note1[0]->col.Intersected(line1->col))) //≈ı∏Ìµµ
		{
			if(!isStory || (isStory && count_hit < tmp))
			list_note1[0]->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Note/note_side.png", 0, 0), 0.5f);
		}

		if (InputManager::GetKeyDown(0x44))
			HitNote(list_note1, line1, line_under1, line_up1, 0);
	}

	if (list_note2.size() > 0) // f
	{
		if (list_note2[0]->col.Intersected(line_up2->col) && !(list_note2[0]->col.Intersected(line2->col))) //≈ı∏Ìµµ
		{
			if (!isStory || (isStory && count_hit < tmp))
			list_note2[0]->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Note/note_center.png", 0, 0), 0.5f);
		}

		if (InputManager::GetKeyDown(0x46))
			HitNote(list_note2, line2, line_under2, line_up2, 1);

	}

	if (list_note3.size() > 0) // j
	{
		if (list_note3[0]->col.Intersected(line_up3->col) && !(list_note3[0]->col.Intersected(line3->col))) //≈ı∏Ìµµ
		{
			if (!isStory || (isStory && count_hit < tmp))
			list_note3[0]->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Note/note_center.png", 0, 0), 0.5f);
		}

		if (InputManager::GetKeyDown(0x4A))
			HitNote(list_note3, line3, line_under3, line_up3, 2);
		
	}

	if (list_note4.size() > 0) // k
	{
		if (list_note4[0]->col.Intersected(line_up4->col) && !(list_note4[0]->col.Intersected(line4->col))) //≈ı∏Ìµµ
		{
			if (!isStory || (isStory && count_hit < tmp))
			list_note4[0]->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Note/note_side.png", 0, 0), 0.5f);
		}

		if (InputManager::GetKeyDown(0x4B))
			HitNote(list_note4, line4, line_under4, line_up4, 3);
	}
}

void KeyManager::HitNote(std::vector<CenterNote*>& note, Line* line, UnderLine* underLine, UpLine* upLine, unsigned short num)
{
	if (note[0]->col.Intersected(line->col))
	{
		perfect++;
		count_hit++;

		if (scoreManager->hp > 0)
		{
			if (scoreManager->hp <= 98)
				scoreManager->hp += 2;
			else
				scoreManager->hp = 100;

			CreateAnim(num);
		}

		Scene::GetCurrentScene().Destroy(note[0]);
		note.erase(note.begin() + 0);
	}

	else if (note[0]->col.Intersected(underLine->col))
	{
		great++;
		count_hit++;

		if (scoreManager->hp > 0)
		{
			if (scoreManager->hp <= 99)
				scoreManager->hp += 1;

			CreateAnim(num);
		}

		Scene::GetCurrentScene().Destroy(note[0]);
		note.erase(note.begin() + 0);
	}

	else if (note[0]->col.Intersected(upLine->col))
	{
		miss++;
		count_hit++;

		if (scoreManager->hp >= 10) scoreManager->hp -= 10;
		else if (scoreManager >= 0) scoreManager->hp = 0;

		note.erase(note.begin() + 0);
	}
}

void KeyManager::HitNote(std::vector<SideNote*>& note, Line* line, UnderLine* underLine, UpLine* upLine, unsigned short num)
{
	if (note[0]->col.Intersected(line->col))
	{
		perfect++;
		count_hit++;

		if (scoreManager->hp > 0)
		{
			if (scoreManager->hp <= 98)
				scoreManager->hp += 2;
			else
				scoreManager->hp = 100;

			CreateAnim(num);
		}

		Scene::GetCurrentScene().Destroy(note[0]);
		note.erase(note.begin() + 0);
	}

	else if (note[0]->col.Intersected(underLine->col))
	{
		great++;
		count_hit++;

		if (scoreManager->hp > 0)
		{
			if (scoreManager->hp <= 99)
				scoreManager->hp += 1;

			CreateAnim(num);
		}

		Scene::GetCurrentScene().Destroy(note[0]);
		note.erase(note.begin() + 0);
	}

	else if (note[0]->col.Intersected(upLine->col))
	{
		miss++;
		count_hit++;

		if (scoreManager->hp >= 10) scoreManager->hp -= 10;
		else if (scoreManager >= 0) scoreManager->hp = 0;

		note.erase(note.begin() + 0);
	}
}

void KeyManager::CreateAnim(unsigned short num)
{
	switch (num)
	{
	case 0:
		if (reversed1 != num && reversed2 != num)
			Scene::GetCurrentScene().PushBackGameObject(new ClearedAnimation(766.0f, 220.0f));
		else
			Scene::GetCurrentScene().PushBackGameObject(new ClearedAnimation(766.0f, 860.0f));
		break;

	case 1:
		if (reversed1 != num && reversed2 != num)
			Scene::GetCurrentScene().PushBackGameObject(new ClearedAnimation(896.0f, 220.0f));
		else
			Scene::GetCurrentScene().PushBackGameObject(new ClearedAnimation(896.0f, 860.0f));
		break;

	case 2:
		if (reversed1 != num && reversed2 != num)
			Scene::GetCurrentScene().PushBackGameObject(new ClearedAnimation(1026.0f, 220.0f));
		else
			Scene::GetCurrentScene().PushBackGameObject(new ClearedAnimation(1026.0f, 860.0f));
		break;

	case 3:
		if (reversed1 != num && reversed2 != num)
			Scene::GetCurrentScene().PushBackGameObject(new ClearedAnimation(1156.0f, 220.0f));
		else
			Scene::GetCurrentScene().PushBackGameObject(new ClearedAnimation(1156.0f, 860.0f));
		break;
	}
}

void KeyManager::DestroyNote(std::vector<SideNote*>& note)
{
	Scene::GetCurrentScene().Destroy(note[0]);
	note.erase(note.begin() + 0);
	if (scoreManager->hp >= 10)
		scoreManager->hp -= 10;
	else if (scoreManager >= 0)
		scoreManager->hp = 0;
	miss++;
	count_hit++;
}

void KeyManager::DestroyNote(std::vector<CenterNote*>& note)
{
	Scene::GetCurrentScene().Destroy(note[0]);
	note.erase(note.begin() + 0);
	if (scoreManager->hp >= 10)
		scoreManager->hp -= 10;
	else if (scoreManager >= 0)
		scoreManager->hp = 0;
	miss++;
	count_hit++;
}

void KeyManager::StopNote()
{
	if (list_note1.size() > 0)
		for (int i = 0; i < list_note1.size(); i++)
			list_note1[i]->moveSpeed = 0;
	if (list_note2.size() > 0)
		for (int i = 0; i < list_note2.size(); i++)
			list_note2[i]->moveSpeed = 0;
	if (list_note3.size() > 0)
		for (int i = 0; i < list_note3.size(); i++)
			list_note3[i]->moveSpeed = 0;
	if (list_note4.size() > 0)
		for (int i = 0; i < list_note4.size(); i++)
			list_note4[i]->moveSpeed = 0;
}

void KeyManager::HideNote(std::vector<CenterNote*>& note, unsigned short num)
{
	if (reversed1 != num && reversed2 != num)
	{
		if (note[0]->transform->position.y < 420.0f) // 40«»ºø πÿø°º≠
		{
			note[0]->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Note/note_center.png", 0, 0), 0.0f);
		}
	}
	else
	{
		if (note[0]->transform->position.y > 660.0f) // 40«»ºø ¿ßø°º≠
		{
			note[0]->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Note/note_center.png", 0, 0), 0.0f);
		}
	}
}

void KeyManager::HideNote(std::vector<SideNote*>& note, unsigned short num)
{
	if (reversed1 != num && reversed2 != num)
	{
		if (note[0]->transform->position.y < 420.0f) // 40«»ºø πÿø°º≠
		{
			note[0]->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Note/note_center.png", 0, 0), 0.0f);
		}
	}
	else
	{
		if (note[0]->transform->position.y > 660.0f) // 40«»ºø ¿ßø°º≠
		{
			note[0]->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(L"resources/Note/note_center.png", 0, 0), 0.0f);
		}
	}
}