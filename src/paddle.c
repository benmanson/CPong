#include "pong/paddle.h"

Paddle* get_paddle()
{
    Paddle* paddle = (Paddle*) malloc(sizeof(Paddle));

    paddle->x = 0;
    paddle->y = 0;
    paddle->yVel = 0;

    return paddle;
}

void delete_paddle(Paddle* paddle)
{
    free(paddle);
}
