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

void game_step(Pong* game)
{
    if (collides(game->puck, game->paddle1))
    {
        game->puck->xVel = -1 * PUCK_X_SPEED * game->paddle1->id;
    }
    else if (collides(game->puck, game->paddle2))
    {
        game->puck->xVel = -1 * PUCK_X_SPEED * game->paddle2->id;
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
