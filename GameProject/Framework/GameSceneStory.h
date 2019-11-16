#pragma once
#include "Scene.h"
#include "CenterNote.h"
#include "UnderLine.h"
#include "UpLine.h"
#include "Line.h"
class GameSceneStory :
	public Scene
{
public:
	virtual void Initialize();
	CenterNote* note_center;
	UnderLine* line_under1, *line_under2, *line_under3, *line_under4;
	UpLine* line_up1, *line_up2, *line_up3, *line_up4;
	Line* line1, *line2, *line3, *line4;
};

