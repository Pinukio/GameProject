#pragma once
#include "GameObject.h"
class Light :
	public GameObject
{
public:
	Light(bool isAnimation);
	virtual void Update();
	float al = 0.9f;
	bool isAnimation;
};

