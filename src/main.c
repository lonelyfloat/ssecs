#include <raylib.h>
#include <stdio.h>
#include "ecs/ecs.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten/emscripten.h>
#endif

EntityData entityData;

void UpdateDrawFrame(void);
Texture2D tex;
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitEntityData(&entityData, 5, 2, (size_t[]){sizeof(Vector2), sizeof(Texture2D*)});
    InitWindow(screenWidth, screenHeight, "ecs test");
    tex = LoadTexture("assets/gun.png");
    for (int i = 0; i < 5; ++i)
    {
        SetECSData(&entityData, i, COMPONENT_DRAW, &tex, Texture2D*);
        SetECSData(&entityData, i, COMPONENT_POSITION, ((Vector2){i * 800/5, screenHeight/2}), Vector2);
    }

    #ifndef __EMSCRIPTEN__
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            UpdateDrawFrame();
        }

    #else
        emscripten_set_main_loop(UpdateDrawFrame, 0,1);
    #endif
    //--------------------------------------------------------------------------------------


    // De-Initialization
    //--------------------------------------------------------------------------------------
    FreeEntityData(&entityData);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void UpdateDrawFrame(void)
{
        // Main game loop
        // Update
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawFPS(0,0);
            DrawEntities(&entityData);
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------

}