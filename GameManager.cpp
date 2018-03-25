#include "GameManager.h"

GameManager::GameManager(int w, int h)
{
    srand(time(NULL));
    quit = false;
    up1 = 'w';
    up2 = 72;
    down1 = 's';
    down2 = 80;
    score1 = score2 = 0;
    width = w;
    heigth = h;
    ball = new Ball( w /2, h / 2);
    player1 = new Paddle(1, h/2 -3);
    player2  = new Paddle(w - 2, h / 2 - 3);
};
void GameManager::ScoreUp(Paddle * player)
{
    if (player == player1) score1++;
    else if (player == player2) score2++;
    ball->Reset();
    player1->Reset();
    player2->Reset();
}
void GameManager::Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << '\xB2';
    cout<<endl;
    for(int i = 0; i < heigth; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int ballx = ball->getX();
            int bally = ball->getY();
            int player1x = player1->getX();
            int player2x = player2->getX();
            int player1y = player1->getY();
            int player2y = player2->getY();

            if (j == 0) cout << '\xB2';

            if (ballx == j && bally == i)
                cout << '0'; // ball
            else if (player1x == j && player1y == i)
                cout << '\xB2'; //player 1
            else if (player2x == j && player2y == i)
                cout << '\xB2'; //player 2

            else if (player1x == j && player1y + 1 == i)
                cout << '\xB2'; //player 1
            else if (player1x == j && player1y + 2 == i)
                cout << '\xB2'; //player 1
            else if (player1x == j && player1y + 3 == i)
                cout << '\xB2'; //player 1

            else if (player2x == j && player2y + 1 == i)
                cout << '\xB2'; //player 2
            else if (player2x == j && player2y + 2 == i)
                cout << '\xB2'; //player 2
            else if (player2x == j && player2y + 3 == i)
                cout << '\xB2'; //player 2

            else
                cout << ' ';

            if (j == width -1) cout << '\xB2';

        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
        cout << '\xB2';
    cout<<"\nGame Score \nplayer1: " << score1 << "\t player2: " << score2 << endl;

}
void GameManager::NextMove()
{
    ball->Move();
    int ballx = ball->getX();
    int bally = ball->getY();
    int player1x = player1->getX();
    int player2x = player2->getX();
    int player1y = player1->getY();
    int player2y = player2->getY();

    if(_kbhit())
    {
        char current = _getch();
        if (current == up1)
            if (player1y > 0) player1->moveUp();
        if (current == up2)
            if (player2y > 0) player2->moveUp();
        if (current == down1)
            if (player1y + 4 < heigth) player1->moveDown();
        if (current == down2)
            if (player2y + 4 < heigth) player2->moveDown();

        if (ball->getDirection() == STOP)
            ball->randomDirection();

        if(current == 27) quit = true;
    }
}
void GameManager::DetectAndFixCollisions()
{
    int ballx = ball->getX();
    int bally = ball->getY();
    int player1x = player1->getX();
    int player2x = player2->getX();
    int player1y = player1->getY();
    int player2y = player2->getY();

    for(int i = 0; i < 4; i++) // for left paddle
        if (ballx == player1x + 1)
            if (bally == player1y + i)
                ball->changeDirection((DIRECTIONS)((rand()%3) + 4));

    for(int i = 0; i < 4; i++) // or rigth paddle
        if (ballx == player2x - 1)
            if (bally == player2y + i)
                ball->changeDirection((DIRECTIONS)((rand()%3) + 1));

    if (bally == heigth - 1) // bottom
        ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

    if (bally == 0) // top
        ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

    if (ballx == width - 1) // right wall
        ScoreUp(player1);

    if (ballx == 0) // left wall
        ScoreUp(player2);


}
void GameManager::run()
{
    while(!quit)
    {
        Draw();
        NextMove();
        DetectAndFixCollisions();
    }
}
GameManager::~GameManager()
{
    delete ball;
    delete player1;
    delete player2;
}
