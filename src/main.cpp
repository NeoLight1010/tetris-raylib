#include "blocks.cpp"
#include "game.h"
#include <raylib.h>
#include <stdlib.h>

int main() {
  InitWindow(300, 600, "Tetris");
  SetTargetFPS(60);

  auto game = Game();

  while (!WindowShouldClose()) {
    game.handleInput();

    BeginDrawing();

    ClearBackground(DARKBLUE);
    game.draw();

    EndDrawing();
  }

  return 0;
}
