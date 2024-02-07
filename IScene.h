#pragma once
#include "Novice.h"

// シーン名
enum SCENE {
	TITLE,
	STAGE,
	CLEAR
};

class IScene {
protected:
	// シーン番号
	static int sceneNo;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

public:
	virtual ~IScene();

	virtual void Inisialize() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	int GetSceneNo();
};