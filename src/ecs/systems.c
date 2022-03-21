#include <math.h>
#include <raylib.h>
#include "components.h"

#define GetECSDataIndex(entData, index, type, valType) ((valType*)(entData)->componentData[type].data)[index]
// Input index (found in sparse), gives data                                 
#define GetECSDataID(entData, ID, type, valType) ((valType*)(entData)->componentData[type].data)[(entData)->componentData[type].sparse[ID]]                                                     
// Input Entity ID (found in dense), gives data
void BounceEntities(EntityData* data)
{
    for (int i = 0; i < data->componentData[COMPONENT_MOVE].count; ++i)
    {
        if(HasComponent(data, COMPONENT_POSITION, data->componentData[COMPONENT_MOVE].dense[i]))
        {
        GetECSDataID(data, data->componentData[COMPONENT_MOVE].dense[i], COMPONENT_POSITION, Vector2).y += 
        sinf(GetTime() * GetECSDataIndex(data, i, COMPONENT_MOVE, MoveComponent).freq) * GetECSDataIndex(data, i, COMPONENT_MOVE, MoveComponent).magnitude * GetFrameTime();
        }
    }
    
}

void DrawEntities(EntityData* data)
{
    for (int i = 0; i < data->componentData[COMPONENT_DRAW].count; ++i)
    {
        if(HasComponent(data, COMPONENT_POSITION, data->componentData[COMPONENT_DRAW].dense[i]))
        {
            DrawTextureV(*GetECSDataIndex(data, i, COMPONENT_DRAW, Texture2D*), GetECSDataID(data, data->componentData[COMPONENT_DRAW].dense[i], COMPONENT_POSITION, Vector2), WHITE);
        }
    }
}
