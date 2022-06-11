#include "puck.h"

Puck* get_puck()
{
    Puck* puck = (Puck*) malloc(sizeof(Puck));
    puck->x = SCREEN_WIDTH / 2;
    puck->y = SCREEN_HEIGHT / 2;

    puck->xVel = rand() % 10;
    puck->yVel = rand() % 5;

    return puck;
}

void delete_puck(Puck* puck)
{
    free(puck);
    puck = NULL;
}

void move_puck(Puck* puck)
{
    puck->x += puck->xVel;
    puck->y += puck->yVel;

    if (puck->x + puck->xVel >= (SCREEN_WIDTH - PUCKSIZE) | puck->x <= 0 )
    {
        puck->xVel *= -1;
    }

    if (puck->y >= (SCREEN_HEIGHT - PUCKSIZE) | puck->y <= 0 )
    {
        puck->yVel *= -1;
    }
}
