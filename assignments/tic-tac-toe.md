# Assignment: Tic-Tac-Toe

**Due:** [DATE]  
**Estimated time:** 2–3 hours

## Overview

In this assignment you'll build a two-player tic-tac-toe game that runs in the terminal. Two people take turns at the same keyboard, and the program tracks the board, rejects bad moves, and announces the winner or a draw.

You'll get practice with:

- two-dimensional arrays
- passing arrays to functions
- loops and conditionals
- breaking a program into small functions that each do one job

## What you're given

Download `tictactoe_starter.cpp`. It contains:

- **Function prototypes** for every function you'll write
- **`main()`**, already written, which runs the game by calling your functions
- **`read_int()`**, a helper that reads a number from the user and handles non-numeric input for you
- **Empty function stubs** marked `TODO`, each with a comment describing exactly what it must do

Your job is to fill in the `TODO` functions so the game works.

## Rules

1. **Do not change any function prototype, `main()`, or `read_int()`.** Your functions must work with the code exactly as given. Submissions that don't compile with the original `main()` will lose significant points.
2. **No global variables.** The board lives in `main()` and gets passed to your functions.
3. You may write additional helper functions if you want to, as long as the required ones work as described.

## How the board works

The board is a `char board[3][3]`. Each cell holds `'X'`, `'O'`, or `' '` (a space, meaning empty).

Players choose a cell by number:

```
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

Cell number `n` is stored at `board[(n - 1) / 3][(n - 1) % 3]`. Work through a few examples on paper to convince yourself this is right before you start coding.

## Functions to write

| Function | What it does |
|---|---|
| `init_board` | Sets every cell to `' '` |
| `print_board` | Prints the board, showing `X`/`O` in filled cells and the cell number in empty cells |
| `is_valid_move` | Returns `true` if the cell is 1–9 **and** empty |
| `get_move` | Asks the player for a cell until they enter a valid one, then returns it. Tell them *why* a move was rejected. |
| `place_mark` | Puts the player's mark in the given cell |
| `check_winner` | Checks all 8 winning lines. Returns `'X'`, `'O'`, or `' '` if no one has won |
| `is_board_full` | Returns `true` if there are no empty cells |
| `switch_player` | Returns `'O'` for `'X'` and `'X'` for `'O'` |

See the comments in the starter file for more detail on each one.

**Suggested order:** Start with `init_board`, `print_board`, and `switch_player`, and get the board displaying. Then do `is_valid_move`, `get_move`, and `place_mark` so you can play. Finish with `is_board_full` and `check_winner`. Compile and run after each function. Don't write everything at once.

## Sample run

Your wording doesn't have to match exactly, but your program should behave like this:

```
Welcome to Tic-Tac-Toe!

  1 | 2 | 3
 ---+---+---
  4 | 5 | 6
 ---+---+---
  7 | 8 | 9

Player X, choose a cell (1-9): 5

  1 | 2 | 3
 ---+---+---
  4 | X | 6
 ---+---+---
  7 | 8 | 9

Player O, choose a cell (1-9): 5
That cell is taken. Choose another: 12
That's not a cell. Choose 1-9: 1

  O | 2 | 3
 ---+---+---
  4 | X | 6
 ---+---+---
  7 | 8 | 9

Player X, choose a cell (1-9):
...
Player X wins!
```

## Test your program

Before submitting, make sure each of these works:

- [ ] X wins with a row
- [ ] O wins with a column
- [ ] Someone wins with each diagonal
- [ ] A game ends in a draw
- [ ] A player wins on the very last move (this should be a win, **not** a draw)
- [ ] Choosing a taken cell is rejected
- [ ] Choosing 0, 10, or a negative number is rejected
- [ ] Typing a letter instead of a number doesn't crash the program

**Tip:** You don't have to type every game by hand. Put the moves in a text file, one per line, and run `./tictactoe < moves.txt`.

## Extra credit (optional)

Submit extra credit in a **separate file** named `tictactoe_extra.cpp`. In that file only, you may modify `main()`. Your required submission must still use the original `main()`.

- **Play again (+5):** After a game ends, ask whether the players want to play again, and keep a running score of X wins, O wins, and draws.
- **Computer opponent (+5):** Let one player be the computer, which picks a random empty cell.
- **Smarter computer (+5 more):** The computer takes a winning move if it has one, blocks the other player's winning move if it doesn't, and otherwise picks randomly.

## Grading

| Category | Points |
|---|---|
| Correctness: moves, wins (all 8 lines), and draws all work | 50 |
| Input validation: out-of-range and taken cells handled with clear messages | 20 |
| Follows the rules: unchanged prototypes and `main()`, no globals | 20 |
| Readability: clear names, consistent indentation, comments where helpful | 10 |
| **Total** | **100** |

## Submission

Submit `tictactoe.cpp` [and optionally `tictactoe_extra.cpp`] to [LOCATION] by [DATE].
