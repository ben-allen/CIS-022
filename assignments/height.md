# CIS022 In-Class and Lab Assignment: Building a Height

## Overview

During today's class, I build `Clock` on the slides, and you build `Height` in your own file. Each time I show something on `Clock`, you do the same thing on `Height` by adapting my `Clock` code. That includes the operators and the `main()` that tests them.

Steps 1–8 below are the YOUR TURN slides from class. Step 9, storing total inches, starts at the end of class, and we'll spend time on it in lab. When it's done, you turn in the finished `height.cpp`.

By the end, your `Height` will work with:

- `==`, so `count` and `find` work on a vector of heights
- `<`, so `sort` works on a vector of heights
- `+`, so you can add two heights together

and it will store a height as one number, the total inches, instead of feet and inches.

---

## Starter code

Start from `height.cpp`, posted with today's slides. It has a `Height` class with a constructor, two getters, and `print`, and no operators yet:

```cpp
class Height {
public:
    Height(int feet, int inches) {
        this->feet = feet;
        this->inches = inches;
    }
    int getFeet() const {
        return feet;
    }
    int getInches() const {
        return inches;
    }
    void print() const {
        cout << feet << "'" << inches << "\"";
    }

private:
    int feet;
    int inches;
};
```

You can assume `inches` is always between 0 and 11 when a `Height` is made.

---

## In class: steps 1–8

These are the same as the YOUR TURN slides, in the same order. Each step adds to the same `main()`, so by step 8 your `main()` does all of them. Use the exact output wording shown, so you can compare your output with "Check your work" below.

1. **`isSameHeight`.** Write it the same way we wrote `isSameTime`: two heights are the same when the feet match and the inches match. In `main()`, make `finn` (5'4"), `jake` (5'4"), and `bmo` (1'10"). Test `finn` against `jake` and against `bmo`, and print `finn and jake match` or `finn and bmo match` when they match.
2. **`operator==`.** Rename `isSameHeight` to `operator==`, the way we renamed `isSameTime`. Change your two tests to use `==`. The output shouldn't change.
3. **An unnamed `Height`.** Compare `finn` with an unnamed `Height` set to 5'4", the way we compared `lunch` with `Clock(12, 0)`. If they match, print `finn is 5'4"`.
4. **`count`.** Make a `vector<Height>` called `roster` holding 6'2", 5'11", 5'4", 6'0", 1'10", and 5'4", in that order. Use `count` the way we counted meetings at 12:00: print how many people are 5'4", then how many are 7'0".
5. **`find`.** Use `find` on `roster` the way we found the 12:00 meeting. Look for someone 5'11" tall, and print `found at index` and the index, or `not found`. Then do the same for 7'0".
6. **`operator<`.** Add it the way we did for `Clock`: compare feet first, and only look at inches when the feet are the same. Test whether 5'11" < 6'2", and whether 6'2" < 5'11". When one is true, print it like `5'11" is shorter than 6'2"`.
7. **`sort`.** Sort `roster` the way we sorted meetings, and print each height on its own line.
8. **`operator+`.** `Height + Height` gives the total height. Inches roll over at 12, and a height doesn't wrap around the way a clock does. Print 5'8" + 0'7", then 2'6" + 3'6", each on its own line.

Each operator takes a `const Height&` and ends with `const`, the same way the `Clock` operators do.

When step 8 is done, check your output against "Check your work" below. Then **save a copy of this working version** (for example, `height_feet_inches.cpp`) before you start step 9, so you can go back to it if something breaks.

---

## In lab: step 9, store total inches

At the end of class, we change `Clock` so that it stores one number, the minutes since midnight. Do the same for `Height`: replace `feet` and `inches` in the `private` section with one `int totalInches`.

- The constructor still takes feet and inches: `Height(5, 11)` still has to work.
- `getFeet()`, `getInches()`, and `print` work out the feet and inches from `totalInches` when they need them.
- Rewrite `operator==`, `operator<`, and `operator+` to use `totalInches`. Each one should get shorter.
- Don't change `main()`. The output should be exactly the same as before step 9.

---

## Check your work

After step 8, and again after step 9, your program should print:

```
finn and jake match
finn is 5'4"
2
0
found at index 1
not found
5'11" is shorter than 6'2"
1'10"
5'4"
5'4"
5'11"
6'0"
6'2"
6'3"
6'0"
```

If your output is different, here's where to look:

| What you see | Where the problem probably is |
|---|---|
| It doesn't compile, and the error mentions `operator==`, `operator<`, or `operator+` | That operator is missing, misspelled, or has the wrong parameter type |
| `finn and bmo match` shows up | `operator==` |
| The counts aren't 2 and 0, or 5'11" isn't at index 1 | `operator==` (`count` and `find` both use it), or the roster isn't in the order from step 4 |
| `5'11" is shorter than 6'2"` is missing | `operator<`. Check what happens when the inches are bigger but the feet are smaller |
| The heights aren't in order | `operator<` (`sort` uses it) |
| You see `5'15"` instead of `6'3"` | `operator+` isn't rolling the inches over at 12 |
| The output was right before step 9 and isn't now | Compare that part of your class with your saved copy. `getFeet()` and `getInches()` are a good place to start, since `print` uses them |

The starter file already has `#include <vector>` and `#include <algorithm>`, which you need for `vector`, `count`, `find`, and `sort`. If you started from a blank file, add them.

---

## Submitting

Submit one file, `height.cpp`, that contains:

- [ ] your `Height` class with `operator==`, `operator<`, and `operator+`, storing one `int totalInches` (the step 9 version)
- [ ] your `main()` from steps 1–8
- [ ] your name in a comment at the top

Make sure it compiles with no warnings before you submit.

---

## Grading

You get full credit for turning in code that works, or a good-faith effort at it. I'll test your class with my own `main()`, and I'll also run yours. Working code means:

- [ ] `==` works, so `count` and `find` give the right answers
- [ ] `<` works, so `sort` puts the roster in order
- [ ] `+` works, including rolling the inches over at 12
- [ ] `Height` stores one `int totalInches`, and the output is the same as before step 9
- [ ] your `main()` uses `count`, `find`, and `sort`, and prints the output in "Check your work"
