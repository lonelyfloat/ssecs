#include <raylib.h>
#include <stdio.h>
#include "ecs/ecs.h"
#include "ecs/components.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten/emscripten.h>
#endif

EntityData entityData;
Texture2D tex;
Vector2 e;

const int maxEntities = 15;
// ~80k entities before it goes below 60fps 

void UpdateDrawFrame(void);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitEntityData(&entityData, maxEntities, 3, (size_t[]){sizeof(Vector2), sizeof(Texture2D*), sizeof(MoveComponent)});
    InitWindow(screenWidth, screenHeight, "ecs test");
    tex = LoadTexture("assets/gun.png");
    
    for (int i = 0; i < maxEntities; ++i)
    {
        AddComponent(&entityData, i, COMPONENT_DRAW, &tex, Texture2D*);
        AddComponent(&entityData, i, COMPONENT_POSITION, ((Vector2){(i * 800/maxEntities) + 20, (screenHeight/2)}), Vector2);
        if(GetRandomValue(1,maxEntities) < 9)
            AddComponent(&entityData, i, COMPONENT_MOVE, ((MoveComponent){2, 50}), MoveComponent);
        
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
        BounceEntities(&entityData);
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