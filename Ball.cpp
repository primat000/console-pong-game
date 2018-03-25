#include "Ball.h"

Ball::Ball(int posX, int posY)

{
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
    dir = STOP;
};

void Ball::Reset()
{
    x = originalX;
    y = originalY;
    dir = STOP;
};

void Ball::changeDirection(DIRECTIONS d)
{
    dir = d;
};

void Ball::randomDirection()
{
    dir = (DIRECTIONS)((rand() %6 )+ 1);
};

void Ball::Move()
{
    switch(dir)
    {
    case STOP:
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        x--;
        y--;
        break;
    case DOWNLEFT:
        x--;
        y++;
        break;
    case UPRIGHT:
        x++;
        y--;
        break;
    case DOWNRIGHT:
        x++;
        y++;
        break;
    default:
        break;
    }
};


