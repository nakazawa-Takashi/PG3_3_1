#pragma once

#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

class GameManager {
private:
	// シーンを保持
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prvSceneNo_;

public:
	GameManager();
	~GameManager();

	int Run();
private:

	int sceneNo;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};
