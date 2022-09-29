#pragma once

#include "common.h"

#define PADDLE_WIDTH  25
#define PADDLE_HEIGHT 170

typedef struct
{
    int x;
    int y;

    int yVel;

    int score;
} Paddle;

Paddle* get_paddle(int id);
void delete_paddle(Paddle* paddle);

void reset_paddle(Paddle* paddle);
void move_paddle(Paddle* paddle);

void score(Paddle* paddle);
