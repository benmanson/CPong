#include "pong/puck.h"

Puck* get_puck()
{
    Puck* puck = (Puck*) malloc(sizeof(Puck));
    return puck;
}

void delete_puck(Puck* puck)
{
    free(puck);
}
