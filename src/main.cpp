#include "block.h"
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

void drawBlock(Block &block, float cellSize, Vector2 offset) {
  const int BORDER_WIDTH = 1;

  std::vector<Position> currentRotationCells =
      block.rotations[block.rotationState];

  for (Position cell : block.getMovedCellPositions()) {
    DrawRectangle(cell.column * cellSize + offset.x,
                  cell.row * cellSize + offset.y, cellSize - BORDER_WIDTH,
                  cellSize - BORDER_WIDTH, getCellColor(block.id()));
  }
}

void drawGameCurrentBlock(Game game) {
  drawBlock(*game.getCurrentBlock(), game.CELL_SIZE,
            {game.PADDING_SIZE, game.PADDING_SIZE});
}

void drawNextBlockIndicator(Font font, Game game) {
  DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);

  DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, BLUE);

  float offsetX = 0;
  float offsetY = 0;

  auto block = game.getNextBlock();
  switch (block->id()) {
  case 3:
    offsetX = 255;
    offsetY = 290;
    break;
  case 4:
    offsetX = 255;
    offsetY = 280;
    break;
  default:
    offsetX = 270;
    offsetY = 270;
    break;
  }

  drawBlock(*game.getNextBlock(), game.CELL_SIZE, {offsetX, offsetY});
}

void drawHUD(Font font, Game &game) {
  drawScoreIndicator(font, game.getScore());
  drawNextBlockIndicator(font, game);

  if (game.gameOver) {
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

void drawAll(Game game, Font font) {
  BeginDrawing();

  ClearBackground(DARKBLUE);
  game.draw();
  drawGameCurrentBlock(game);
  drawHUD(font, game);

  EndDrawing();
}

void handleGameInput(Game &game) {
  int keyPressed = GetKeyPressed();

  if (game.gameOver && keyPressed != 0) {
    game.restart();
    return;
  }

  switch (keyPressed) {
  case KEY_LEFT:
    game.moveBlockLeft();
    break;
  case KEY_RIGHT:
    game.moveBlockRight();
    break;
  case KEY_DOWN:
    game.moveBlockDown();
    game.giveScoreForManualDrop();
    break;

  case KEY_Z:
    game.rotateBlockBackward();
    break;
  case KEY_X:
    game.rotateBlockForward();
  }
}

void updateGame(Game &game) {
  handleGameInput(game);

  if (deltaTimeHasPassed(0.2)) {
    game.applyGravity();
  }
}

int main() {
  auto game = Game();

  int windowWidth = game.grid.NUM_COLUMNS * game.CELL_SIZE + 200;
  int windowHeight = game.grid.NUM_ROWS * game.CELL_SIZE + 20;

  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  InitAudioDevice();
  Music music = LoadMusicStream("../sounds/music.mp3");
  PlayMusicStream(music);

  Font font = GetFontDefault();

  while (!WindowShouldClose()) {
    UpdateMusicStream(music);

    updateGame(game);
    drawAll(game, font);
  }

  UnloadMusicStream(music);
  CloseAudioDevice();

  return 0;
}
