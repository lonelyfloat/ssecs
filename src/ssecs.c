#include <stdlib.h>
#include "ssecs.h"


void InitEntityData(EntityData *data, uint32_t maxEntities, ComponentID componentCount, size_t sizes[])
{
    data->componentData = malloc(componentCount*sizeof(ComponentData));
    data->componentCount = componentCount;
    for(int i=0; i<componentCount; ++i)
    {
        data->componentData[i].count = 0;
        data->componentData[i].dense = malloc(maxEntities*sizeof(EntityID));
        data->componentData[i].sparse = malloc(maxEntities*sizeof(EntityID));
        data->componentData[i].data = malloc(maxEntities*sizes[i]);
    }
}

void FreeEntityData(EntityData *data)
{
    for (int i = 0; i < data->componentCount; ++i)
    {
        free(data->componentData[i].dense);
        free(data->componentData[i].sparse);
        free(data->componentData[i].data);
    }
    free(data->componentData);
}

bool HasComponent(EntityData *data, ComponentID type, EntityID ID)
{
    return ((data->componentData[type].sparse[ID] < data->componentData[type].count) && (data->componentData[type].dense[data->componentData[type].sparse[ID]] == ID));
}
