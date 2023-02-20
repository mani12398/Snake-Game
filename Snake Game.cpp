#include <iostream>
#include <cstdlib> // rand function 
#include <ctime> // sleep
#include <Windows.h> // gotoxy
#include <conio.h> // kb hit 

using namespace std;
const int height = 20; // fix dont want to change
const int width = 40;
int snake_size = 3; // snake starting length
int score = 0;
int fruitx = 12; // starting fruit display
int fruity = 12; //
bool gameover = false; // game end 

struct point // snake
{
    int x;
    int y;
};

void gotoxy(int x, int y)  // cursor ko kisi bhi point pe lee jane ke liye yaaa koi cheez print karni hu
{

    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void boundary()
{

    for (int i = 0; i < width; i++)
        cout << "+";
    cout << endl;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            if (j == 0) // left wall
                cout << "+";

            if (j == width - 2) // right wall      points match 
                cout << "+";

            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
        cout << "+";
    cout << endl;

    gotoxy(fruitx, fruity); // first time print 
    cout << "F";

}

void Displaysnake(point p[])
{
    gotoxy(p[0].x, p[0].y);
    cout << "O";

    int i;
    for (i = 1; i < snake_size; i++)
    {
        gotoxy(p[i].x, p[i].y);
        cout << "o";

    }

}

void removesnake(point p[])
{
    for (int index = 0; index < snake_size; index++)
    {
        gotoxy(p[index].x, p[index].y);
        cout << " ";
    }

}

void Moveup(point p[])
{
    int index;

    for (index = snake_size; index > 0; index--)
    {
        p[index].x = p[index - 1].x;
        p[index].y = p[index - 1].y;

    }
    p[index].y = p[index].y - 1;
}

void Movedown(point p[])
{
    int index;
    for (index = snake_size; index > 0; index--)
    {
        p[index].x = p[index - 1].x;
        p[index].y = p[index - 1].y;

    }
    p[index].y = p[index].y + 1;
}

void Moveright(point p[])
{
    int index;
    for (index = snake_size; index > 0; index--)
    {
        p[index].x = p[index - 1].x;
        p[index].y = p[index - 1].y;

    }
    p[index].x = p[index].x + 1;
}

void Moveleft(point p[])
{
    int index;
    for (index = snake_size; index > 0; index--)
    {
        p[index].x = p[index - 1].x;
        p[index].y = p[index - 1].y;

    }
    p[index].x = p[index].x - 1;
}

void movement(point p[], char i)
{

    if (i == 72)
    {
        Moveup(p);
    }
    else if (i == 80)
    {
        Movedown(p);
    }
    else if (i == 77)
    {
        Moveright(p);
    }
    else if (i == 75)
    {
        Moveleft(p);
    }


}

void boundary_check(point p[])
{

    if (p[0].x >= width - 1)

    {
        gameover = true;

        gotoxy(0, height + 3);
        cout << "Game over!" << endl;
        system("PAUSE");

    }

    if (p[0].x <= 0)
    {
        gameover = true;

        gotoxy(0, height + 3);
        cout << "Game over!" << endl;
        system("PAUSE");

    }

    if (p[0].y > height)

    {
        gameover = true;

        gotoxy(0, height + 3);
        cout << "Game over!" << endl;
        system("PAUSE");

    }

    if (p[0].y <= 0)
    {
        gameover = true;

        gotoxy(0, height + 3);
        cout << "Game over!" << endl;
        system("PAUSE");

    }

    for (int index = 1; index < snake_size; index++)
    {
        if (p[0].x == p[index].x && p[0].y == p[index].y)
        {
            gameover = true;

            gotoxy(0, height + 3);
            cout << "Game over!" << endl;
            system("PAUSE");
        }
    }

}

void fruit(point p[], int& speed, int& score)
{
    if (p[0].x == fruitx && p[0].y == fruity)
    {


        fruitx = 2 + rand() % (width - 12);
        fruity = 2 + rand() % (height - 12);

        for (int i = 0; i < snake_size; i++)
        {
            if (fruitx == p[i].x && fruity == p[i].y)
            {
                fruitx = 2 + rand() % (width - 12);
                fruity = 2 + rand() % (height - 12);
            }
        }

        gotoxy(fruitx, fruity);

        cout << "F";
        score = score + 10;
        snake_size++;

        if (speed > 50)
        {
            speed = speed - 50;
        }


        gotoxy(0, height + 2);
        cout << "Score: " << score;

    }

}

void game_setup()
{

    system("Color 3");
    int x;
    cout << endl << endl;
    cout << "\t\t\t\t\tWelcome To PT Snake Game Project" << endl << endl;
    cout << "\n\n\tFALL-2020 BSCS" << endl << "\tSECTION B" << endl << "\tGroup 2" << endl << endl << "\tGroup Members: " << endl << endl << "\tMuhammad Abdur-Rehman-022" << endl << "\tMuhammad Ammar Zaid-014" << endl << "\tMohammad Ali-052" << endl << endl << endl;
    cout << "\tInstructions" << endl << endl << endl;
    cout << "\tUSE Arrow KEYS TO MOVE SNAKE" << endl << endl << endl;
    cout << "\tPress 1 and Enter to Start Game: ";
    cin >> x;

    system("cls");


}

int main()
{
    game_setup();
    char i = 0;
    int score = 0;
    int speed = 200;
    point p[300]; // snake size 
    p[0].x = width / 2; // snake first time display
    p[0].y = height / 2;
    boundary();

    gotoxy(0, height + 2);
    cout << "Score: " << score;

    while (gameover != true)
    {
        if (_kbhit())
        {
            i = _getch();// 77745
            i = _getch();//45
        }


        Sleep(speed);
        removesnake(p);
        movement(p, i);
        Displaysnake(p);

       

        fruit(p, speed, score);
        boundary_check(p);

    }

}