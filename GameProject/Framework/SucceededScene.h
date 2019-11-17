#pragma once
#include "Scene.h"
class SucceededScene :
	public Scene
{
private:
	unsigned short perfect, great, miss;
	bool isStory;
public:
	virtual void Initialize();
	SucceededScene(unsigned short perfect, unsigned short great, unsigned short miss, bool isStory);
	void WriteScore(unsigned short num, float x);
	void Help_Write(unsigned short num, float x);
};

