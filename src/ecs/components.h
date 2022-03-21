#ifndef H_COMPONENTS
#define H_COMPONENTS

#include "ecs.h"

typedef struct MoveComponent
{
    float freq;      // sinwave frequency
    float magnitude; // sinwave magnitude
} MoveComponent;

void DrawEntities(EntityData* data);
void BounceEntities(EntityData* data);
#endif
