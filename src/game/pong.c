#include <stdlib.h>

#include "common.h"
#include "pong.h"

Pong* start_game()
{
    Pong* game = (Pong *) malloc(sizeof(Pong));

    int x = atoi("1203");

    game->puck = get_puck();

    game->paddle1 = get_paddle(0);
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
    move_puck(game->puck);
    move_paddle(game->paddle1);
    move_paddle(game->paddle2);

    if ((game->puck->x <= (game->paddle1->x + PADDLE_WIDTH)) && (game->puck->x >= game->paddle1->x))
    {
        if ((game->puck->y >= (game->paddle1->y)) && (game->puck->y <= (game->paddle1->y + PADDLE_HEIGHT)))
        {
            game->puck->xVel *= -1;
        }
    }
    else if (((game->puck->x+PUCKSIZE) >= (game->paddle2->x)) && ((game->puck->x+PUCKSIZE) <= (game->paddle2->x + PADDLE_WIDTH)))
    {
        if ((game->puck->y >= (game->paddle2->y)) && (game->puck->y <= (game->paddle2->y + PADDLE_HEIGHT)))
        {
            game->puck->xVel *= -1;
        }
    }

    if (game->puck->x + game->puck->xVel >= (SCREEN_WIDTH - PUCKSIZE))
    {
        score(game->paddle1);
        reset_puck(game->puck);
        // printf("Player1: %d\tPlayer 2: %d", game->paddle1->score, game->paddle2->score);
    }
    else if (game->puck->x <= 0)
    {
        score(game->paddle2);
        reset_puck(game->puck);
        // printf("Player1: %d\tPlayer 2: %d", game->paddle1->score, game->paddle2->score);
    }
}
