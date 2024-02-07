#include "ClearScene.h"

void ClearScene::Inisialize()
{
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	Novice::DrawBox(
		0, 0,
		1280, 720,
		0.0f,
		RED,
		kFillModeSolid
	);
}
