#include "TitleScene.h"

void TitleScene::Inisialize()
{

}

void TitleScene::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::DrawBox(
		0, 0,
		1280, 720,
		0.0f,
		BLUE,
		kFillModeSolid
	);
}
