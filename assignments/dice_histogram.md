## Overview

In this assignment you'll write a program that rolls two dice hundreds of times, keeps track of how often each total comes up, and prints the results as a bar chart made of stars. When you run it, you should see a clear pattern: some totals come up a lot more often than others.

You'll get practice with:

- generating random numbers with `rand()` and `srand()`
- getting a random number in a specific range
- using an array to count things
- passing arrays to functions


## What you're given

Download `dice_starter.cpp`. It contains:

- **Function prototypes** for every function you'll write
- **Empty function stubs** marked `TODO`, each with a comment describing exactly what it must do

There is no `main()` in the starter file. You'll write it yourself (see "Writing `main()`" below), and you'll fill in the `TODO` functions.

## Rules

1. **Do not change any function prototype.**
2. **No global variables.** The global *constants* `NUM_ROLLS` and `MAX_SUM` are fine to use.

## How the counts array works

The counts live in an array declared in `main()` as `int counts[MAX_SUM + 1] = {};`, which makes 13 slots, all starting at 0. The total of the two dice is used directly as the index, so `counts[7]` holds how many times you rolled a 7, `counts[12]` holds how many times you rolled a 12, and so on.

Two dice can only add up to 2 through 12, so `counts[0]` and `counts[1]` are never used. We waste two slots so that we never have to convert between a total and an index.

## Writing `main()`

Your `main()` must:

1. Seed the random number generator so that every run of the program gives different results.
2. Declare the counts array (see above).
3. Print the `Rolling two dice...` line, call `roll_dice` and `print_histogram`, and then print the `Total rolls` line using `total_rolls`.

Think carefully about where `srand` belongs and how many times it should be called. Look back at the "Random numbers" slides from the Minesweeper unit if you're not sure.

**When I grade your program, I will replace your seed with `srand(137)`.** Before you submit, do the same thing yourself:

1. Temporarily change your seed to `srand(137)`.
2. Run your program on [OnlineGDB](https://www.onlinegdb.com) (choose C++ as the language). Different computers can produce different random numbers from the same seed, so use OnlineGDB for this check even if you wrote your code somewhere else.
3. Compare your output with the sample run below. It should match exactly.
4. Change your seed back before you submit.

## Functions to write

| Function | What it does |
|---|---|
| `roll_die` | Returns a random whole number from 1 to 6 |
| `roll_dice` | Rolls two dice `num_rolls` times, adding 1 to `counts[sum]` after each roll |
| `total_rolls` | Returns the total of `counts[2]` through `counts[12]` |
| `print_histogram` | Prints one line per total from 2 to 12: the total, a colon, a space, one `*` per roll, a space, and the count in parentheses |

See the comments in the starter file for more detail on each one.

**Hint for `roll_die`:** In the Minesweeper slides, `rand() % ROWS + 1` was a *bug*, because rows start at 0. A die starts at 1, so think carefully about what range `rand() % 6` gives you and what you need to do to it.

**Hint for `print_histogram`:** To make the colons line up, print one extra space before the totals 2 through 9.

**Suggested order:** Write the seeding part of `main()` and `roll_die` first. Test them by temporarily putting a loop in `main()` that prints 20 rolls, and check that you see both 1s and 6s but never 0 or 7. Then write `roll_dice` and `total_rolls`, and check that the total comes out to 360. Finish with `print_histogram` and the rest of `main()`. Compile and run after each step.

## Sample run

Your program should look like this (PLEASE MATCH THE EXACT WORDING AND FORMATTING). This output came from `srand(137)` on OnlineGDB. Run with that seed there, and your counts should match these exactly.

```
Rolling two dice 360 times...

 2: ************ (12)
 3: ***************** (17)
 4: ***************************** (29)
 5: ********************************** (34)
 6: *********************************************************** (59)
 7: ************************************************************* (61)
 8: ********************************************** (46)
 9: ****************************************** (42)
10: ************************************* (37)
11: *************** (15)
12: ******** (8)

Total rolls: 360
```

## Test your program

Before submitting, make sure each of these works:

- [ ] With `srand(137)` on OnlineGDB, your output matches the sample run exactly
- [ ] `Total rolls` is exactly 360
- [ ] The colons line up for every total from 2 to 12
- [ ] With your real seed back in place, running the program twice, a few seconds apart, gives you different results
- [ ] Your submitted file does **not** still say `srand(137)`

## When the numbers look wrong

| What you see | Likely cause | Instead |
|---|---|---|
| 11 and 12 are always `(0)`, and the total is less than 360 | `roll_die` returns 0 to 5 | Add 1 to `rand() % 6` |
| Every run gives the same chart | The time isn't being used as the seed, or you left `srand(137)` in | Review the "A different seed every time" slide |
| All 360 rolls land on a single total | `srand` is called more than once | Review the "Random mistakes" slide |
| `srand(137)` on OnlineGDB gives different counts from the sample, but the total is 360 | Something extra is calling `rand()`, or the dice are rolled a different way | Each roll should call `roll_die()` exactly twice, and nothing else should call `rand()` |
| The total is right but the chart is missing a line | Your print loop stops at `< 12` | Use `<= MAX_SUM` |

## Extra credit (optional)

Submit extra credit in a **separate file** named `dice_extra.cpp`. In that file only, you may change the prototypes. Your required submission must still use the original prototypes. Note: I'm not going to be too picky with the wording and formatting of the extra credit components.

- **Three dice (+2):** Roll three dice instead of two. Think about how big the counts array needs to be now and which totals are possible.
- **Lottery picks (+3):** Pick 6 *different* random numbers from 1 to 49 and store them in an array. If you pick a number you already have, pick again (just like placing mines when a cell already has one). Print the 6 numbers.

## Submission

Submit `dice.cpp` [and optionally `dice_extra.cpp`].
