#include <raylib.h>
#include <stdlib.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cool");
    SetTargetFPS(60);

    Shader cloudShader = LoadShader(0, "shaders/first.frag");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        DrawCircle(0, 0, 10, BLUE);

        BeginShaderMode(cloudShader);
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
        EndShaderMode();

        EndDrawing();
    }

    UnloadShader(cloudShader);
    CloseWindow();
    return 0;
}
