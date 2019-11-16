#include "UnderLine.h"
#include "stdafx.h"

UnderLine::UnderLine()
	:GameObject(L"resources/Line/under_line_part.png", Vector2(766.0f, 302.0f)),
	col(*transform, Vector2(130.0f, 156.0f))
{

}
