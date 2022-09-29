#pragma once

#include "common.h"
#include "paddle.h"
#include "puck.h"

#include <stdio.h>

typedef struct
{
    Puck* puck;

    Paddle* paddle1;
    Paddle* paddle2;
} Pong;

Pong* start_game();
void end_game(Pong* game);

void game_step(Pong* game);
