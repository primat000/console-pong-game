#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include <iostream>
using namespace std;
enum DIRECTIONS
{
    STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT =6
};

class Ball
{
int x, y;
int originalX, originalY;
DIRECTIONS dir;
public:
    Ball(int posX, int posY);
    void Reset();
    void changeDirection(DIRECTIONS d);
    void randomDirection();
    void Move();
    inline int getX(){ return x; }
    inline int getY(){ return y; }
    inline DIRECTIONS getDirection()
    {
        return dir;
    }
};

#endif // BALL_H_INCLUDED
