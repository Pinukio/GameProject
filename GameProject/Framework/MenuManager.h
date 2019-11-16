#pragma once
#include "GameObject.h"
class MenuManager :
	public GameObject
{
	unsigned short selected = 0;

public:
	MenuManager();
	virtual void Update();
};

