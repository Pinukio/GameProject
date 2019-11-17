#pragma once
#include "GameObject.h"
class FailedManager :
	public GameObject
{
private:
	GameObject* arrow;
	unsigned short selected = 0;
	bool isStory;
public:
	FailedManager(bool isStory);
	virtual void Update();
};

