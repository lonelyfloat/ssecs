#include <raylib.h>
#include <stdio.h>
#include "entity.h"

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
    
    InitEntityData(&entityData, 2, 5, (size_t[]){sizeof(Vector2), sizeof(Texture2D*)});
    Vector2 v = (Vector2){screenWidth/2, screenHeight/2};
    SetECSData(&entityData, 0, COMPONENT_POSITION, v, Vector2);
    Vector2 position;
    GetECSData(&entityData, 0, COMPONENT_POSITION, &position, Vector2);
    InitWindow(screenWidth, screenHeight, "ecs test");
    printf("%f,%f\n", position.x, position.y);

    

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
            //DrawEntities(&entityData);
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------

}