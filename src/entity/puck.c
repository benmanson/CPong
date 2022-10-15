#include <stdlib.h>

#include "../game/common.h"
#include "paddle.h"
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

int collides(Puck* puck, Paddle* paddle)
{
    if (
        paddle->x < puck->x + PUCKSIZE &&
        paddle->x + PADDLE_WIDTH > puck->x &&
        paddle->y < puck->y + PUCKSIZE &&
        paddle->y + PADDLE_HEIGHT > puck->y
    )
    {
        return 1;
    }

    return 0;
}

void reset_puck(Puck* puck)
{
    puck->x = SCREEN_WIDTH / 2;
    puck->y = SCREEN_HEIGHT / 2;

    int dir = rand() % 1;

    puck->xVel = dir ? PUCK_X_SPEED : -1 * PUCK_X_SPEED;
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
