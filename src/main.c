#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cool");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    Shader loadedShader = LoadShader(0, "shaders/firstcloud.frag");

    while (!WindowShouldClose()) {
        Vector2 dynamicScreenSize = (Vector2){GetScreenWidth(), GetScreenHeight()};

        float time = GetTime();
        float res[2] = {dynamicScreenSize.x, dynamicScreenSize.y}; 
        float mouse[2] = {GetMouseX(), GetMouseY()};

        int timeLoc = GetShaderLocation(loadedShader, "u_time");
        int resLoc = GetShaderLocation(loadedShader, "u_resolution");
        int mouseLoc = GetShaderLocation(loadedShader, "u_mouse");

        SetShaderValue(loadedShader, timeLoc, &time, SHADER_UNIFORM_FLOAT);
        SetShaderValue(loadedShader, resLoc, res, SHADER_UNIFORM_VEC2);
        SetShaderValue(loadedShader, mouseLoc, mouse, SHADER_UNIFORM_VEC2);

        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(0, 0, 10, BLUE);

        BeginShaderMode(loadedShader);
        DrawRectangle(0, 0, dynamicScreenSize.x, dynamicScreenSize.y, WHITE);
        EndShaderMode();
    
        DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadShader(loadedShader);
    CloseWindow();
    return 0;
}
