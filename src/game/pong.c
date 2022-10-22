#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "pong.h"

Pong* start_game()
{
    Pong* game = (Pong *) malloc(sizeof(Pong));

    game->puck = get_puck();

    game->paddle1 = get_paddle(-1);
    game->paddle2 = get_paddle(1);

    return game;
}

void end_game(Pong* game)
{
    delete_paddle(game->paddle1);
    delete_paddle(game->paddle2);
    delete_puck(game->puck);

    free(game);
    game = NULL;
}

float collision_yVel(int puckY, int paddleY)
{
    int collision = (int) (7 * ((float) (puckY - paddleY) / PADDLE_HEIGHT));

    switch (collision)
    {
    case 0:
        return -4;

    case 1:
    case 2:
        return -2;

    case 3:
        return 0;

    case 4:
    case 5:
        return 2;

    case 6:
        return 4;

    }
    return 0;
}

void game_step(Pong* game)
{
    if (collides(game->puck, game->paddle1))
    {
        game->puck->xVel = fminf(1.1 * (game->puck->xVel * game->paddle1->id), 12.0);
        game->puck->yVel = collision_yVel(game->puck->y, game->paddle1->y);
    }
    else if (collides(game->puck, game->paddle2))
    {
        game->puck->xVel = fmaxf(-1.1 * (game->puck->xVel * game->paddle2->id), -12.0);
        game->puck->yVel = collision_yVel(game->puck->y, game->paddle2->y);
    }

    if (game->puck->x + game->puck->xVel >= (SCREEN_WIDTH - PUCKSIZE))
    {
        score(game->paddle1);
        reset_puck(game->puck);
    }
    else if (game->puck->x <= 0)
    {
        score(game->paddle2);
        reset_puck(game->puck);
    }

    move_puck(game->puck);
    move_paddle(game->paddle1);
    move_paddle(game->paddle2);
}
