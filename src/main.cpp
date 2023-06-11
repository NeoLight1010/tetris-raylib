#include "grid.h"
#include <raylib.h>
#include <stdlib.h>

int main() {
  InitWindow(300, 600, "Tetris");
  SetTargetFPS(60);

  Grid grid = Grid();
  grid.grid[0][0] = 1;
  grid.debugPrint();

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(DARKBLUE);
    grid.draw();

    EndDrawing();
  }

  return 0;
}
