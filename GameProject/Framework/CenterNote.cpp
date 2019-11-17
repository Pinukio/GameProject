#include "CenterNote.h"
#include "stdafx.h"
#include "Scene.h"

using namespace std;

CenterNote::CenterNote()
	:GameObject(L"resources/Note/note_center.png"),
	moveSpeed(15.0f),
	col(*transform, Vector2(130.0f, 63.0f))
{
}

void CenterNote::Update()
{
	transform->position.y -= moveSpeed;
}

