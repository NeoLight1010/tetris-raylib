#include <raylib.h>
#include <stdlib.h>

int main() {
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DARKBLUE);

        EndDrawing();
    }

    return 0;
}
