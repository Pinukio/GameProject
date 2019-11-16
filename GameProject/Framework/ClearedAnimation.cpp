#include "stdafx.h"
#include "ClearedAnimation.h"
#include <time.h>
#include "Scene.h"


ClearedAnimation::ClearedAnimation(float x, float y)
	:GameObject(animRenderer = new AnimationRenderer())
{
	transform->position.x = x;
	transform->position.y = y;
	anim = new SheetAnimation(1,70.0f, L"resources/Note/effect3.png", 420, 420, 15);
	animRenderer->PushBackAnimation(anim);
	animRenderer->ChangeAnimation(1);
}

void ClearedAnimation::Update()
{
	if (anim->currentFrame == 14)
		Scene::GetCurrentScene().Destroy(this);

}