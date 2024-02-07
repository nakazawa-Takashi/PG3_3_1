#include "StageScene.h"

void StageScene::Inisialize()
{
}

void StageScene::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	// 変数を初期化
	playerSpeed = 5.0f;
	bulletSpeed = 8.0f;

	/*---------------
	   プレイヤー
	---------------*/

	// Wキーを押すと上へ移動し、画面端で静止
	if (keys[DIK_W]) {
		if (playerPosY <= 20) {
			playerSpeed = 0;
		}
		playerPosY -= playerSpeed;
	}

	// Sキーを押すと下へ移動し、画面端で静止
	if (keys[DIK_S]) {
		if (playerPosY >= 700) {
			playerSpeed = 0;
		}
		playerPosY += playerSpeed;
	}

	// Dキーを押すと右へ移動し、画面端で静止
	if (keys[DIK_D]) {
		if (playerPosX >= 1260) {
			playerSpeed = 0;
		}
		playerPosX += playerSpeed;
	}

	// Aキーを押すと左へ移動し、画面端で静止
	if (keys[DIK_A]) {
		if (playerPosX <= 20) {
			playerSpeed = 0;
		}
		playerPosX -= playerSpeed;
	}

	/*---------------
		 弾
	---------------*/

	// スペースキーで弾を発射
	if ((bool)isBulletShot == false) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			bulletPosX = playerPosX;
			bulletPosY = playerPosY;
			isBulletShot = true;
		}
	}

	// 弾道
	if ((bool)isBulletShot == true) {
		if (bulletPosY <= 0) {
			isBulletShot = false;
		}
		bulletPosY -= bulletSpeed;
	}

	// 弾が画面外に行くと初期化
	if (bulletPosY <= 0) {
		isBulletShot = false;
	}


	/*---------------
		 敵
	---------------*/

	// 敵の速さ
	enemyPosX = enemyPosX + enemySpeed;

	// 右端で反射
	if (enemyPosX >= 1260) {
		enemySpeed *= -1;
	}

	// 左端で反射
	if (enemyPosX <= 20) {
		enemySpeed *= -1;
	}

	// 弾と敵の当たり判定の変数
	e2bX = enemyPosX - bulletPosX;
	e2bY = enemyPosY - bulletPosY;
	hit = enemyRadius + bulletRadius;

	// 弾に当たったら消滅
	if (e2bX * e2bX + e2bY * e2bY <= hit * hit) {
		isEnemyAlive = false;
	}

	if (isEnemyAlive == false) {
		sceneNo = CLEAR;
	}

}

void StageScene::Draw()
{
	// プレイヤーを表示
	Novice::DrawEllipse(
		(int)playerPosX, (int)playerPosY,
		20, 20,
		0.0f,
		WHITE,
		kFillModeSolid
	);

	// 弾を表示
	if ((bool)isBulletShot == true) {
		Novice::DrawTriangle(
			(int)bulletPosX, (int)bulletPosY - (int)bulletRadius,
			(int)bulletPosX - (int)bulletRadius, (int)bulletPosY + (int)bulletRadius,
			(int)bulletPosX + (int)bulletRadius, (int)bulletPosY + (int)bulletRadius,
			WHITE,
			kFillModeSolid
		);
	}

	// 敵を表示
	if ((bool)isEnemyAlive == true) {
		Novice::DrawEllipse(
			(int)enemyPosX, (int)enemyPosY,
			(int)enemyRadius, (int)enemyRadius,
			0.0f,
			RED,
			kFillModeSolid
		);
	}
}
