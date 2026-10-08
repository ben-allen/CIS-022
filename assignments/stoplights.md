# CIS022 In-Class Assignment: Stoplights

## Overview

Today you'll model a traffic light with an `enum`, then model a whole intersection with a `struct`.

<a href="stoplight_starter.cpp" download>Download the starter code</a>

Open the starter file, `stoplight_starter.cpp`. It has a function for every task below, each with a `TODO` comment and a placeholder body. **Don't change `main()`.** Once your functions are right, the program prints exactly what's shown under Expected output.

The starter won't compile until you've finished the first step of Part 1. That's expected: `main()` uses the `LightColor` type, and you haven't written it yet.

## Part 1: The LightColor enum

1. Define an `enum` called `LightColor` with the values `GREEN`, `YELLOW`, `RED`, and `FLASHING_RED`. Now the starter should compile.
2. Write `colorName()`. It returns `"green"`, `"yellow"`, `"red"`, or `"flashing red"`. (Remember: printing an enum directly just gives you a number.)
3. Write `nextColor()`. It returns the color that comes after the one passed in: `GREEN` → `YELLOW` → `RED` → `GREEN`.
4. Decide what `nextColor(FLASHING_RED)` should return. A flashing red light means the light is broken, so it shouldn't start cycling again on its own. Write a one-line comment explaining your choice.
5. Write `advance()`. It takes a `LightColor` **by reference** and changes it to the next color. You've already written a function that does most of the work.

**Try this:** before writing `nextColor()`, try `color = color + 1;` and compile it. It won't compile. Write a comment explaining why the compiler stops you.

## Part 2: The Intersection struct

An intersection has two lights: one for traffic going north-south and one for east-west. It also has a timer counting down the seconds until the lights change.

1. Define a `struct` called `Intersection` with three variables: `northSouth` (a `LightColor`), `eastWest` (a `LightColor`), and `secondsRemaining` (an `int`).
2. Write `printIntersection()`. It prints one line, like `north-south: green, east-west: red (5 seconds left)`. Use `colorName()`!
3. Write `isSafe()`. It returns `true` if at least one direction is stopped, meaning its light is `RED` or `FLASHING_RED`.
4. Write `tick()`, which simulates one second passing. It subtracts 1 from `secondsRemaining`. If that leaves time on the clock, it's done. If the timer has hit 0, it changes the lights according to the table below and resets the timer.

| When the timer hits 0 and... | Change the lights to... | Reset the timer to |
| --- | --- | --- |
| north-south is green | north-south yellow | `YELLOW_TIME` |
| north-south is yellow | north-south red, east-west green | `GREEN_TIME` |
| east-west is green | east-west yellow | `YELLOW_TIME` |
| east-west is yellow | east-west red, north-south green | `GREEN_TIME` |

Notice that every change in the table is just one light moving to its next color. Use `advance()` instead of assigning colors directly.

**The most important rule:** both directions must never be able to go at the same time. If `isSafe()` ever returns `false`, `main()` prints `CRASH!`, and something in your `tick()` is wrong.

## Expected output

When everything works, your program prints exactly this:

```
green
yellow
red
green
broken light after advancing: flashing red

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
```

## If you finish early

- Rewrite `colorName()` using a `switch` instead of `if`/`else`.
- Write `bool canGo(LightColor color)`. Should a yellow light count as "go"? Should a flashing red? There's no single right answer: pick one, and explain your reasoning in a comment.
- Write `void malfunction(Intersection &intersection)`, which sets both lights to `FLASHING_RED`. What does your `tick()` do to a malfunctioning intersection? What *should* it do?
