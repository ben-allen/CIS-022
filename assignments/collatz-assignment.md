# Assignment: The 3n + 1 Problem



## Background

Pick any positive integer. Then repeat the following rule:

- If the number is **even**, divide it by 2.
- If the number is **odd**, multiply it by 3 and add 1.

Starting from 6, you get:

```
6  3  10  5  16  8  4  2  1
```

Once a sequence reaches 1 it would cycle forever (1, 4, 2, 1, 4, 2, ...), so we stop as soon as we hit 1.

Every starting value anyone has ever tested eventually reaches 1. Nobody has been able to prove that this always happens. That open question is called the **Collatz conjecture**, and it has been unsolved since 1937. Your program will not settle it, but it will let you poke at it.

Throughout this assignment, the **length** of a sequence means the number of values printed, counting both the starting value and the final 1. The sequence above has length 9.

The sequence that results from running this algorithm is sometimes called the "hailstone sequence", because while hailstones form in the clouds they descend and ascend unpredictably before they finally fall. 

## What to write

Your program has two parts, both run from `main`.

### Part 1 — One sequence

Prompt the user for a positive starting value. If the user enters zero or a negative number, print an error and prompt again until the input is valid. Don't worry about handling situations where the user types something other than a whole number.

(i.e. don't worry about what happens if they type a non-numeric string, or a number with a decimal point)

Then print the full sequence on one line, followed by its length.

### Part 2 — The search

Without asking the user for anything further, examine every starting value from 1 up to 9999 and determine which one produces the **longest** sequence. Print that starting value and its length.

If two starting values tie, report the smaller one.

## Required functions

`main` must be short. Write at least these three functions and call them:

| Function | Purpose |
|---|---|
| `long long collatzNext(long long n)` | Returns the next value after `n`. This is the only place the 3n + 1 rule appears. |
| `int collatzLength(long long n)` | Returns the length of the sequence starting at `n`, without printing anything. |
| `void printCollatzSequence(long long n)` | Prints the sequence starting at `n`. |

Note that `collatzLength` and `printCollatzSequence` should both call `collatzNext` rather than repeating the rule themselves. If you later discover abug in the rule, you want exactly one place to fix it.

You do **not** need arrays for this assignment. Nothing needs to be stored.

## Sample runs

User input is shown in **bold**.

```
Enter a positive starting value: -4
Value must be positive. Try again: 0
Value must be positive. Try again: 6
Sequence: 6 3 10 5 16 8 4 2 1
Length:   9 terms

Longest sequence starting below 10000:
  Starting value: 6171
  Length:         262 terms
```

A second run, to check a harder case:

```
Enter a positive starting value: 27
Sequence: 27 82 41 124 62 31 94 47 142 71 214 107 322 161 484 242 121 364 182 91 274 137 412 206 103 310 155 466 233 700 350 175 526 263 790 395 1186 593 1780 890 445 1336 668 334 167 502 251 754 377 1132 566 283 850 425 1276 638 319 958 479 1438 719 2158 1079 3238 1619 4858 2429 7288 3644 1822 911 2734 1367 4102 2051 6154 3077 9232 4616 2308 1154 577 1732 866 433 1300 650 325 976 488 244 122 61 184 92 46 23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 1
Length:   112 terms
```

(The sequence for 27 is shown wrapped here to fit on the page. Your program should print it on a single line.)

Two useful values to check yourself against: starting at 1 gives a length of 1, and starting at 2 gives a length of 2.

## Why `long long`

The starting values are small, but the sequences are not. Starting from 9663, the sequence climbs above 27 million before it comes back down. That still fits in an `int`, but it is closer to the limit than you might expect from a four-digit starting value, and it costs you nothing to use `long long` instead.
This is worth remembering: the size of the input does not always predict the size of the intermediate values.

## Extensions

Optional, if you finish early.

1. Report the largest value reached anywhere during the search, along with the starting value that produced it.
2. Part 2 recomputes work constantly. The sequence from 6171 passes through hundreds of smaller numbers whose lengths you have already computed. Time your program, then estimate how much faster it could be if you remembered previous answers. You do not have to implement that yet, but describe in a
   comment how you would.
3. Print a table of the record-setters: every starting value that produces a longer sequence than all values before it. There are fewer than you would guess.

A note on types:

## int, long, and long long

All three hold whole numbers. They differ in how many bits they get, which decides how large a value they can hold before overflowing.

C++ does not fix these sizes. The standard only sets a **minimum** for each, and the compiler may give you more. Here is what you actually get on the compilers you will use in this class:

| Type | Guaranteed at least | Typical size | Typical range |
|---|---|---|---|
| `int` | 16 bits | 32 bits | −2,147,483,648 to 2,147,483,647 |
| `long` | 32 bits | 32 or **64** bits | depends on the platform |
| `long long` | 64 bits | 64 bits | about ±9.2 quintillion |

The one to be careful with is `long`. On 64-bit Linux and macOS it is 64 bits, but on Windows it is only 32 bits — the same as `int`. Code that relies on `long` being big will work on one machine and silently overflow on another. For that reason, prefer `int` when the values are small and `long long` when they might not be. There is rarely a good reason to reach for plain `long`.

Overflow does not produce an error. The value simply wraps around to a negative number and your program keeps running with garbage, which is why it is worththinking about range *before* you have a bug.

To check the sizes on your own machine:

```cpp
#include <iostream>
#include <climits>

using namespace std;

int main() {
    cout << sizeof(int) << " bytes, max " << INT_MAX << endl;
    cout << sizeof(long) << " bytes, max " << LONG_MAX << endl;
    cout << sizeof(long long) << " bytes, max " << LLONG_MAX << endl;
    return 0;
}
```

`sizeof` reports **bytes**, so multiply by 8 for bits.