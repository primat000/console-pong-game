#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED
#include "Ball.h"
#include "Paddle.h"
#include <time.h>
#include <conio.h>
class GameManager
{
    int width, heigth;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    Ball *ball;
    Paddle *player1;
    Paddle *player2;
public:
    GameManager(int w, int h);
    void ScoreUp(Paddle * player);
    void Draw();
    void NextMove();
    void DetectAndFixCollisions();
    void run();
    ~GameManager();
};
#endif // GAMEMANAGER_H_INCLUDED
