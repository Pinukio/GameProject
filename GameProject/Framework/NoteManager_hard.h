#pragma once
#include "GameObject.h"
#include "UnderLine.h"
#include "UpLine.h"
#include "Line.h"
#include "Key1.h"
#include "Key2.h"
#include "Key3.h"
#include "Key4.h"
#include "KeyManager.h"

class NoteManager_hard
	:public GameObject
{
private:

	int pastTime = 0;
	int currentTime, startTime;
	unsigned short count_note = 0, count_hit = 0;
	unsigned short random;
	unsigned short temp1 = 10;
	unsigned short temp2 = 10;
	unsigned short reversed1 = 10, reversed2 = 10;
	unsigned short maxCount = 20;

	UnderLine* line_under1, *line_under2, *line_under3, *line_under4;
	UpLine* line_up1, *line_up2, *line_up3, *line_up4;
	Line* line1, *line2, *line3, *line4;
	Key1* key1; Key2* key2; Key3* key3; Key4* key4;

	KeyManager* keyManager;
	

public:

	NoteManager_hard();
	virtual void Update();
	void createNote(unsigned short position);
	void reverseNote(unsigned short position);
};

