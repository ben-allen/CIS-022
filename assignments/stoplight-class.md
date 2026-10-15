# CIS022 Assignment: Stoplights, Part 2: From struct to class

## Overview

In the stoplights assignment, you built an `Intersection` struct, then wrote functions like `isSafe(intersection)` and `tick(intersection)` that took an `Intersection` as a parameter. Those functions only make sense for an intersection, so in this assignment you'll move them *inside* it, the same way we turned `karelMove(karel)` into `Karel::move()`.

<a href="stoplight_class_starter.cpp" download>Download the starter code</a>

You'll start from **your own stoplights code**, so finish that assignment first. Open `stoplight_class_starter.cpp`. **Don't change `main()`.** Once your class is right, the program prints exactly what's shown under Expected output.

The starter won't compile until you've finished Part 2. That's expected: `main()` uses the `Intersection` class, and you haven't written it yet.

## Part 1: Bring over your enum and functions

Paste your `LightColor` enum and your `colorName()`, `nextColor()`, and `advance()` functions into the starter, in the spot marked `TODO`. Don't change them.

These three stay as ordinary functions, not member functions. You'll explain why in Part 3.

## Part 2: The Intersection class

1. Define a `class` called `Intersection` with the same three variables as your struct: `northSouth`, `eastWest`, and `secondsRemaining`. Remember `public:`, or `main()` won't be able to use them.
2. Declare three member functions inside the class: `void print();`, `bool isSafe();`, and `void tick();`.
3. Define each one outside the class, using `Intersection::` before the function name. Start from your stoplights versions of `printIntersection()`, `isSafe()`, and `tick()`, and change them:
    - The functions no longer take an `Intersection` parameter. Delete it.
    - Inside the functions, there's no `intersection.` in front of the variables anymore. Just write `northSouth`, `eastWest`, and `secondsRemaining`.
    - `printIntersection()` becomes `print()`. Now that it's called as `mainAndFirst.print()`, the word "intersection" in the name would just repeat itself.

**The most important rule is still the same:** both directions must never be able to go at the same time. If `main()` ever prints `CRASH!`, something in your `tick()` is wrong.

## Part 3: Questions

Answer these in a multi-line comment at the top of your file.

1. `main()` has two intersections, `mainAndFirst` and `oakAndThird`. When `main()` calls `oakAndThird.tick()`, the code inside `tick()` changes `secondsRemaining`. **Whose** `secondsRemaining` is it? How does `tick()` know?
2. Look at the last line of the expected output. `mainAndFirst` didn't change while `oakAndThird` was ticking. Why not?
3. Why did `colorName()`, `nextColor()`, and `advance()` stay ordinary functions instead of becoming members of `Intersection`?
4. Temporarily add these two lines to `main()`, right after `mainAndFirst` is set up:

    ```cpp
    mainAndFirst.northSouth = GREEN;
    mainAndFirst.eastWest = GREEN;
    ```

    Does the program compile? What does it print? Your `tick()` is careful never to let both directions go at once, but did that help here? Write down any idea you have for how the `Intersection` class could stop this from happening. (You don't need to make it work, and there's no wrong answer: we'll come back to this.) **Then delete the two lines** so your output matches again.

## Expected output

When everything works, your program prints exactly this. The first 16 lines should match the second half of your stoplights output.

```
north-south: green, east-west: red (5 seconds left)
north-south: green, east-west: red (4 seconds left)
north-south: green, east-west: red (3 seconds left)
north-south: green, east-west: red (2 seconds left)
north-south: green, east-west: red (1 seconds left)
north-south: yellow, east-west: red (2 seconds left)
north-south: yellow, east-west: red (1 seconds left)
north-south: red, east-west: green (5 seconds left)
north-south: red, east-west: green (4 seconds left)
north-south: red, east-west: green (3 seconds left)
north-south: red, east-west: green (2 seconds left)
north-south: red, east-west: green (1 seconds left)
north-south: red, east-west: yellow (2 seconds left)
north-south: red, east-west: yellow (1 seconds left)
north-south: green, east-west: red (5 seconds left)
north-south: green, east-west: red (4 seconds left)

north-south: red, east-west: green (2 seconds left)
north-south: red, east-west: green (1 seconds left)
north-south: red, east-west: yellow (2 seconds left)
north-south: red, east-west: yellow (1 seconds left)

main and first, which didn't tick during that loop:
north-south: green, east-west: red (3 seconds left)
```

## If you finish early

- Add a member function `void malfunction();` that sets both lights to `FLASHING_RED`. Call it on `oakAndThird` and print it. Notice that `mainAndFirst` is unaffected.
- Add member functions `bool northSouthCanGo();` and `bool eastWestCanGo();`. If you wrote `canGo(LightColor color)` for the stoplights extension, use it to keep them short. Should `canGo()` itself be a member of `Intersection`? Explain why or why not in a comment.
