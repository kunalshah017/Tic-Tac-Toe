// TIC-TAC-TOE
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <random>
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
    const string blue = "\033[34m"; // Blue
    const string red = "\033[31m"; // Red
    const string cyan = "\033[36m"; // Cyan
    const string yellow = "\033[33m"; // Yellow
    const string green = "\033[32m"; // Green
    const string magenta = "\033[35m"; // Magenta
    const string reset = "\033[0m"; // White

    // Define your text
    const string horizontalLine = blue + "---+---+---" + reset + "\n"; // Horizontal Line (Decorator)
    const string invalidMove = red + "Invalid Move" + reset + "\n"; // Invalid Move (Message)
    const string invalidInput = red + "Invalid Input" + reset + "\n"; // Invalid Input (Message)
    const string instruction = cyan + "Enter a number from 1 to 9: \n OR \nPress 'q' to quit" + reset + "\n"; // Select a spot (Gameplay)
    const string difficultyMenu = yellow + "Choose difficulty:\n1. Easy\n2. Medium\n3. Hard" + reset + "\n"; // Choose a difficulty (Gameplay)
    const string win = green + "You Win!" + reset + "\n"; // Win Message (Message)
    const string lose = red + "You Lose!" + reset + "\n"; // Lose Message (Message)
    const string tie = "\n\n----- " + magenta + "Tie Game!" + reset + " -----\n"; // Tie Message (Message)
    const string quitting = yellow + "Quitting..." + reset + "\n"; // Quit Message (Message)
    const string thanks = cyan + "Thanks for playing!" + reset + "\n"; // Thanks for Playing (Message)
};

class Game
{
public:
    char chars[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // chars[0] is not used
    char u;
    int comp;
    float randomPos;    // for random move
    bool win = false;
    Texts texts;

    void ShowDifficultyMenu()
    {
        char difficulty;
        cout << texts.difficultyMenu;
        cin >> difficulty;
        switch (difficulty)
        {
        case '1':
            randomPos = 7;
            break;
        case '2':
            randomPos = 4;
            break;
        case '3':
            randomPos = 1;
            break;
        case 'q':
            cout << texts.quitting;
            exit(0);
            break;
            
        default:
            cout << texts.invalidInput;
            ShowDifficultyMenu();
            break;
        }
    }

    void PrintBoard()
    {
        for (int i = 1; i <= 9; i++)
        {
            cout << " " << chars[i] << " ";
            if (i % 3 == 0 && i != 9)
            {
                cout << endl
                     << texts.horizontalLine;
            }
            else
            {
                if (i != 9)
                {
                    cout << "|";
                }
            }
        }
    }

    void getUserMove()
    {
        cout << texts.instruction;
        bool validInput = false;
        do
        {
            cout << ">>";
            cin >> u;
            cin.ignore();

            if (u >= '1' && u <= '9')
            {
                int i = u - '0'; // char -> int  e.g. '5' - '0' = 5
                if (chars[i] == u)
                {
                    chars[i] = 'X';
                    validInput = true;
                }
                else
                {
                    cout << texts.invalidMove;
                    Pause();
                }
            }

            else if (u == 'q')
            {
                cout << texts.quitting;
                validInput = true;
            }
            else
            {
                cout << texts.invalidMove;
                Pause();
            }
        } while (!validInput);
    }

    int GetRandomInt(int min, int max)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(gen);
    }

    void ComputerMove()
    {   
        int randomNum = GetRandomInt(1, 10);
        do {
            if (randomNum <= randomPos) 
            {
                comp = GetRandomInt(1, 9);
            }
            else
            {
                comp = findBestMove(chars);
            }
        } while (chars[comp] != '0' + comp);    // int -> char  e.g. '0' + 5 = '5'
        chars[comp] = 'O';
    }

    void WinCheck()
    {
        for (int i = 1; i <= 3; i++) // If wins vertically or horizontally
        {
            if (equals3(chars[i], chars[i + 3], chars[i + 6]) || equals3(chars[3 * i - 2], chars[3 * i - 1], chars[3 * i])) // first find if there's a winner
            {
                chars[i] == 'X' ? PlayerWin() : PlayerLose(); // then check if X or O wins
                return;
            }
        }
        if (equals3(chars[1], chars[5], chars[9]) || equals3(chars[3], chars[5], chars[7])) // If wins diagonally
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
        exit(0);
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
            if (game.chars[i] == '0' + i)
            {
                break;
            }
            else if (i == 9)
            {
                ClearScreen();
                game.PrintBoard();
                cout << texts.tie;
                exit(0);
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
