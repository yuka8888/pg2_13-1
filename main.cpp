#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Function.h"


const char kWindowTitle[] = "学籍番号";

int Enemy::enemyCount;
int Enemy::enemyRemainingCount;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Enemy* enemy[6];
	for (int i = 0; i < 6; i++) {
		enemy[i] = new Enemy;
	}
	Player* player = new Player;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		for (int i = 0; i < 6; i++) {
			if (IsCollision(enemy[i]->GetEnemy(), player->bullet_->GetBullet())) {
				enemy[i]->enemyRemainingCount--;
			}
			enemy[i]->Update();
		}
		player->Update(keys, preKeys);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		for (int i = 0; i < 6; i++) {
			enemy[i]->Draw();
		}
		player->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	for (int i = 0; i < 6; i++) {
		delete enemy[i];
	}
	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
