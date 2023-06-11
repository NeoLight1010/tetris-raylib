#include "blocks.cpp"
#include "grid.h"
#include <raylib.h>
#include <stdlib.h>

int main() {
  InitWindow(300, 600, "Tetris");
  SetTargetFPS(60);

  Grid grid = Grid();
  grid.debugPrint();

  auto block = SBlock();

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(DARKBLUE);
    grid.draw();
    block.draw();

    EndDrawing();
  }

  return 0;
}
