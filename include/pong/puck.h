#pragma once

#include "pong/common.h"

typedef struct
{
    int x;
    int y;

    int xVel;
    int yVel;
} Puck;

Puck* get_puck();
void delete_puck();