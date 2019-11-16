#pragma once
#include "GameObject.h"
#include <vector>
#include "CenterNote.h"
#include "SideNote.h"
#include "UnderLine.h"
#include "UpLine.h"
#include "Line.h"
#include "Key1.h"
#include "Key2.h"
#include "Key3.h"
#include "Key4.h"
#include "ListAnimation.h"
#include "AnimationRenderer.h"
#include "ScoreManager.h"

class KeyManager :
	public GameObject
{
private:
	ListAnimation* anim;
	AnimationRenderer* animRenderer;
	int pastTime = 0, currentTime;
	unsigned short count_hit;
	unsigned short maxCount = 20;

public:
	KeyManager();

	std::vector<SideNote*> list_note1, list_note4;
	std::vector<CenterNote*> list_note2, list_note3;

	virtual void Update();
	virtual void LateUpdate();

	Key1* key1; Key2* key2; Key3* key3; Key4* key4;

	UnderLine* line_under1, *line_under2, *line_under3, *line_under4;
	UpLine* line_up1, *line_up2, *line_up3, *line_up4;
	Line* line1, *line2, *line3, *line4;

	unsigned short reversed1 = 10, reversed2 = 10;
	unsigned short miss = 0, great = 0, perfect = 0;

	GameObject* light1, *light2, *light3, *light4;
	ScoreManager* scoreManager;

};

