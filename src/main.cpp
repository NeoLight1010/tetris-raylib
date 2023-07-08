#include "blocks.cpp"
#include "game.h"
#include <raylib.h>
#include <stdlib.h>

double lastUpdateTime = 0;

bool deltaTimeHasPassed(double interval) {
  double currentTime = GetTime();

  if (currentTime - lastUpdateTime > interval) {
    lastUpdateTime = currentTime;
    return true;
  }

  return false;
}

int main() {
  InitWindow(300, 600, "Tetris");
  SetTargetFPS(60);

  auto game = Game();

  while (!WindowShouldClose()) {
    game.handleInput();

    if (deltaTimeHasPassed(0.5)) {
      game.applyGravity();
      game.checkForFullRows();
    }

    BeginDrawing();

    ClearBackground(DARKBLUE);
    game.draw();

    EndDrawing();
  }

  return 0;
}
