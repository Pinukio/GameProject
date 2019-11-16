#pragma once
#include "GameObject.h"
#include "AABBCollider.h"

class UnderLine :
	public GameObject
{
public:
	UnderLine();
	AABBCollider col;
};

