#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED

class Paddle
{
    int x, y;
    int originalX, originalY;
public:
    Paddle();
    Paddle(int posX, int posY);
    inline void Reset()
    {
        x = originalX;
        y = originalY;
    };
    inline int getX()
    {
        return x;
    };
    inline int getY()
    {
        return y;
    };
    inline void moveUp()
    {
        y--;
    };
    inline void moveDown()
    {
        y++;
    };
};


#endif // PADDLE_H_INCLUDED
