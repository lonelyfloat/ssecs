#include <math.h>
#include "include/raylib.h"
#include "components.h"


void BounceEntities(EntityData* data)
{
    for (int i = 0; i < data->componentData[COMPONENT_MOVE].count; ++i)
    {
        if(HasComponent(data, COMPONENT_POSITION, data->componentData[COMPONENT_MOVE].dense[i]))
        {
        GetComponentFromID(data, data->componentData[COMPONENT_MOVE].dense[i], COMPONENT_POSITION, Vector2).y += 
        sinf(GetTime() * GetComponentFromIndex(data, i, COMPONENT_MOVE, MoveComponent).freq) * GetComponentFromIndex(data, i, COMPONENT_MOVE, MoveComponent).magnitude * GetFrameTime();
        }
    }
    
}

void DrawEntities(EntityData* data)
{
    for (int i = 0; i < data->componentData[COMPONENT_DRAW].count; ++i)
    {
        if(HasComponent(data, COMPONENT_POSITION, data->componentData[COMPONENT_DRAW].dense[i]))
        {
            DrawTextureV(*GetComponentFromIndex(data, i, COMPONENT_DRAW, Texture2D*), GetComponentFromID(data, data->componentData[COMPONENT_DRAW].dense[i], COMPONENT_POSITION, Vector2), WHITE);
        }
    }
}
