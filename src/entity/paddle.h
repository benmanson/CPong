#pragma once

typedef struct
{
    int x;
    int y;

    int id;
    int yVel;

    int score;
} Paddle;

Paddle* get_paddle(int id);
void delete_paddle(Paddle* paddle);

void reset_paddle(Paddle* paddle);
void move_paddle(Paddle* paddle);

void score(Paddle* paddle);
