//TIC-TAC-TOE
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include "findMove.cpp"
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
    const string horizontalLine = "---+---+---\n";    // horizontal line in the board
    const string invalidMove = "Invalid Move\n";      // invalid move
    const string instruction = "Enter a number from 1 to 9: \n OR \nPress 'q' to quit\n";
    const string win = "You Win!\n";                  // win message
    const string lose = "You Lose!\n";                // lose message
    const string tie = "\n\n----- Tie Game! -----\n"; // tie message
    const string thanks = "Thanks for playing!\n";
};

class Game
{
public:
    char chars[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};    // chars[0] is not used
    char u;
    int comp;
    float randomPos;    // for random move
    bool win = false;
    Texts texts;

    void ShowDifficultyMenu()
    {
        char difficulty;
        cout << "Choose difficulty:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cin >> difficulty;
        switch (difficulty)
        {
        case '1':
            randomPos = 0.7;
            break;
        case '2':
            randomPos = 0.4;
            break;
        case '3':
            randomPos = 0.1;
            break;
        default:
            cout << "Invalid input\n";
            ShowDifficultyMenu();
            break;
        }
    }

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
            int i = u - '0';    // char -> int  e.g. '5' - '0' = 5
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

    void ComputerMove()
    {
        comp = findBestMove(chars);
        if (comp >= 1 && comp <= 9)
        {
            if (chars[comp] == '0' + comp)  // int -> char  e.g. '0' + 5 = '5'
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
        for (int i=1; i<=3; i++)    // If wins vertically or horizontally
        {
            if (equals3(chars[i], chars[i+3], chars[i+6]) || equals3(chars[3*i-2], chars[3*i-1], chars[3*i]))   // first find if there's a winner
            {
                chars[i] == 'X' ? PlayerWin() : PlayerLose();   // then check if X or O wins
                return;
            }
        }
        if (equals3(chars[1], chars[5], chars[9]) || equals3(chars[3], chars[5], chars[7]))    // If wins diagonally
        {
            chars[5] == 'X' ? PlayerWin() : PlayerLose();
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

    bool equals3(char a, char b, char c)
    {
        return ((a == b) && (b == c));
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

    game.ShowDifficultyMenu();
    ClearScreen();

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
                cout << texts.tie;
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
