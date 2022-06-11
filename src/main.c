#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>

#include "common.h"
#include "paddle.h"
#include "pong.h"
#include "puck.h"

int main(int argc, char* argv[])
{
    Pong* game = start_game();

    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;

    if ((SDL_Init(SDL_INIT_VIDEO) < 0))
    {
        printf("SDL failed to initialize. SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow(
        "CPong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        printf("Failed to create window. SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    surface = SDL_GetWindowSurface(window);

    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;

    while (!quit)
    {
        Uint8* keyboardState = SDL_GetKeyboardState(NULL);

        printf(
            "W %d S %d UP %d DOWN %d\n",
            keyboardState[SDL_SCANCODE_W],
            keyboardState[SDL_SCANCODE_S],
            keyboardState[SDL_SCANCODE_UP],
            keyboardState[SDL_SCANCODE_DOWN]
        );

        // Paddle 1 movement
        if (keyboardState[SDL_SCANCODE_W] & !(keyboardState[SDL_SCANCODE_S]))
        {
            printf("Paddle 1 up\n");
            game->paddle1->yVel = 1;
        }
        else if (!(keyboardState[SDL_SCANCODE_W]) & keyboardState[SDL_SCANCODE_S])
        {
            printf("Paddle 1 down\n");
            game->paddle1->yVel = -1;
        }
        else
        {
            game->paddle1->yVel = 0;
        }

        // Paddle 2 movement
        if (keyboardState[SDL_SCANCODE_UP] & !(keyboardState[SDL_SCANCODE_DOWN]))
        {
            printf("Paddle 2 up\n");
            game->paddle2->yVel = 1;
        }
        else if (!(keyboardState[SDL_SCANCODE_UP]) & keyboardState[SDL_SCANCODE_DOWN])
        {
            printf("Paddle 2 down\n");
            game->paddle2->yVel = -1;
        }
        else
        {
            game->paddle2->yVel = 0;
        }

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
        }

        game_step(game);

        printf("Puck @ %d, %d\n", game->puck->x, game->puck->y);
        printf("Paddle1 @ %d\n", game->paddle1->y);
        printf("Paddle2 @ %d\n", game->paddle2->y);
        SDL_Delay(50);
    }

    end_game(game);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return EXIT_SUCCESS;
}
