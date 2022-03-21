#ifndef H_ENTITY
#define H_ENTITY

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t EntityID;

typedef enum ComponentType
{
    COMPONENT_POSITION,
    COMPONENT_DRAW,
    COMPONENT_MOVE,
} ComponentType;

typedef struct ComponentData
{
    void* data;       // Component data
    EntityID *dense;  // Get IDs by using index here
    EntityID *sparse; // Get indices by using ID here
    uint32_t count;   // how many elements there are in dense array
} ComponentData;

typedef struct EntityData
{
    uint8_t componentCount;
    ComponentData* componentData;
} EntityData;

void InitEntityData(EntityData *data, uint32_t entityCount, uint8_t componentCount, size_t sizes[]);
void FreeEntityData(EntityData *data);

bool HasComponent(EntityData *data, ComponentType type, EntityID ID);

#define AddComponent(entData, ID, type, val, valType)                                                  \
    do {                                                                                               \
    (entData)->componentData[type].dense[(entData)->componentData[type].count] = ID;                   \
    (entData)->componentData[type].sparse[ID] = (entData)->componentData[type].count;                  \
    ((valType*)(entData)->componentData[type].data)[(entData)->componentData[type].count] = val;       \
    ++(entData)->componentData[type].count;} while(0) 

#endif



