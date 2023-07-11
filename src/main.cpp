#include "blocks.cpp"
#include "colors.h"
#include "game.h"
#include <cstddef>
#include <raylib.h>
#include <stdlib.h>

void drawHUD(Font font, bool gameOver, int score) {
  DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
  DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, BLUE);
  DrawTextEx(font, std::to_string(score).c_str(), {330, 65}, 38, 2, WHITE);

  DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
  DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, BLUE);

  if (gameOver) {
    DrawTextEx(font, "Game Over", {320, 450}, 38, 2, RED);
  }
}

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

  Font font = LoadFontEx("fonts/monogram.ttf", 64, NULL, 0);

  int windowWidth = game.grid.NUM_COLUMNS * game.CELL_SIZE + 200;
  int windowHeight = game.grid.NUM_ROWS * game.CELL_SIZE + 20;

  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    game.handleInput();

    if (deltaTimeHasPassed(0.2)) {
      game.applyGravity();
    }

    BeginDrawing();

    ClearBackground(DARKBLUE);
    game.draw();
    drawHUD(font, game.gameOver, game.getScore());

    EndDrawing();
  }

  return 0;
}
