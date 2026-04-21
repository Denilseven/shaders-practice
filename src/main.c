#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cool");
    SetTargetFPS(60);

    Shader loadedShader = LoadShader(0, "shaders/firstcloud.frag");

    // following the example at https://github.com/raysan5/raylib/blob/master/examples/shaders/shaders_postprocessing.c
    RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (!WindowShouldClose()) {
        float time = GetTime();
        float res[2] = {SCREEN_WIDTH, SCREEN_HEIGHT}; 
        float mouse[2] = {GetMouseX(), GetMouseY()};

        int timeLoc = GetShaderLocation(loadedShader, "u_time");
        int resLoc = GetShaderLocation(loadedShader, "u_resolution");
        int mouseLoc = GetShaderLocation(loadedShader, "u_mouse");

        SetShaderValue(loadedShader, timeLoc, &time, SHADER_UNIFORM_FLOAT);
        SetShaderValue(loadedShader, resLoc, res, SHADER_UNIFORM_VEC2);
        SetShaderValue(loadedShader, mouseLoc, mouse, SHADER_UNIFORM_VEC2);
        // printf("time: %d res: %d mouse: %d\n", timeLoc, resLoc, mouseLoc);

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
