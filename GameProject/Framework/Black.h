#pragma once
#include "GameObject.h"

class Black :
	public GameObject
{
private:
	GameObject* black;
	float al = 0.1f;
	float tmp = 1.0f, tmp2 = 0.05f;
	int pastTime = 0;
	int currentTime;
	unsigned short num, perfect, great, miss;

public:
	Black(unsigned short num);
	Black(unsigned short perfect, unsigned short great, unsigned short miss);
	virtual void Update();
};

