#include <stdint.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdarg.h>
#include "entity.h"
#include <stdio.h>

#define NULL_VECTOR2 (Vector2){-(1.0E12),-(1.0E12)};

/*
void InitEntityData(EntityData *data, int entityCount)
{
    data->positions = malloc(entityCount * sizeof(Vector2));
    data->velocities = malloc(entityCount * sizeof(Vector2));
    data->textureIDs = malloc(entityCount * sizeof(Texture2D*));
    data->entityCount = entityCount;
    data->texturesCount = 0;
    for (int i = 0; i < entityCount; ++i)
    {
        data->positions[i] = NULL_VECTOR2;
        data->velocities[i] = NULL_VECTOR2;
        data->textureIDs[i] = NULL;
    }
}

void InitEntityTextures(EntityData *data, int argCount, ...)
{
    va_list ap;
    va_start(ap, argCount);
    data->textures = malloc(argCount * sizeof(Texture2D));    
    for (int i = 0; i < argCount; ++i)
    {
        
        data->textures[i] = va_arg(ap, Texture2D);
    }
    va_end(ap);   
}

void DrawEntities(EntityData *data)
{
    for (int i = 0; i < data->texturesCount; ++i)
    {
        DrawTextureV(*data->textureIDs[i], data->positions[i], WHITE);
    }
}

void SetEntityTexture(EntityData *data, uint8_t ID, uint8_t textureID)
{    
    data->textureIDs[ID] = &data->textures[textureID];
    data->texturesCount++;
}

void FreeEntityData(EntityData *data)
{
    free(data->positions);
    free(data->textureIDs);
    free(data->textures);
    free(data->velocities);
}
*/