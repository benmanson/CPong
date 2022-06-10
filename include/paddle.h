#pragma once

#include "common.h"

#define PADDLE_WIDTH  10
#define PADDLE_HEIGHT 100

typedef struct
{
    int x;
    int y;

    int yVel;
} Paddle;

Paddle* get_paddle();
void delete_paddle(Paddle* paddle);

void move_paddle(Paddle* paddle);
