// In-class assignment: enums and structs
// Name:

#include <iostream>
#include <string>

using namespace std;

const int GREEN_TIME = 5;
const int YELLOW_TIME = 2;

// ---------------------------------------------------------------- Part 1: the LightColor enum

// TODO: define an enum called LightColor with the values
//       GREEN, YELLOW, RED, and FLASHING_RED


// TODO: return "green", "yellow", "red", or "flashing red"
string colorName(LightColor color) {
    return "";
}

// TODO: return the color that comes after this one
//       (GREEN -> YELLOW -> RED -> GREEN). What should FLASHING_RED do?
LightColor nextColor(LightColor color) {
    return color;
}

// TODO: change the color passed in to the next color.
//       Hint: you've already written something that can help!
void advance(LightColor &color) {
}

// ---------------------------------------------------------------- Part 2: the Intersection struct

// TODO: define a struct called Intersection with three variables:
//       northSouth (a LightColor), eastWest (a LightColor),
//       and secondsRemaining (an int)


// TODO: print one line describing the intersection, like:
//       north-south: green, east-west: red (5 seconds left)
void printIntersection(const Intersection &intersection) {
}

// TODO: return true if at least one direction is stopped
//       (its light is RED or FLASHING_RED)
bool isSafe(const Intersection &intersection) {
    return true;
}

// TODO: count down one second. When the time runs out, change the lights
//       (see the handout for the exact rules) and reset the timer.
void tick(Intersection &intersection) {
}

// ---------------------------------------------------------------- main
// Don't change main(): if your functions are right, it prints what the handout shows.
// (Until you've finished Part 1, main() won't compile, and that's expected!)

int main() {
    // Part 1 tests
    LightColor light = GREEN;
    for (int i = 0; i < 4; i++) {
        cout << colorName(light) << endl;
        advance(light);
    }
    LightColor broken = FLASHING_RED;
    advance(broken);
    cout << "broken light after advancing: " << colorName(broken) << endl;
    cout << endl;

    // Part 2 tests
    Intersection mainAndFirst;
    mainAndFirst.northSouth = GREEN;
    mainAndFirst.eastWest = RED;
    mainAndFirst.secondsRemaining = GREEN_TIME;

    for (int second = 0; second < 16; second++) {
        printIntersection(mainAndFirst);
        if (!isSafe(mainAndFirst)) {
            cout << "CRASH! Both directions can go!" << endl;
        }
        tick(mainAndFirst);
    }

    return 0;
}
