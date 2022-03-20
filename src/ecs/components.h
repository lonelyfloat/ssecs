#ifndef H_COMPONENTS
#define H_COMPONENTS

#include <raylib.h>
#include "ecs.h"

typedef struct MoveComponent
{
    float freq;
    float magnitude;
} MoveComponent;

void DrawEntities(EntityData* data);
void BounceEntities(EntityData* data);
#endif