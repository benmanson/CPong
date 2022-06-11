#include "pong.h"

Pong* start_game()
{
    Pong* game = (Pong *) malloc(sizeof(Pong));

    game->puck = get_puck();

    game->paddle1 = get_paddle();
    game->paddle2 = get_paddle();

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
}
