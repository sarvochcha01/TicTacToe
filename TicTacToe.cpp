#include <iostream>
#include <stdlib.h>
#include <array>

using board = std::array<char, 9>;
bool isGameOver = false;

void DrawBoard(board& grid)
{
    std::cout << "   " << '|' << "   " << '|' << "   " << '\n';
    std::cout << " "<< grid[0] <<" " << '|' << " " << grid[1] << " " << '|' << " " << grid[2] << '\n';
    std::cout << "___" << '|' << "___" << '|' << "___" << '\n';
    std::cout << "   " << '|' << "   " << '|' << "   " << '\n';
    std::cout << " " << grid[3] << " " << '|' << " " << grid[4] << " " << '|' << " " << grid[5] << '\n';
    std::cout << "___" << '|' << "___" << '|' << "___" << '\n';
    std::cout << "   " << '|' << "   " << '|' << "   " << '\n';
    std::cout << " " << grid[6] << " " << '|' << " " << grid[7] << " " << '|' << " " << grid[8] << '\n';
    std::cout << "   " << '|' << "   " << '|' << "   " << '\n';
}

int getUserInput(board& b)
{
    int temp{};

    do
    {
        std::cin >> temp;
    } while ((temp > 9) || (b[temp - 1] == 'X' || b[temp - 1] == 'O'));

    return temp;
}

std::string getPlayerName()
{
    std::string temp{};
    std::cin >> temp;
    return temp;
}

int checkWinner(board& b)
{
    for (int i = 0; i < 3; i++)
    {
        if (b[i] == 'X' && b[i+3] == 'X' && b[i+6] == 'X')
        {
            isGameOver = true;
            return 1;
        }
        else if (b[i] == 'X' && b[i + 1] == 'X' && b[i + 2] == 'X')
        {
            isGameOver = true;
            return 1;
        }
        else if (b[0] == 'X' && b[4] == 'X' && b[8] == 'X')
        {
            isGameOver = true;
            return 1;
        }
        else if (b[2] == 'X' && b[4] == 'X' && b[6] == 'X')
        {
            isGameOver = true;
            return 1;
        }
        else if (b[i] == 'O' && b[i + 3] == 'O' && b[i + 6] == 'O')
        {
            isGameOver = true;
            return 0;
        }
        else if (b[i] == 'O' && b[i + 1] == 'O' && b[i + 2] == 'O')
        {
            isGameOver = true;
            return 0;
        }
        else if (b[0] == 'O' && b[4] == 'O' && b[8] == 'O')
        {
            isGameOver = true;
            return 0;
        }
        else if (b[2] == 'O' && b[4] == 'O' && b[6] == 'O')
        {
            isGameOver = true;
            return 0;
        }
    }
}

int main()
{
    board b{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    std::cout << "Enter player one name: ";
    std::string player1{ getPlayerName() };
    system("CLS");
    std::cout << "Enter player two name: ";
    std::string player2{ getPlayerName() };
    system("CLS");

    bool isPlayerOneTurn = true;

    while (!isGameOver)
    {
        DrawBoard(b);

        if (isPlayerOneTurn)
        {
            std::cout << player1 << "'s turn: ";
            int i = getUserInput(b);
            b[i - 1] = 'X';
            isPlayerOneTurn = !isPlayerOneTurn;
            checkWinner(b);
        }
        else
        {
            std::cout << player2 << "'s turn: ";
            int i = getUserInput(b);
            b[i - 1] = 'O';
            isPlayerOneTurn = true; 
            checkWinner(b);
        }        
        system("CLS");
    }

    DrawBoard(b);

    if (checkWinner(b) == 1)
    {
        std::cout << player1 << " Wins!\n";
    }
    else if (checkWinner(b) == 0)
    {
        std::cout << player2 << " Wins!\n";
    }

    system("PAUSE");
}