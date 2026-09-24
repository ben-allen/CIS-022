// Minesweeper, part 1: the board and its numbers

#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLUMNS = 8;

int count_mines(bool mines[][COLUMNS]) {
    // TODO: return the number of cells in mines that are true
    return 0;
}

bool is_in_bounds(int row, int column) {
    // TODO: return true if (row, column) is on the board
    return false;
}

int count_adjacent_mines(bool mines[][COLUMNS], int row, int column) {
    // TODO: return how many of the 8 neighbors of (row, column) are mines
    return 0;
}

void compute_adjacent_counts(bool mines[][COLUMNS], int adjacent_counts[][COLUMNS]) {
    // TODO: fill adjacent_counts with the number for every cell
}

void print_debug_board(bool mines[][COLUMNS], int adjacent_counts[][COLUMNS]) {
    // TODO: print the whole board, * for mines and the number for everything else
}

int main() {
    bool mines[ROWS][COLUMNS] = {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0}
    };

    // Put the test code from the slides here, replacing any earlier test.

    return 0;
}
