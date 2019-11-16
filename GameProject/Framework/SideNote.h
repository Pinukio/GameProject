#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class SideNote :
	public GameObject
{

public:
	
	AABBCollider col;
	float moveSpeed;
	SideNote();
	virtual void Update();

};

