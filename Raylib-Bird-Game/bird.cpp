#include "bird.h"

Bird::Bird()
{
	imageFly = LoadTexture("graphics/SMfly.png");
	imageFall = LoadTexture("graphics/SMfall.png");
	position.x = GetScreenWidth()/2 - 30;
	position.y = GetScreenHeight()/2;
	speed = 1;
	fall = true;
}
Bird::~Bird() 
{
	UnloadTexture(imageFly);
	UnloadTexture(imageFall);
}
void Bird::Restart() {
	position.x = GetScreenWidth() / 2 - 30;
	position.y = GetScreenHeight() / 2;
	speed = 1;
	fall = true;
}

void Bird::Draw() {
	if(fall)DrawTextureV(imageFall, position, WHITE);
	else DrawTextureV(imageFly, position, WHITE);

}
void Bird::Update() {
	position.y += speed;
	speed += 0.1;
	fall = true;
	if (IsKeyDown(KEY_SPACE)) {
		speed -= 0.2;
		fall = false;
	}
}

Rectangle Bird::GetRect()
{
	return Rectangle{position.x, position.y, float(imageFall.width), float(imageFall.height) };
}

bool Bird::OutOfSight()
{
	if (position.y >= GetScreenHeight() || position.y <= 0) return true;
	else return false;
}