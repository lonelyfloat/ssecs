#include <stdint.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ecs.h"
#include <stdio.h>


void InitEntityData(EntityData *data, int entityCount,int componentCount, size_t sizes[])
{
    data->componentData = malloc(componentCount*sizeof(ComponentData));
    data->componentSizes = malloc(componentCount*sizeof(size_t));
    data->componentCount = componentCount;
    for(int i=0; i<componentCount; ++i)
    {
        data->componentSizes[i] = sizes[i];
        data->componentData[i].data = malloc(componentCount*sizes[i]);
    }
}

void FreeEntityData(EntityData *data)
{
    free(data->componentData);
    free(data->componentSizes);
    for (int i = 0; i < data->componentCount; ++i)
    {
        free(data->componentData[i].data);
    }
}

void DrawEntities(EntityData* data)
{
    for (int i = 0; i < data->componentData[COMPONENT_DRAW].count; ++i)
    {
        DrawTextureV(*((Texture2D**)data->componentData[COMPONENT_DRAW].data)[i], ((Vector2*)data->componentData[COMPONENT_POSITION].data)[i], WHITE);
    }
}

/* TODO: fix these!
void SetECSData(EntityData *data, uint8_t ID, ComponentType type, void *in)
{
    ((Vector2*)(data->componentData[type].data))[ID] = *(Vector2*)(in);
}

void GetECSData(EntityData *data, int ID, ComponentType type, void *out)
{
    *(Vector2*)(out) = *((Vector2 *)data->componentData[ID].data);
}
*/