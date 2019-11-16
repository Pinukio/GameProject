#include "UpLine.h"
#include "stdafx.h"

UpLine::UpLine()
	:GameObject(L"resources/Line/up_line_part.png", Vector2(766.0f, 142.0f)),
	col(*transform, Vector2(130.0f, 147.0f))
{
}

