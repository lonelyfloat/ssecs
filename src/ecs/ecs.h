#ifndef H_ENTITY
#define H_ENTITY

#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>

typedef uint32_t EntityID;

typedef enum ComponentType
{
    COMPONENT_POSITION,
    COMPONENT_MOVE,
    COMPONENT_DRAW
} ComponentType;

typedef struct ComponentData
{
    void* data;
    EntityID *dense; // Get IDs by using index here
    EntityID *sparse; // Get indices by using ID here
    uint32_t count;
} ComponentData;

typedef struct EntityData
{
    uint8_t componentCount;
    ComponentData* componentData;
} EntityData;

void InitEntityData(EntityData *data, int entityCount,int componentCount, size_t sizes[]);
void FreeEntityData(EntityData *data);

bool HasComponent(EntityData *data, ComponentType type, EntityID ID);
//void AddComponent(EntityData *data, ComponentType type, EntityID ID, void* addedData);
// (((char*)data->componentData[type].data) + (ID * sizes[type]))
#define AddComponent(entData, ID, type, val, valType)                                                  \
    do {                                                                                               \
    (entData)->componentData[type].dense[(entData)->componentData[type].count] = ID;                   \
    (entData)->componentData[type].sparse[ID] = (entData)->componentData[type].count;                  \
    ((valType*)(entData)->componentData[type].data)[(entData)->componentData[type].count] = val;       \
    ++(entData)->componentData[type].count;}while(0) 
    
//((valType *)((entData)->componentData[type].data))[ID];

/* fix these later!
void SetECSData(EntityData *data, uint8_t ID, ComponentType type, void *in);
void GetECSData(EntityData *data, int ID, ComponentType type, void *out);
*/

// systems

#endif



