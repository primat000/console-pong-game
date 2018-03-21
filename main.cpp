#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

enum DIRECTIONS
{
    STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT =6
};
class Ball
{
private:
    int x,y;
    int originalX, originalY;
    DIRECTIONS dir;
public:
    Ball(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        dir = STOP;
    }
    void Reset()
    {
        x = originalX;
        y = originalY;
        dir = STOP;
    }
    void changeDirection(DIRECTIONS d)
    {
        dir = d;
    }
    void randomDirection()
    {
        dir = (DIRECTIONS)((rand() %6 )+ 1);
    }
    inline int getX() {return x;}
    inline int getY() {return y;}
    inline DIRECTIONS getDirection() {return dir;}
    void Move()
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
            x--; y--;
            break;
        case DOWNLEFT:
            x--; y++;
            break;
        case UPRIGHT:
            x++; y--;
            break;
        case DOWNRIGHT:
            x++; y++;
            break;
        default:
            break;
        }
    }
    friend ostream & operator<<(ostream & o, Ball ball)
        {
            o << "Ball [" << ball.x << "," << ball.y << "][" << ball.dir << "]" << endl;
            return o;
        }
};
class Paddle
{
private:
    int x, y;
    int originalX, originalY;
public:
    Paddle()
    {
        x = y = 0;
    }
    Paddle(int posX, int posY) : Paddle()
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }
    inline void Reset(){x = originalX; y = originalY;}
    inline int getX() {return x;}
    inline int getY() {return y;}
    inline void moveUp() {y--;}
    inline void moveDown() {y++;}
    friend ostream & operator<<(ostream & o, Paddle p)
    {
        o << "Paddle [" << p.x << "," << p.y << "]";
        return o;
    }
};
class GameManager
{
private:
    int width, heigth;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    Ball *ball;
    Paddle *player1;
    Paddle *player2;
public:
    GameManager(int w, int h)
    {
        srand(time(NULL));
        quit = false;
        up1 = 'w'; up2 = 'i';
        down1 = 's'; down2 = 'k';
        score1 = score2 = 0;
        width = w; heigth = h;
        ball = new Ball( w /2, h / 2);
        player1 = new Paddle(1, h/2 -3);
        player2  = new Paddle(w - 2, h / 2 - 3);
    }
    void ScoreUp(Paddle * player)
    {
        if (player == player1) score1++;
        else if (player == player2) score2++;
        ball->Reset();
        player1->Reset();
        player2->Reset();
    }
    void Draw()
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
    void Input()
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

            if(current == 'q') quit = true;
        }
    }
    void Logic()
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
    void run()
    {
        while(!quit){
            Draw();
            Input();
            Logic();
        }
    }
    ~GameManager()
    {
        delete ball;
        delete player1;
        delete player2;
    }
};

int main()
{
    GameManager game(40, 20);
    game.run();
    return 0;
}
