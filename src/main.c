#include <raylib.h>
#include <stdlib.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cool");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        DrawCircle(0, 0, 10, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}