#pragma once
#include "GameObject.h"
class SucceededManager :
	public GameObject
{
private:
	GameObject* arrow;
	unsigned short selected = 0;
	bool isStory;
public:
	SucceededManager(bool isStory);
	virtual void Update();
};

