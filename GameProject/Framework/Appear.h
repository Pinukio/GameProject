#pragma once
#include "GameObject.h"

class Appear :
	public GameObject
{
private:
	GameObject* black;
	float al = 1.0f;
public:
	Appear();
	virtual void Update();
};

