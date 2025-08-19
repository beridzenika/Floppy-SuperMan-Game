#pragma once
#include "raylib.h"
#include <vector>
class Pipe
{
public:
	Pipe();
	~Pipe();
	void Draw();
	void Update();
	void Restart();
	Rectangle GetUpRect();
	Rectangle GetLowRect();
	

private:
	Texture2D UpPipeImage, LowPipeImage;
	Vector2 UpPos, LowPos;
	Rectangle LowRec, UpRec;
	int holeH, speed, score, highScore;
	int pipeI, recycleI, lastI;
	float width, LowHeight;
	std::vector<Vector2> pipes;
};
