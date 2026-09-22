// =============================================================
//  Tic-Tac-Toe  -  Starter Code
//
//  Your job: implement every function marked TODO.
//  Do NOT change any function prototype, readInt(), or main().
//  Your functions must work with main() exactly as written.
//
//  Board cells are numbered like this:
//       1 | 2 | 3
//      ---+---+---
//       4 | 5 | 6
//      ---+---+---
//       7 | 8 | 9
//
//  Cell n is stored at board[(n - 1) / 3][(n - 1) % 3].
//  Each board element holds 'X', 'O', or ' ' (a space = empty).
// =============================================================

#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;


// ----- Constants (please use consistently) -----
const int ROWS = 3;
const int COLUMNS = 3;

// ----- Function prototypes (do not change) -----
void initBoard(char board[][COLUMNS]);
void printBoard(const char board[][COLUMNS]);
int  readInt();                                        // provided
bool isValidMove(const char board[][COLUMNS], int cell);
int  getMove(const char board[][COLUMNS], char player);
void placeMark(char board[][COLUMNS], int cell, char player);
char checkWinner(const char board[][COLUMNS]);
bool isBoardFull(const char board[][COLUMNS]);
char switchPlayer(char player);

// ----- main (do not change) -----
int main()
{
    char board[ROWS][COLUMNS];
    char player = 'X';
    char winner = ' ';

    initBoard(board);
    cout << "Welcome to Tic-Tac-Toe!\n";

    while (winner == ' ' && !isBoardFull(board))
    {
        printBoard(board);
        int cell = getMove(board, player);
        placeMark(board, cell, player);
        winner = checkWinner(board);
        player = switchPlayer(player);
    }

    printBoard(board);
    if (winner != ' ')
        cout << "Player " << winner << " wins!\n";
    else
        cout << "It's a draw!\n";

    return 0;
}

// ----- Provided helper (do not change) -----
// Reads an integer from the user. If they type something that
// isn't a number, it clears the error and asks again.
int readInt()
{
    int value;
    while (!(cin >> value))
    {
        if (cin.eof())          // input ended (e.g. Ctrl-D, or end of a test file)
        {
            cout << "\nInput ended. Goodbye!\n";
            exit(0);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number: ";
    }
    return value;
}

// =============================================================
//  YOUR CODE BELOW
// =============================================================

// Set every cell of the board to ' ' (empty).
void initBoard(char board[][COLUMNS])
{
    // TODO
}

// Print the board. Show 'X' or 'O' in filled cells and the
// cell's NUMBER (1-9) in empty cells, so players can see
// which numbers are still available. Example:
//
//       X | 2 | 3
//      ---+---+---
//       4 | O | 6
//      ---+---+---
//       7 | 8 | X
void printBoard(const char board[][COLUMNS])
{
    // TODO
}

// Return true if cell is between 1 and 9 AND that cell is empty.
// Otherwise return false.
bool isValidMove(const char board[][COLUMNS], int cell)
{
    // TODO
    return false;
}

// Prompt the given player for a cell number (use readInt()).
// Keep asking until they enter a valid move, then return it.
// Tell the player WHY a move was rejected (out of range vs. taken).
int getMove(const char board[][COLUMNS], char player)
{
    // TODO
    return 1;
}

// Put the player's mark ('X' or 'O') in the given cell (1-9).
// You may assume the move has already been validated.
void placeMark(char board[][COLUMNS], int cell, char player)
{
    // TODO
}

// Check all 8 ways to win: 3 rows, 3 columns, 2 diagonals.
// Return 'X' or 'O' if that player has three in a row.
// Return ' ' if nobody has won yet.
char checkWinner(const char board[][COLUMNS])
{
    // TODO
    return ' ';
}

// Return true if there are no empty cells left.
bool isBoardFull(const char board[][COLUMNS])
{
    // TODO
    return true;
}

// Return 'O' if player is 'X', and 'X' if player is 'O'.
char switchPlayer(char player)
{
    // TODO
    return player;
}
