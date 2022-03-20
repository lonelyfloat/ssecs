#ifndef H_ENTITY
#define H_ENTITY

#include <stdint.h>
#include <raylib.h>
#include <stdarg.h>

typedef enum mType
{
    TYPE_INT,
    TYPE_UINT,
    TYPE_FLOAT,
    TYPE_CHARPTR,
    TYPE_VEC2,
    TYPE_TEX2D,
    TYPE_RECT,
    TYPE_COLOR
} mType;

typedef struct ComponentMember 
{
    mType type;
    union ComponentMemberData
    {
        int32_t i;
        uint32_t u;
        float f;
        char *cptr;
        Vector2 v2;
        Texture2D tex2D;
        Rectangle rect;
        Color color;
    } data;

} ComponentMember;

typedef struct ComponentCreateData 
{
    
} ComponentCreateData;

typedef struct ComponentData 
{
    ComponentMember **members; // Members for the components
    uint16_t count; // how many of this component there are
} ComponentData;



/*
    int entityCount;
    uint8_t componentCount;
    ComponentInfo *components;

*/
typedef struct EntityData
{
    int entityCount;
    uint8_t componentCount;
    ComponentData *componentData;
} EntityData;

void InitEntityData(EntityData *data, int entityCount);
void CreateComponent(EntityData* data, uint8_t componentID, uint16_t memberCount, ...);
void InitEntityTextures(EntityData *data, int argCount, ...);
void SetEntityTexture(EntityData *data, uint8_t ID, uint8_t textureID);
void DrawEntities(EntityData *data);
void FreeEntityData(EntityData *data);
/*



void CreateComponent(&data, 0, 2, TYPE_VEC2, TYPE_FLOAT);
void CreateComponent(EntityData* data, uint8_t componentID, uint16_t memberCount, ...);




*/
#endif