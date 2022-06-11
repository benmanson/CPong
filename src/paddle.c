#include "paddle.h"

Paddle* get_paddle()
{
    Paddle* paddle = (Paddle*) malloc(sizeof(Paddle));

    paddle->x = 0;
    paddle->y = SCREEN_HEIGHT / 2;
    paddle->yVel = 0;

    return paddle;
}

void delete_paddle(Paddle* paddle)
{
    free(paddle);
    paddle = NULL;
}

void move_paddle(Paddle* paddle)
{
    if (paddle->y >= SCREEN_HEIGHT | paddle->y <= 0)
    {
        paddle->yVel = 0;
    }
    paddle->y += paddle->yVel;
}
