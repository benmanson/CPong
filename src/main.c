#include <stdio.h>

#include "pong/paddle.h"
#include "pong/puck.h"

int main(int argc, char* argv[])
{
    Puck* puck = get_puck();

    Paddle* paddle1 = get_paddle();
    Paddle* paddle2 = get_paddle();

    printf("Puck @ %p\n", puck);
    printf("Paddle1 @ %p\n", paddle1);
    printf("Paddle2 @ %p\n", paddle2);

    delete_puck(puck);

    delete_paddle(paddle1);
    delete_paddle(paddle2);

    printf("Puck @ %p\n", puck);
    printf("Paddle1 @ %p\n", paddle1);
    printf("Paddle2 @ %p\n", paddle2);

    printf("Goodbye, world.\n");

    return 0;
}
