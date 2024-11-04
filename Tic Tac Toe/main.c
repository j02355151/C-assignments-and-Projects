
#include <stdio.h>
#include <stdlib.h>
#define CHAR_X 'X'
#define CHAR_O 'O'
#define CHAR_S ' '

char board[9]; // array of char to represent game board

// initializes board to start new game
void initializeBoard()
{
    for (int i = 0; i < 9; i++)
        {
            board[i] = CHAR_S;
        }
}

// print the board
void printBoard()
{
// print board in 3x3 matrix
    for (int i = 1; i < 10; i++)
        {
            if (board[i - 1] == CHAR_S)
            {
                printf("%d ", i);
            }
            else
            {
                printf("%c ", board[i - 1]);
            }
            if (i % 3 == 0)
            {
                printf("\n");
            }
        }
}

int hasSpace()
{
// check board if any space left
    for (int i = 0; i < 9; i++)
        {
            if (board[i] == CHAR_S)
            {
                return 1;
            }
        }
// no empty space found
    return 0;
}

int isValid(int position)
{
// check for valid index
    if (position < 1 || position > 9)
        {
            return 0;
        }
    else
    {
// check for empty space in board
    if (board[position - 1] == CHAR_S)
        {
            return 1;
        }
// position is alreaddy filled
    return 0;
    }
}

int isFinished()
{
// look for horizontal lines
    if ((board[0] == board[1]) && (board[1] == board[2]) && (board[0] != CHAR_S))
    {
        return 1;
    }
    if ((board[3] == board[4]) && (board[4] == board[5]) && (board[3] != CHAR_S))
    {
        return 1;
    }
    if ((board[6] == board[7]) && (board[7] == board[8]) && (board[6] != CHAR_S))
    {
        return 1;
    }
// look for vertical lines
    if ((board[0] == board[3]) && (board[3] == board[6]) && (board[0] != CHAR_S))
    {
        return 1;
    }
    if ((board[1] == board[4]) && (board[4] == board[7]) && (board[1] != CHAR_S))
    {
        return 1;
    }
    if ((board[2] == board[5]) && (board[5] == board[8]) && (board[2] != CHAR_S))
    {
        return 1;
    }
// check for diagonal lines
    if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] != CHAR_S))
    {
        return 1;
    }
    if ((board[6] == board[4]) && (board[4] == board[2]) && (board[6] != CHAR_S))
    {
        return 1;
    }
    return 0;
}

void play_game(char Player)
{
// initialize board to play new game
    initializeBoard();
    int place = 0;
    while (1)
        {
// print player turn
            printf("Player: %c\n", Player);
// print board
            printBoard();
// ask player to make move
            printf("Select place: ");
            scanf("%d", &place);
// check for valid place
            if (isValid(place))
                {
// place mark on board
                    board[place - 1] = Player;
// check winner
                    if (isFinished())
                        {
                            printBoard();
// declare current player winner
                            printf("Player: %c won!\n", Player);
                            break;
                        }
// check for draw
                    if (!hasSpace())
                        {
                            printBoard();
// game is Tie
                            printf("Game is Tie!");
                            break;
                        }
// change player turn
                    if (Player == CHAR_X)
                        {
                            Player = CHAR_O;
                        }
                    else
                    {
                        Player = CHAR_X;
                    }
                }
                else
                    {
                        printf("Invalid position. Try again.\n");
                    }
        }

}


// main function to run program
int main()
{
// current player turn
    char Player = CHAR_X;
// continue playing till user select quit
    while (1)
        {
// randomly select first player
            if (rand() % 2 == 0)
                {
                    Player = CHAR_X;
                }
        else
            {
                Player = CHAR_O;
            }
// play the game till its over
        play_game(Player);
// ask user if they want to play again
        printf("\nDo you want to play Again?\n1. Yes\n2. No\n");
// get user iinput and let them play again if they want
        int option = 0;
        scanf("%d", &option);
        if (option != 1)
            {
                break;
            }
        }
}
