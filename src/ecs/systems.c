#include "components.h"
#include <math.h>

void BounceEntities(EntityData* data)
{
    for (int i = 0; i < data->componentData[COMPONENT_POSITION].count; ++i)
    {
        ((Vector2*)data->componentData[COMPONENT_POSITION].data)[i].y += (sinf(GetTime() * GetECSData(data, i, COMPONENT_MOVE, MoveComponent).freq) * GetECSData(data, i, COMPONENT_MOVE, MoveComponent).magnitude) * GetFrameTime();
    }
    
}

void DrawEntities(EntityData* data)
{
    for (int i = 0; i < data->componentData[COMPONENT_DRAW].count; ++i)
    {
        if(HasComponent(data, COMPONENT_POSITION, data->componentData[COMPONENT_DRAW].sparse[i]))
            DrawTextureV(*((Texture2D**)data->componentData[COMPONENT_DRAW].data)[i], ((Vector2*)data->componentData[COMPONENT_POSITION].data)[i], WHITE);
    }
}
