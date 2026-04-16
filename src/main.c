#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cool");
    SetTargetFPS(60);

    Shader loadedShader = LoadShader(0, "shaders/helloworld.frag");

    // following the example at https://github.com/raysan5/raylib/blob/master/examples/shaders/shaders_postprocessing.c
    Shader grayShader = LoadShader(0, "shaders/helloworld.frag");
    RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (!WindowShouldClose()) {
        float value = GetTime();
        SetShaderValue(loadedShader, GetShaderLocation(loadedShader, "u_time"), &value, SHADER_UNIFORM_FLOAT);
        // printf("%d\n", GetShaderLocation(loadedShader, "u_time"));

        BeginDrawing();
            ClearBackground(WHITE);
            DrawCircle(0, 0, 10, BLUE);

            BeginShaderMode(loadedShader);
                DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
                DrawTextureRec(target.texture, (Rectangle){0, 0, (float)target.texture.width, (float)-target.texture.height}, (Vector2){0, 0}, WHITE);
            EndShaderMode();
        
            DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadShader(loadedShader);
    CloseWindow();
    return 0;
}
