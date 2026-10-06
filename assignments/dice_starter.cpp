// CIS 022: Dice Histogram
// Write main() and fill in every function marked TODO. Do not change the prototypes.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_ROLLS = 360;
const int MAX_SUM = 12;   // the biggest sum two dice can make

int roll_die();
void roll_dice(int counts[], int num_rolls);
int total_rolls(int counts[]);
void print_histogram(int counts[]);

// TODO: Write main(). See the assignment for what it has to do.

// TODO: Return a random whole number from 1 to 6, like rolling one die.
// Use rand().
int roll_die() {
    return 0;
}

// TODO: Roll two dice num_rolls times. Each time, add the two dice together
// and add 1 to counts[sum]. Use roll_die().
void roll_dice(int counts[], int num_rolls) {
}

// TODO: Return the total of every count from counts[2] to counts[12].
// If everything works, this equals NUM_ROLLS.
int total_rolls(int counts[]) {
    return 0;
}

// TODO: Print one line for each sum from 2 to 12:
//   the sum, a colon, a space, one * per roll, a space, and the count in parentheses.
// Put an extra space before sums 2-9 so the colons line up:
//    7: ******************************************************************** (61)
//   10: ****************************** (30)
void print_histogram(int counts[]) {
}
