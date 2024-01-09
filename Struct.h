#pragma once

struct Vector2 {
	int x;
	int y;
};

struct Transform {
	Vector2 position;
	int radius;
	int speed;
};