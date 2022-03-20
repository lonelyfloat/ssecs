#ifndef H_ENTITY
#define H_ENTITY

#include <stdint.h>
#include <raylib.h>

typedef enum ComponentType
{
    COMPONENT_POSITION,
    COMPONENT_MOVE,
    COMPONENT_DRAW
} ComponentType;

typedef struct ComponentData
{
    void* data;
    uint32_t count;
} ComponentData;

typedef struct EntityData
{
    uint8_t componentCount;
    ComponentData* componentData;
    size_t *componentSizes;
} EntityData;

void InitEntityData(EntityData *data, int entityCount,int componentCount, size_t sizes[]);
void FreeEntityData(EntityData *data);


#define GetECSData(entData, ID, type, valType) ((valType*)(entData)->componentData[type].data)[ID]
#define SetECSData(entData, ID, type, val, valType) GetECSData(entData, ID, type, valType) = val;
//((valType *)((entData)->componentData[type].data))[ID];

/* fix these later!
void SetECSData(EntityData *data, uint8_t ID, ComponentType type, void *in);
void GetECSData(EntityData *data, int ID, ComponentType type, void *out);
*/

// systems

#endif



