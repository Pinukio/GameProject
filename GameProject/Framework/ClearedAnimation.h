#pragma once
#include "GameObject.h"
#include "AnimationRenderer.h"
#include "ListAnimation.h"
#include "SheetAnimation.h"
class ClearedAnimation :
	public GameObject
{
public:
	ClearedAnimation(float x, float y);
	float al = 0.4f;
	int pastTime = 0;
	int currentTime;
	unsigned short count = 0;
	virtual void Update();
	AnimationRenderer* animRenderer;
	SheetAnimation* anim;
};

