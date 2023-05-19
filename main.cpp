#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <random>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

using namespace std;
void Pause()
{
#ifdef _WIN32
    system("pause");
#else
    system("read -n1 -r -p \"Press any key to continue...\" key");
#endif
}

class Game
{
    char char1 = '1', char2 = '2', char3 = '3', char4 = '4', char5 = '5', char6 = '6', char7 = '7', char8 = '8', char9 = '9';
    int random = 6, comp = 0;

public:
    char u;

    void PrintBoard()
    {
        cout << "_" << char1 << "_|_" << char2 << "_|_" << char3 << "_\n_" << char4 << "_|_" << char5 << "_|_" << char6 << "_\n " << char7 << " | " << char8 << " | " << char9 << " \n";
    }
    void getUserMove()
    {
        cout << "Enter a number from 1 to 9: \n OR \nPress 'q' to quit\n";
        cout << ">>";
        cin >> u;
        cin.ignore();

        if (u == '1')
        {
            if (char1 == '1')
            {
                char1 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == '2')
        {
            if (char2 == '2')
            {
                char2 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == '3')
        {
            if (char3 == '3')
            {
                char3 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == '4')
        {
            if (char4 == '4')
            {
                char4 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == '5')
        {
            if (char5 == '5')
            {
                char5 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == '6')
        {
            if (char6 == '6')
            {
                char6 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == '7')
        {
            if (char7 == '7')
            {
                char7 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == '8')
        {
            if (char8 == '8')
            {
                char8 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == '9')
        {
            if (char9 == '9')
            {
                char9 = 'X';
            }
            else
            {
                cout << "Invalid Move\n";
                Pause();
            }
        }
        else if (u == 'q')
        {
            cout << "Quitting...\n";
        }
        else
        {
            cout << "Invalid Move\n";
            Pause();
        }
    }

    void ComputerMove()
    {
        srand(time(NULL));
        comp = rand() % random + 1;
    }
};

void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    ClearScreen();

    Game game;

    game.PrintBoard();
    do
    {
        game.getUserMove();
        ClearScreen();
        game.PrintBoard();
    } while (game.u != 'q');
    return 0;
}