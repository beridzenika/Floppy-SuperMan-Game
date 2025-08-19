#include "Pipe.h"

Pipe::Pipe()
{
	UpPipeImage = LoadTexture("graphics/UpperPipe.png");
	LowPipeImage = LoadTexture("graphics/LowerPipe.png");
	holeH = 200;
	width = float(UpPipeImage.width);
	speed = 2;
	highScore = 0;
	score = 0;
	pipeI = -1;
	recycleI = 0;

	for (int i = 0; i <= GetScreenWidth() / 300; i++) {
		UpPos.x = GetScreenWidth() / 4 * 3 + i*300;
		UpPos.y = GetRandomValue(0, float(UpPipeImage.height)) - float(UpPipeImage.height);
		pipes.push_back(UpPos);
	}
	lastI = pipes.size() - 1;
}

Pipe::~Pipe()
{
	UnloadTexture(UpPipeImage);
	UnloadTexture(LowPipeImage);
}
void Pipe::Draw() {

	for (int i = 0; i < pipes.size(); i++) {
		DrawTextureV(UpPipeImage, pipes[i], WHITE);
		DrawTextureV(LowPipeImage, Vector2{ pipes[i].x, pipes[i].y + holeH + float(UpPipeImage.height) }, WHITE);
	}
	
	LowRec = Rectangle{ pipes[pipeI].x, 0, width, pipes[pipeI].y + UpPipeImage.height };
	UpRec = Rectangle{ pipes[pipeI].x, pipes[pipeI].y + UpPipeImage.height + holeH, width, GetScreenHeight() - LowPos.y };


	DrawText(TextFormat("score %04i", score), 20, 20, 40, WHITE);
	DrawText(TextFormat("high score %04i", highScore), 20, 60, 20, WHITE);
}

void Pipe::Update() {
	for (int i = 0; i < pipes.size(); i++) {
		pipes[i].x -= speed;
	}
	if (UpRec.x * 2 + 150 <= GetScreenWidth()) {
		pipeI = (pipeI + 1)%pipes.size();
		score++;
		if (highScore < score)highScore++;
	}
	if (pipes[recycleI].x + UpPipeImage.width <= 0) {
		pipes[recycleI].x = pipes[lastI].x + 300;
		pipes[recycleI].y = GetRandomValue(0, float(UpPipeImage.height)) - float(UpPipeImage.height);
		recycleI = (recycleI + 1)%pipes.size();
		lastI = (lastI + 1) % pipes.size();
	}
}
void Pipe::Restart() {
	if (highScore < score)highScore = score;
	score = 0;
	pipeI = 0;
	recycleI = 0;
	
	pipes.clear();
	for (int i = 0; i <= GetScreenWidth() / 300; i++) {
		UpPos.x = GetScreenWidth() / 4 * 3 + i * 300;
		UpPos.y = GetRandomValue(0, float(UpPipeImage.height)) - float(UpPipeImage.height);
		pipes.push_back(UpPos);
	}
	lastI = pipes.size() - 1;
}

Rectangle Pipe::GetUpRect()
{
	return UpRec;
}
Rectangle Pipe::GetLowRect()
{
	return LowRec;
}