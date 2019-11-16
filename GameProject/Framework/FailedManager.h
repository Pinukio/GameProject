#pragma once
#include "GameObject.h"
class FailedManager :
	public GameObject
{
private:
	GameObject* arrow;
	unsigned short selected = 0;

public:
	FailedManager();
	virtual void Update();
};

