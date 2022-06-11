#pragma once

#include "common.h"

#define PADDLE_WIDTH  25
#define PADDLE_HEIGHT 170

typedef struct
{
    int x;
    int y;

    int yVel;
} Paddle;

Paddle* get_paddle();
void delete_paddle(Paddle* paddle);

void move_paddle(Paddle* paddle);
