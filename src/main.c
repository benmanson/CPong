#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>

#include "pong/common.h"
#include "pong/paddle.h"
#include "pong/puck.h"

int main(int argc, char* argv[])
{
    Puck* puck = get_puck();

    Paddle* paddle1 = get_paddle();
    Paddle* paddle2 = get_paddle();

    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;

    if (!SDL_Init(SDL_INIT_VIDEO) < 0)
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
        paddle1->yVel = 0;
        paddle2->yVel = 0;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
            if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_w:
                        paddle1->yVel = 1;
                        break;
                    case SDLK_s:
                        paddle1->yVel = -1;
                        break;
                    case SDLK_UP:
                        paddle2->yVel = 1;
                        break;
                    case SDLK_DOWN:
                        paddle2->yVel = -1;
                        break;
                }
            }
        }

        move_paddle(paddle1);
        move_paddle(paddle2);
        move_puck(puck);

        printf("Puck @ %d, %d\n", puck->x, puck->y);
        printf("Paddle1 @ %d\n", paddle1->y);
        printf("Paddle2 @ %d\n", paddle2->y);
        SDL_Delay(50);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
