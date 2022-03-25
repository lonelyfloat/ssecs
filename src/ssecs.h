#ifndef H_ENTITY
#define H_ENTITY

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t EntityID; 
typedef uint8_t ComponentID;

typedef struct ComponentData
{
    void* data;       // Component data array
    EntityID *dense;  // Get IDs by using index here
    EntityID *sparse; // Get indices by using ID here
    uint32_t count;   // how many elements there are in dense array
} ComponentData;

typedef struct EntityData
{
    ComponentID componentCount;
    ComponentData* componentData;
} EntityData;

void InitEntityData(EntityData *data, uint32_t maxEntities, ComponentID componentCount, size_t sizes[]);
void FreeEntityData(EntityData *data);

bool HasComponent(EntityData *data, ComponentID type, EntityID ID);

#define GetComponentFromIndex(entData, index, type, valType) ((valType*)(entData)->componentData[type].data)[index]
// Input index (found in sparse), gives data                                 
#define GetComponentFromID(entData, ID, type, valType) ((valType*)(entData)->componentData[type].data)[(entData)->componentData[type].sparse[ID]]                                                     
// Input Entity ID (found in dense array), gives data

#define AddComponent(entData, ID, type, val, valType)                                                  \
    do {                                                                                               \
    (entData)->componentData[type].dense[(entData)->componentData[type].count] = ID;                   \
    (entData)->componentData[type].sparse[ID] = (entData)->componentData[type].count;                  \
    ((valType*)(entData)->componentData[type].data)[(entData)->componentData[type].count] = val;       \
    ++(entData)->componentData[type].count;} while(0) 

#define RemoveComponent(entData, ID, type, valType)  \
    do     {                                                \
     if(HasComponent(entData, type, ID))                                                            \
     {                                                                                              \
         --(entData)->componentData[type].count;                                                    \
        EntityID item = (entData)->componentData[type].dense[(entData)->componentData[type].count]; \
        EntityID denseIndex = (entData)->componentData[type].sparse[ID];                            \
        (entData)->componentData[type].dense[denseIndex] = item;                                    \
        (entData)->componentData[type].sparse[item] = denseIndex;                                   \
     }                                                                                              \
    } while(0)
#endif



