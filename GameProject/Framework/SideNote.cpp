#include "SideNote.h"
#include "stdafx.h"
#include "Scene.h"

SideNote::SideNote()
	:GameObject(L"resources/Note/note_side.png"),
	moveSpeed(15.0f),
	col(*transform, Vector2(130.0f, 63.0f))
{
}

void SideNote::Update()
{
	transform->position.y -= moveSpeed;
}