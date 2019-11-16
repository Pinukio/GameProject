#pragma once
#include "GameObject.h"
class SucceededManager :
	public GameObject
{
private:
	GameObject* arrow;
	unsigned short selected = 0;
public:
	SucceededManager();
	virtual void Update();
};

