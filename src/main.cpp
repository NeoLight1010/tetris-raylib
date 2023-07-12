#include "blocks.cpp"
#include "colors.h"
#include "game.h"
#include <cstddef>
#include <iostream>
#include <raylib.h>
#include <stdlib.h>

void drawScoreText(int score, float backgroundX, float backgroundWidth,
                   Font font) {
  int scoreTextFontSize = 38;
  float scoreTextSpacing = 2;

  auto scoreString = std::to_string(score);

  int scoreTextWidth = MeasureText(scoreString.c_str(), scoreTextFontSize);

  float sidesPadding = (backgroundWidth - scoreTextWidth) / 2;
  float scoreTextX = backgroundX + sidesPadding;

  DrawTextEx(font, scoreString.c_str(), {scoreTextX, 65}, scoreTextFontSize,
             scoreTextSpacing, WHITE);
}

void drawScoreIndicator(Font font, int score) {
  DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);

  float backgroundX = 320;
  float backgroundY = 55;
  float backgroundWidth = 170;
  float backgroundHeight = 60;

  DrawRectangleRounded(
      {backgroundX, backgroundY, backgroundWidth, backgroundHeight}, 0.3, 6,
      BLUE);

  drawScoreText(score, backgroundX, backgroundWidth, font);
}

void drawHUD(Font font, bool gameOver, int score) {
  drawScoreIndicator(font, score);

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

  Font font = GetFontDefault();

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
