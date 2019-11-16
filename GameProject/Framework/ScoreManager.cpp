#include "ScoreManager.h"
#include "Scene.h"
#include "stdafx.h"

ScoreManager::ScoreManager()
	:GameObject()
{
	Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/Score/ScoreBar.png", Vector2(1293.0f, 715.0f)));
	colour = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/Score/Colour.png", Vector2(1238.0f, 715.0f + 30.5f)));
	colour->transform->scalingCenter = Vector2(0.0f, 645.0f / 2.0f);
}

void ScoreManager::Update()
{
	if (tmp != hp)
	{
		isChanged = true;
	}
	else
		isChanged = false;

	if (isChanged)
	{

		if (tmp > hp) //깎인 경우
		{
			for (int i = 0; i < 6; i++)
			{

				if (lastIndex == 10000)
				{
					index = tmp * 10 - count;
					lastIndex = index;
				}

				else if (lastIndex != index)
				{
					index = lastIndex;

					if(lastIndex - tmp * 10 > 0)
					count = lastIndex - tmp * 10;

					else
						count = (lastIndex - tmp * 10) * -1;
				}

				else
					index = tmp * 10 - count;

				lastIndex = index;

				if (index > 999)
				{
					isChanged = false;
					break;
				}
				else
				{
					colour->transform->SetScale(1.0f, (float)index / 1000.0f);
				}

				if (count == 10)
				{
					count = 0;
					tmp--;
				}
				
				count++;
			}
		}

		else if (tmp < hp) // 회복된 경우
		{
			for (int i = 0; i < 6; i++)
			{
				if (lastIndex != index2)
				{
					index2 = lastIndex;

					if(tmp * 10 - lastIndex > 0)
						count = tmp * 10 - lastIndex;
					else
						count = (tmp * 10 - lastIndex) * -1;
				}

				else
					index2 = tmp * 10 - count;
			
				lastIndex = index2;

				if (index2 > 999)
				{
					isChanged = false;
					break;
				}

				else
				{
					colour->transform->SetScale(1.0f, (float)index2 / 1000.0f);
				}
				
				if (count == 0)
				{
					count = 10;
					tmp++;
				}

				count--;

			}
		}
	}

}
