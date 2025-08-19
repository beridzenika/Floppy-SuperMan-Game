#pragma once
#include "raylib.h"

class Bird {
public:
	Bird();
	~Bird();
	void Draw();
	void Update();
	void Restart();
	Rectangle GetRect();
	bool OutOfSight();
private:
	Texture2D imageFly, imageFall;
	Vector2 position;
	float speed;
	bool fall;
};