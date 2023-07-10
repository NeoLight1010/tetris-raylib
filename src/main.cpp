#include "blocks.cpp"
#include "colors.h"
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
  auto game = Game();

  int windowWidth = game.grid.NUM_COLUMNS * game.CELL_SIZE + 200;
  int windowHeight = game.grid.NUM_ROWS * game.CELL_SIZE + 20;

  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    game.handleInput();

    if (deltaTimeHasPassed(0.2)) {
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
