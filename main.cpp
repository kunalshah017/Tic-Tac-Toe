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

class Game
{
public:
    char char1 = '1', char2 = '2', char3 = '3', char4 = '4', char5 = '5', char6 = '6', char7 = '7', char8 = '8', char9 = '9';
    char u;
    int comp;
    bool win = false;

    void PrintBoard()
    {
        cout << " " << char1 << " | " << char2 << " | " << char3 << " \n";
        cout << "---+---+---\n";
        cout << " " << char4 << " | " << char5 << " | " << char6 << " \n";
        cout << "---+---+---\n";
        cout << " " << char7 << " | " << char8 << " | " << char9 << " \n";
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
        if (comp == 1)
        {
            if (char1 == '1')
            {
                char1 = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else if (comp == 2)
        {
            if (char2 == '2')
            {
                char2 = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else if (comp == 3)
        {
            if (char3 == '3')
            {
                char3 = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else if (comp == 4)
        {
            if (char4 == '4')
            {
                char4 = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else if (comp == 5)
        {
            if (char5 == '5')
            {
                char5 = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else if (comp == 6)
        {
            if (char6 == '6')
            {
                char6 = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else if (comp == 7)
        {
            if (char7 == '7')
            {
                char7 = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else if (comp == 8)
        {
            if (char8 == '8')
            {
                char8 = 'O';
            }
            else
            {
                ComputerMove();
            }
        }
        else if (comp == 9)
        {
            if (char9 == '9')
            {
                char9 = 'O';
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
        if (char1 == 'X' && char2 == 'X' && char3 == 'X')
        {
            cout << "You Win!\n";
            Pause();
            win = true;
        }
        else if (char4 == 'X' && char5 == 'X' && char6 == 'X')
        {
            cout << "You Win!\n";
            Pause();
            win = true;
        }
        else if (char7 == 'X' && char8 == 'X' && char9 == 'X')
        {
            cout << "You Win!\n";
            Pause();
            win = true;
        }
        else if (char1 == 'X' && char4 == 'X' && char7 == 'X')
        {
            cout << "You Win!\n";
            Pause();
            win = true;
        }
        else if (char2 == 'X' && char5 == 'X' && char8 == 'X')
        {
            cout << "You Win!\n";
            Pause();
            win = true;
        }
        else if (char3 == 'X' && char6 == 'X' && char9 == 'X')
        {
            cout << "You Win!\n";
            Pause();
            win = true;
        }
        else if (char1 == 'X' && char5 == 'X' && char9 == 'X')
        {
            cout << "You Win!\n";
            Pause();
            win = true;
        }
        else if (char3 == 'X' && char5 == 'X' && char7 == 'X')
        {
            cout << "You Win!\n";
            Pause();
            win = true;
        }
        else if (char1 == 'O' && char2 == 'O' && char3 == 'O')
        {
            cout << "You Lose!\n";
            Pause();
            win = true;
        }
        else if (char4 == 'O' && char5 == 'O' && char6 == 'O')
        {
            cout << "You Lose!\n";
            Pause();
            win = true;
        }
        else if (char7 == 'O' && char8 == 'O' && char9 == 'O')
        {
            cout << "You Lose!\n";
            Pause();
            win = true;
        }
        else if (char1 == 'O' && char4 == 'O' && char7 == 'O')
        {
            cout << "You Lose!\n";
            Pause();
            win = true;
        }
        else if (char2 == 'O' && char5 == 'O' && char8 == 'O')
        {
            cout << "You Lose!\n";
            Pause();
            win = true;
        }
        else if (char3 == 'O' && char6 == 'O' && char9 == 'O')
        {
            cout << "You Lose!\n";
            Pause();
            win = true;
        }
        else if (char1 == 'O' && char5 == 'O' && char9 == 'O')
        {
            cout << "You Lose!\n";
            Pause();
            win = true;
        }
        else if (char3 == 'O' && char5 == 'O' && char7 == 'O')
        {
            cout << "You Lose!\n";
            Pause();
            win = true;
        }
        else
        {
            win = false;
        }
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
        if (game.char1 != '1' && game.char2 != '2' && game.char3 != '3' && game.char4 != '4' && game.char5 != '5' && game.char6 != '6' && game.char7 != '7' && game.char8 != '8' && game.char9 != '9')
        {
            ClearScreen();
            game.PrintBoard();
            cout << "\n\n----- Tie Game! -----\n";
            break;
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

    cout << "Thanks for playing!\n";

    return 0;
}
