#pragma once
#include "GameObject.h"
class Light_reversed :
	public GameObject
{
public:
	Light_reversed(bool isAnimation);
	virtual void Update();
	float al = 0.9f;
	bool isAnimation;
};

