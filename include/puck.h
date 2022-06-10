#pragma once

#include "common.h"

typedef struct
{
    int x;
    int y;

    int xVel;
    int yVel;
} Puck;

Puck* get_puck();
void delete_puck(Puck* puck);

void move_puck(Puck* puck);
