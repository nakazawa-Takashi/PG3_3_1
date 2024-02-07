#pragma once
#include "IScene.h"

class TitleScene : public IScene {
public:
	void Inisialize() override;
	void Update() override;
	void Draw() override;
private:
};

