//TIC-TAC-TOE
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
    cout << "\nPress any key to continue...";
    cin.ignore();

#endif
}

class Texts
{
public:
    string horizontalLine = "---+---+---\n";    // horizontal line in the board
    string invalidMove = "Invalid Move\n";      // invalid move
    string instruction = "Enter a number from 1 to 9: \n OR \nPress 'q' to quit\n";
    string win = "You Win!\n";                  // win message
    string lose = "You Lose!\n";                // lose message
    string title = "\n\n----- Tie Game! -----\n";
    string thanks = "Thanks for playing!\n";
};

class Game
{
public:
    char chars[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char u;
    int comp;
    bool win = false;
    Texts texts;

    void PrintBoard()
    {
        for (int i = 1; i <= 10; i++)
        {
            cout << " " << chars[i] << " ";
            if (i % 3 == 0)
            {
                cout << endl << texts.horizontalLine;
            }
            else
            {
                cout << "|";
            }
        }
    }

    void getUserMove()
    {
        cout << texts.instruction;
        cout << ">>";
        cin >> u;
        cin.ignore();

        
        if (u >= '1' && u <= '9')
        {
            int i = u - '0';
            if (chars[i] == u)
            {
                chars[i] = 'X';
            }
            else
            {
                cout << texts.invalidMove;
                Pause();
            }
        }

        else if (u == 'q')
        {
            cout << "Quitting...\n";
        }
        else
        {
            cout << texts.invalidMove;
            Pause();
        }
    }

    void ChooseRandom()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(1, 9);
        comp = distribution(gen);
    }

    void ComputerMove()
    {
        ChooseRandom();
        if (comp >= 1 && comp <= 9)
        {
            if (chars[comp] == '0' + comp)
            {
                chars[comp] = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else
        {
            ComputerMove();
        }
    }

    void WinCheck()
    {
        if (chars[1] == 'X' && chars[2] == 'X' && chars[3] == 'X')
        {
            PlayerWin();
        }
        else if (chars[4] == 'X' && chars[5] == 'X' && chars[6] == 'X')
        {
            PlayerWin();
        }
        else if (chars[7] == 'X' && chars[8] == 'X' && chars[9] == 'X')
        {
            PlayerWin();
        }
        else if (chars[1] == 'X' && chars[4] == 'X' && chars[7] == 'X')
        {
            PlayerWin();
        }
        else if (chars[2] == 'X' && chars[5] == 'X' && chars[8] == 'X')
        {
            PlayerWin();
        }
        else if (chars[3] == 'X' && chars[6] == 'X' && chars[9] == 'X')
        {
            PlayerWin();
        }
        else if (chars[1] == 'X' && chars[5] == 'X' && chars[9] == 'X')
        {
            PlayerWin();
        }
        else if (chars[3] == 'X' && chars[5] == 'X' && chars[7] == 'X')
        {
            PlayerWin();
        }
        else if (chars[1] == 'O' && chars[2] == 'O' && chars[3] == 'O')
        {
            PlayerLose();
        }
        else if (chars[4] == 'O' && chars[5] == 'O' && chars[6] == 'O')
        {
            PlayerLose();
        }
        else if (chars[7] == 'O' && chars[8] == 'O' && chars[9] == 'O')
        {
            PlayerLose();
        }
        else if (chars[1] == 'O' && chars[4] == 'O' && chars[7] == 'O')
        {
            PlayerLose();
        }
        else if (chars[2] == 'O' && chars[5] == 'O' && chars[8] == 'O')
        {
            PlayerLose();
        }
        else if (chars[3] == 'O' && chars[6] == 'O' && chars[9] == 'O')
        {
            PlayerLose();
        }
        else if (chars[1] == 'O' && chars[5] == 'O' && chars[9] == 'O')
        {
            PlayerLose();
        }
        else if (chars[3] == 'O' && chars[5] == 'O' && chars[7] == 'O')
        {
            PlayerLose();
        }
        else
        {
            win = false;
        }
    }

    void PlayerWin()
    {
        cout << texts.win;
        Pause();
        win = true;
    }

    void PlayerLose()
    {
        cout << texts.lose;
        Pause();
        win = false;
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
    Texts texts;

    game.PrintBoard();
    do
    {
        game.getUserMove();
        for (int i = 1; i <= 9; i++)
        {
            if (game.chars[i] == i)
            {
                break;
            }
            else if (i == 9)
            {
                ClearScreen();
                game.PrintBoard();
                cout << texts.title;
                break;
            }
        }

        game.ComputerMove();
        ClearScreen();
        game.PrintBoard();
        game.WinCheck();
        if (game.win == true)
        {
            game.u = 'q';
        }
    } while (game.u != 'q');

    cout << texts.thanks;

    return 0;
}
