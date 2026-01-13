#include <raylib.h>
#include <stdlib.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cool");
    SetTargetFPS(60);

    Shader cloudShader = LoadShader(0, "shaders/first.frag");

    // following the example at https://github.com/raysan5/raylib/blob/master/examples/shaders/shaders_postprocessing.c
    Shader grayShader = LoadShader(0, "shaders/gray.frag");
    RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(WHITE);
            DrawCircle(0, 0, 10, BLUE);

            BeginShaderMode(cloudShader);
                DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
                DrawTextureRec(target.texture, (Rectangle){0, 0, (float)target.texture.width, (float)-target.texture.height}, (Vector2){0, 0}, WHITE);
            EndShaderMode();
        EndDrawing();
    }

    UnloadShader(cloudShader);
    CloseWindow();
    return 0;
}
