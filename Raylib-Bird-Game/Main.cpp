#include "raylib.h"
#include "bird.h"
#include "Pipe.h"



int main() {
	int screenWidth = 900;
	int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Flippy Bird Game");
	SetTargetFPS(60);

	Bird bird;       
	Pipe pipe;

	while (WindowShouldClose() == false) {

		bool isColision = CheckCollisionRecs(bird.GetRect(), pipe.GetUpRect()) 
			           || CheckCollisionRecs(bird.GetRect(), pipe.GetLowRect())
			           || bird.OutOfSight();
		if (isColision) {
			if (IsKeyDown(KEY_ENTER)) {
				pipe.Restart();
				bird.Restart();
				isColision = false;
			}
		}
		else {
			bird.Update();
			pipe.Update();
		}

		BeginDrawing();
		ClearBackground(SKYBLUE);
		pipe.Draw();
		bird.Draw();

		if (isColision) DrawText("Click ENTER to restart", 100, screenHeight / 2, 60, WHITE);
		EndDrawing();
	}
	CloseWindow();
}