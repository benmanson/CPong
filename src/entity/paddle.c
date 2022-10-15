#include <stdlib.h>

#include "../game/common.h"
#include "paddle.h"

Paddle* get_paddle(int id)
{
    Paddle* paddle = (Paddle*) malloc(sizeof(Paddle));
    paddle->score = 0;

    switch (id)
    {
    case 0:
        paddle->x = 0;
        break;

    case 1:
        paddle->x = SCREEN_WIDTH - PADDLE_WIDTH;
        break;

    default:
        exit(1);
    }

    reset_paddle(paddle);
    return paddle;
}

void delete_paddle(Paddle* paddle)
{
    free(paddle);
    paddle = NULL;
}

void reset_paddle(Paddle* paddle)
{
    paddle->y = SCREEN_HEIGHT / 2;
    paddle->yVel = 0;
}

void move_paddle(Paddle* paddle)
{
    if ((paddle->y+paddle->yVel) >= (SCREEN_HEIGHT - PADDLE_HEIGHT) | (paddle->y+paddle->yVel) <= 0)
    {
        paddle->yVel = 0;
    }
    paddle->y += paddle->yVel;
}

void score(Paddle* paddle)
{
    paddle->score += 1;
}
