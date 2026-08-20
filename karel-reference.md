# KAREL REFERENCE SHEET (C++-style)

## Basic commands

```cpp
move();
turn_left();
put_beeper();
pick_beeper();
```

Actions Karel performs. Always end with a semicolon in your code, e.g. `move();`

## Statements end with ; not with a new line

C++ ignores whitespace — line breaks, tabs, and extra spaces are all treated
the same as a single space. Starting a new line does not tell C++ that one
command has ended and another has begun; only a semicolon does that. This is
why every command needs its own `;`, even though indentation makes the code
look organized on its own.

## Basic conditionals

```cpp
front_is_clear()      front_is_blocked()
left_is_clear()       left_is_blocked()
right_is_clear()      right_is_blocked()
back_is_clear()       back_is_blocked()
beepers_present()     no_beepers_present()
```

These return true or false. Use them inside `if`, `else if`, and `while`.

## while loops

```cpp
while (front_is_clear()) {
    move();
}
```

Repeats the block for as long as the condition is true. Karel checks the
condition before each pass — including the first — so if it's already false,
the body never runs at all.

## if / else if / else

```cpp
if (beepers_present()) {
    pick_beeper();
} else if (front_is_clear()) {
    move();
} else {
    turn_left();
}
```

Karel checks the conditions in order, top to bottom, and runs the first block
whose condition is true — the rest are skipped. C++ has no "elif" — it's always
written as two words, `else if`. `else if` and `else` are both optional; use
only what the problem needs.

## && and || and !

```cpp
if (front_is_clear() && !beepers_present()) {
    move();
}
```

`&&` (AND) — the whole condition is only true if BOTH sides are true.
`||` (OR) — the whole condition is true if AT LEAST ONE side is true.
`!` (NOT) — flips a condition: `!beepers_present()` means "no beeper here."

Example above: move forward only if the front is clear AND there's no beeper
sitting on the current corner.

## When is the while condition checked?

```cpp
while (front_is_clear()) {
    move();
    move();
}
```

The condition is only checked at the top of the loop — once when Karel first
reaches the `while`, and then again each time the block finishes and control
loops back around. It is NOT checked in the middle of the block. So if the
front becomes blocked after the first `move()`, Karel still runs the second
`move()` before the loop gets a chance to notice and stop. Karel finishes
whatever's inside the curly braces first.

## Defining new functions

```cpp
void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}
```

Teaches Karel a new command, built from ones it already knows. Once defined,
call it exactly like a built-in: `turn_right();`. Definitions go outside of
`main()` and outside of each other — you can't define a function inside
another function.

## int vs void

The keywords `int` and `void` may not be meaningful yet if you don't have any
prior experience with C++. Rest assured that in a couple of weeks they will
make sense. For now, the short version is: use "int" when defining the main
function, and "void" when defining your own functions.

The longer version: Functions in C++ can "return" a value to the function that
called them when they end. `main` is special: it's the function that runs when
you start the program, meaning that no function of yours calls it. When `main`
ends, it returns a value *to the operating system itself*. If this value is 0,
that means the program finished normally. If the program crashes before
reaching `return 0;`, it returns a nonzero value to the operating system,
indicating that something went wrong and that as a result the operating system
might need to do some cleanup.

`return 0;` at the end of `main` in Karel programs doesn't actually do
anything, but it's included to let you get a sense of how C++ looks and works.
