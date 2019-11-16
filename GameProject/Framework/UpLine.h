#pragma once
#include "GameObject.h"
#include "AABBCollider.h"

class UpLine :
	public GameObject
{
public:
	UpLine();
	AABBCollider col;
};

