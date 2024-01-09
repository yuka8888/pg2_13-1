#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {
	enemyCount++;
	enemyRemainingCount = 1;

	enemy_.position.x = 150 * enemyCount;
	enemy_.position.y = 100;
	enemy_.radius = 50;
	enemy_.speed = 5;
	isAlive_ = true;
}


void Enemy::Update() {
	enemy_.position.x += enemy_.speed;
	if (enemy_.position.x >= 1280 - enemy_.radius) {
		enemy_.speed *= -1;
		enemy_.position.x = 1280 - enemy_.radius;
	}
	else if (enemy_.position.x <= enemy_.radius) {
		enemy_.speed *= -1;
		enemy_.position.x = enemy_.radius;
	}
}


void Enemy::Draw() {
	if (enemyRemainingCount > 0) {
		Novice::DrawEllipse(enemy_.position.x, enemy_.position.y, enemy_.radius, enemy_.radius, 0.0f, BLUE, kFillModeSolid);
	}
}

