#pragma once
#include "GameObject.h"
#include "AABBCollider.h"

class Line :
	public GameObject
{
public:
	Line();
	AABBCollider col;
};

