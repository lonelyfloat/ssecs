
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef SSECS_H_
#define SSECS_H_

typedef uint32_t EntityID; 
typedef uint8_t ComponentID;

typedef struct ComponentData
{
    void* data;       // Component data array
    EntityID *dense;  // Get IDs by using index here
    EntityID *sparse; // Get indices by using ID here
    EntityID count;   // how many elements there are in dense array
} ComponentData;

typedef struct EntityData
{
    ComponentID componentCount;
    ComponentData* componentData;
    EntityID maxEntities;
} EntityData;

void InitEntityData(EntityData *data, EntityID maxEntities, ComponentID componentCount, size_t sizes[]);
void FreeEntityData(EntityData *data);

bool HasComponent(EntityData *data, ComponentID type, EntityID ID);

#endif


#ifndef SSECS_IMPLEMENTATION
#define SSECS_IMPLEMENTATION 

#define GetComponentFromIndex(entData, index, type, valType) ((valType*)(entData)->componentData[type].data)[index]
// Input index (found in sparse), gives data                                 
#define GetComponentFromID(entData, ID, type, valType) ((valType*)(entData)->componentData[type].data)[(entData)->componentData[type].sparse[ID]]                                                     
// Input Entity ID (found in dense array), gives data

#define AddComponent(entData, ID, type, val, valType)                                                  \
    do     {                                                                                                                                                                                            \
     if(!HasComponent(entData, type, ID))                                                                                                                                                               \
     {                                                                                                                                                                                                  \
        (entData)->componentData[type].dense[(entData)->componentData[type].count] = ID;                                                                                                                \
        (entData)->componentData[type].sparse[ID] = (entData)->componentData[type].count;                                                                                                               \
        ((valType*)(entData)->componentData[type].data)[(entData)->componentData[type].count] = val;                                                                                                    \
        ++(entData)->componentData[type].count;                                                                                                                                                         \
     }                                                                                                                                                                                                  \
    } while(0)

#define RemoveComponent(entData, ID, type, valType)  \
    do     {                                                                                                                                                                                            \
     if(HasComponent(entData, type, ID))                                                                                                                                                                \
     {                                                                                                                                                                                                  \
        (entData)->componentData[type].dense[ (entData)->componentData[type].sparse[ID] ] = (entData)->componentData[type].dense[ ((entData)->componentData[type].count - 1) ];                             \
        ((valType*)((entData)->componentData[type].data))[(entData)->componentData[type].sparse[ID]] = ((valType*)((entData)->componentData[type].data))[((entData)->componentData[type].count - 1)];   \
        (entData)->componentData[type].sparse[(entData)->componentData[type].dense[((entData)->componentData[type].count - 1)]] = (entData)->componentData[type].sparse[ID];                            \
        --(entData)->componentData[type].count;                                                                                                                                                         \
     }                                                                                                                                                                                                  \
    } while(0)

void InitEntityData(EntityData *data, uint32_t maxEntities, ComponentID componentCount, size_t sizes[])
{
    data->maxEntities = maxEntities;
    data->componentData = malloc(componentCount*sizeof(ComponentData));
    data->componentCount = componentCount;
    for(int i=0; i<componentCount; ++i)
    {
        data->componentData[i].count = 0;
        data->componentData[i].dense = malloc((maxEntities)*sizeof(EntityID));
        data->componentData[i].sparse = malloc((maxEntities)*sizeof(EntityID));
        data->componentData[i].data = malloc((maxEntities)*sizes[i]);
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

#endif
