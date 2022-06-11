#pragma once

#include "common.h"

#define PUCKSIZE 25

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
