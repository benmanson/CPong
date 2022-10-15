#include <stdlib.h>

#include "../game/common.h"
#include "puck.h"

Puck* get_puck()
{
    Puck* puck = (Puck*) malloc(sizeof(Puck));
    reset_puck(puck);
    return puck;
}

void delete_puck(Puck* puck)
{
    free(puck);
    puck = NULL;
}


void reset_puck(Puck* puck)
{
    puck->x = SCREEN_WIDTH / 2;
    puck->y = SCREEN_HEIGHT / 2;

    int dir = rand() % 1;

    puck->xVel = dir ? 4 : -4;
    puck->yVel = (rand() % 2) + 2;
}

void move_puck(Puck* puck)
{
    puck->x += puck->xVel;
    puck->y += puck->yVel;

    if (puck->x + puck->xVel >= (SCREEN_WIDTH - PUCKSIZE) | puck->x <= 0 )
    {
        reset_puck(puck);
    }

    if (puck->y >= (SCREEN_HEIGHT - PUCKSIZE) | puck->y <= 0 )
    {
        puck->yVel *= -1;
    }
}
