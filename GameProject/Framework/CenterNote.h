#pragma once
#include "GameObject.h"
#include "AABBCollider.h"

class CenterNote :
	public GameObject
{

public:

	AABBCollider col;
	float moveSpeed;
	CenterNote();
	virtual void Update();

};

