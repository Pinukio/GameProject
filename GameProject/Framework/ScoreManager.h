#pragma once
#include "GameObject.h"

class ScoreManager :
	public GameObject
{
private:
	bool isChanged = false, isChanged2 = false;
	unsigned short tmp = 100;
	unsigned short count = 1;
	unsigned short lastIndex = 10000;
public:
	ScoreManager();
	virtual void Update();
	unsigned short hp;
	unsigned short index, index2;
	GameObject* colour;
	
};

