#include <stdint.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdarg.h>
#include "entity.h"
#include <stdio.h>

#define NULL_VECTOR2 (Vector2){-(1.0E12),-(1.0E12)};

void InitEntityData(EntityData *data, int componentCount, int entityCount, size_t sizes[])
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