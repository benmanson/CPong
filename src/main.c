#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include <SDL.h>

#include "game/common.h"
#include "game/pong.h"

#include "entity/paddle.h"
#include "entity/puck.h"

void render_game(SDL_Renderer* renderer, Pong* game);

int main()
{
    Pong* game = start_game();

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event e;
    bool quit = false;

    while (!quit)
    {
        const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

        // printf(
        //     "W %d S %d UP %d DOWN %d\n",
        //     keyboardState[SDL_SCANCODE_W],
        //     keyboardState[SDL_SCANCODE_S],
        //     keyboardState[SDL_SCANCODE_UP],
        //     keyboardState[SDL_SCANCODE_DOWN]
        // );

        if (keyboardState[SDL_SCANCODE_Q])
        {
            quit = true;
            break;
        }

        // Paddle 1 movement
        if (keyboardState[SDL_SCANCODE_W] & (!keyboardState[SDL_SCANCODE_S]))
        {
            game->paddle1->yVel = -PADDLE_SPEED;
        }
        else if ((!keyboardState[SDL_SCANCODE_W]) & keyboardState[SDL_SCANCODE_S])
        {
            game->paddle1->yVel = PADDLE_SPEED;
        }
        else
        {
            game->paddle1->yVel = 0;
        }

        // Paddle 2 movement
        if (keyboardState[SDL_SCANCODE_UP] & (!keyboardState[SDL_SCANCODE_DOWN]))
        {
            game->paddle2->yVel = -PADDLE_SPEED;
        }
        else if ((!keyboardState[SDL_SCANCODE_UP]) & keyboardState[SDL_SCANCODE_DOWN])
        {
            game->paddle2->yVel = PADDLE_SPEED;
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
        render_game(renderer, game);

        SDL_Delay(10);
    }

    end_game(game);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    renderer = NULL;
    window = NULL;

    SDL_Quit();

    return EXIT_SUCCESS;
}

void render_game(SDL_Renderer* renderer, Pong* game)
{
    //Clear screen
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    SDL_Rect paddle1Rect = { game->paddle1->x, game->paddle1->y, PADDLE_WIDTH, PADDLE_HEIGHT };
    SDL_Rect paddle2Rect = { game->paddle2->x, game->paddle2->y, PADDLE_WIDTH, PADDLE_HEIGHT };
    SDL_Rect fillRect = { game->puck->x, game->puck->y, PUCKSIZE, PUCKSIZE };

    SDL_Rect rects[3] = { paddle1Rect, paddle2Rect, fillRect };
    int n = (int) sizeof(rects) / sizeof(rects[0]);

    //Render texture to screen
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

    for (int i = 0; i < n; i++)
    {
        SDL_RenderFillRect(renderer, &(rects[i]));
    }

    //Update screen
    SDL_RenderPresent(renderer);
}
