#include <stdlib.h>
#include "ecs.h"


void InitEntityData(EntityData *data, uint32_t entityCount, uint8_t componentCount, size_t sizes[])
{
    data->componentData = malloc(componentCount*sizeof(ComponentData));
    data->componentCount = componentCount;
    for(int i=0; i<componentCount; ++i)
    {
        data->componentData[i].count = 0;
        data->componentData[i].dense = malloc(entityCount*sizeof(EntityID));
        data->componentData[i].sparse = malloc(entityCount*sizeof(EntityID));
        data->componentData[i].data = malloc(entityCount*sizes[i]);
    }
}

void FreeEntityData(EntityData *data)
{
    free(data->componentData);
    for (int i = 0; i < data->componentCount; ++i)
    {
        free(data->componentData[i].dense);
        free(data->componentData[i].sparse);
        free(data->componentData[i].data);
    }
}

bool HasComponent(EntityData *data, ComponentType type, EntityID ID)
{
    return ((data->componentData[type].sparse[ID] < data->componentData[type].count) && (data->componentData[type].dense[data->componentData[type].sparse[ID]] == ID));
}
