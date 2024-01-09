#include "Player.h"
#include <Novice.h>

Player::Player() {
	player_.position.x = 400;
	player_.position.y = 400;
	player_.radius = 50;
	player_.speed = 5;

	bullet_ = new Bullet;
}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		player_.position.y -= player_.speed;
	}
	else if (keys[DIK_S]) {
		player_.position.y += player_.speed;
	}
	else if (keys[DIK_A]) {
		player_.position.x -= player_.speed;
	}
	else if (keys[DIK_D]) {
		player_.position.x += player_.speed;
	}

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		bullet_->SetBullet(player_.position);
		bullet_->SetIsShot(true);
	}

	bullet_->Update();
	bullet_->Draw();
}

void Player::Draw() {
	Novice::DrawEllipse(player_.position.x, player_.position.y, player_.radius, player_.radius, 0.0f, WHITE, kFillModeSolid);
}
