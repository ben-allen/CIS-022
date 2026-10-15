// Assignment: from struct to class
// Name:

#include <iostream>
#include <string>

using namespace std;

const int GREEN_TIME = 5;
const int YELLOW_TIME = 2;

// ---------------------------------------------------------------- Part 1: carry over from stoplights

// TODO: paste in your LightColor enum and your colorName(), nextColor(),
//       and advance() functions from the stoplights assignment.


// ---------------------------------------------------------------- Part 2: the Intersection class

// TODO: define a class called Intersection. It has the same three variables
//       as your struct, plus three member functions: print(), isSafe(), and tick().


// TODO: define Intersection::print()


// TODO: define Intersection::isSafe()


// TODO: define Intersection::tick()


// ---------------------------------------------------------------- main
// Don't change main(): if your class is right, it prints what the handout shows.
// (Until you've finished Part 2, main() won't compile, and that's expected!)

int main() {
    Intersection mainAndFirst;
    mainAndFirst.northSouth = GREEN;
    mainAndFirst.eastWest = RED;
    mainAndFirst.secondsRemaining = GREEN_TIME;

    for (int second = 0; second < 16; second++) {
        mainAndFirst.print();
        if (!mainAndFirst.isSafe()) {
            cout << "CRASH! Both directions can go!" << endl;
        }
        mainAndFirst.tick();
    }
    cout << endl;

    Intersection oakAndThird;
    oakAndThird.northSouth = RED;
    oakAndThird.eastWest = GREEN;
    oakAndThird.secondsRemaining = 2;

    for (int second = 0; second < 4; second++) {
        oakAndThird.print();
        if (!oakAndThird.isSafe()) {
            cout << "CRASH! Both directions can go!" << endl;
        }
        oakAndThird.tick();
    }
    cout << endl;

    cout << "main and first, which didn't tick during that loop:" << endl;
    mainAndFirst.print();

    return 0;
}
