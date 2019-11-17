#pragma once
#include "Scene.h"

class FailedScene :
	public Scene
{
private:
	bool isStory;
public:
	FailedScene(bool isStory);
	virtual void Initialize();
};

