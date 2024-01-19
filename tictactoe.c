#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void PrintBoard();
bool PlaceLeft(); 
bool IsGameOver();

char board[3][3] = {{'.', '.', '.'},{'.', '.','.'},{'.','.','.'}};
char winner = '\0';

void main()
{
    bool gameOver = false;


    while (!gameOver)
    {
    int ur;
    printf("Enter Row: ");
    scanf("%d", &ur);
    getchar();
    int uc;
    printf("\nEnter Column: ");
    scanf("%d", &uc);
    board[ur-1][uc-1] = 'X';

    if (IsGameOver())
    {
        if (winner == 'X')
        {
            PrintBoard();
            printf("\nYou Won !\n\n");
        }
        else if (winner == 'O')
        {
            PrintBoard();
            printf("\nYou Lost\n\n");
        }
        break;
    }

    if (PlaceLeft() == false)
    {
        if (IsGameOver())
        {
            if (winner == 'X')
            {
                PrintBoard();
            printf("\nYou Won !\n\n");
            }
            else if (winner == 'O')
            {
                PrintBoard();
            printf("\nYou Lost\n\n");
            }
            break;
        }else if (IsGameOver()==false && PlaceLeft()==false)
        {
            PrintBoard();
            printf("\nGame Tied !\n\n");
        }
        break;
    }
    
    srand(time(NULL));
    bool unique = false;  
    int rr;
    int rc;
    while (!unique)
    {
        rr = rand() % 3;
        rc = rand() % 3;

        if (board[rr][rc] != '.')
        {
            continue;
        } 
         unique = true;
    }
    
    board[rr][rc] = 'O'; 
    PrintBoard();
    if (IsGameOver())
    {
        if (winner == 'X')
        {
            PrintBoard();
            printf("\nYou Won !\n\n");
        }
        else if (winner == 'O')
        {
            PrintBoard();
            printf("\nYou Lost\n\n");
        }
        break;
    }
    else if (PlaceLeft==false)
    {
        PrintBoard();
        printf("\nGame Tied !\n\n");
        break;
    }
    }
}

void PrintBoard()
{
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            printf("%c\t",board[i][j]);
        }
        printf("\n");
    }
}

bool PlaceLeft()
{
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j] == '.')
            {
                return true;
            }
        }
    }
    return false;
}

bool IsGameOver()
{
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '.' && board[0][1] != '.' && board[0][2] != '.')
        {
            winner = board[0][0];
            return true;

        }
        if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '.' && board[1][1] != '.' && board[1][2] != '.')
        {
           winner = board[1][0];
           return true; 

        }
        if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '.' && board[2][1] != '.' && board[2][2] != '.')
        {winner = board[2][0];
            return true;

        }




        if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '.' && board[1][0] != '.' && board[2][0] != '.')
        {winner = board[0][0];
            return true;

        }
        if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '.' && board[1][1] != '.' && board[2][1] != '.')
        {winner = board[0][1];
            return true;

        }
        if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '.' && board[1][2] != '.' && board[2][2] != '.')
        {winner = board[0][2];
            return true;

        }
        //




        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.' && board[1][1] != '.' && board[2][2] != '.')
        {winner = board[0][0];
            return true;

        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.' && board[1][1] != '.' && board[2][0] != '.')
        {winner = board[0][2];
            return true;

        }
        return false;
}
