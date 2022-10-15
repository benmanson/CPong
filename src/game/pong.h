#pragma once

#include "../entity/paddle.h"
#include "../entity/puck.h"

typedef struct
{
    Puck* puck;

    Paddle* paddle1;
    Paddle* paddle2;
} Pong;

Pong* start_game();
void end_game(Pong* game);

void game_step(Pong* game);
