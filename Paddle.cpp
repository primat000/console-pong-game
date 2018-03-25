#include "Paddle.h"
Paddle::Paddle()
{
    x = y = 0;
};

Paddle::Paddle(int posX, int posY) : Paddle()
{
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
};


