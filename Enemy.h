#pragma once
#include "Struct.h"

class Enemy
{
public:
	Enemy();

	void Update();

	void Draw();

	static int enemyCount;
	static int enemyRemainingCount;

	Transform GetEnemy() { return enemy_; }


private:
	Transform enemy_;
	bool isAlive_;

};

