#pragma once
#include "IScene.h"

class ClearScene : public IScene {
public:
	void Inisialize() override;
	void Update() override;
	void Draw() override;
};
