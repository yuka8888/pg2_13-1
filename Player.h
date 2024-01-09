#pragma once
#include "Bullet.h"
#include "Struct.h"

class Player
{
public:
	Player();

	void Update(char* keys, char* preKeys);

	void Draw();

	Bullet* bullet_;

	Transform GetPlayer() { return player_; }

private:
	Transform player_;

};

