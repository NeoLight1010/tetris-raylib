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
  int windowWidth = Grid::NUM_COLUMNS * Grid::CELL_SIZE + 200;
  int windowHeight = Grid::NUM_ROWS * Grid::CELL_SIZE + 20;

  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  auto game = Game();

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
