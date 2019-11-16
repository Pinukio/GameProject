#include "Line.h"
#include "stdafx.h"

Line::Line()
	:GameObject(L"resources/Line/Line_part.png", Vector2(766.0f, 220.0f)),
	col(*transform, Vector2(130.0f, 9.0f))
{
}

