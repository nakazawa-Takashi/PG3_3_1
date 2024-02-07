#pragma once
#include "IScene.h"

class StageScene : public IScene {
public:
	void Inisialize() override;
	void Update() override;
	void Draw() override;
private:
	// プレイヤーの座標と速さ
	float playerPosX = 680.0f;
	float playerPosY = 340.0f;
	float playerSpeed = 5.0f;

	// 弾の座標と速さ
	float bulletPosX = 0.0f;
	float bulletPosY = 0.0f;
	float bulletRadius = 10.0f;
	float bulletSpeed = 8.0f;
	int isBulletShot = false;

	// 敵の座標と速さ
	float enemyPosX = 680.0f;
	float enemyPosY = 100.0f;
	float enemySpeed = 5.0f;
	float enemyRadius = 20.0f;
	float enemyRespawnTimer = 120;
	int isEnemyAlive = true;

	// 弾と敵の当たり判定の変数
	float e2bX = enemyPosX - bulletPosX;
	float e2bY = enemyPosY - bulletPosY;
	float hit = enemyRadius + bulletRadius;
};

