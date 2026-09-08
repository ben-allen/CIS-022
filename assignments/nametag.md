# Assignment: Centered Name Banner

**Objective:** Practice reading user input, basic string manipulation, and breaking a program into functions.

## Task

Write a C++ program that:

1. Prompts the user to enter their name (their name may contain spaces, so read the whole line).
2. Prints a banner exactly 72 characters wide, three lines tall:
   - **Line 1:** 72 asterisks.
   - **Line 2:** 3 asterisks, then the user's name centered in the remaining space, then 3 asterisks — the full line must still be exactly 72 characters wide.
   - **Line 3:** 72 asterisks.

### Example (for someone who enters `Ada Lovelace`)

```
************************************************************************
***                        Ada Lovelace                             ***
************************************************************************
```

## Function requirements

Your `main()` should be short and mostly just call other functions — it should not contain the logic itself. At minimum, you must write:

- A function that gets and returns the user's name (with an appropriate return type — no non-constant global variables).
- A function that prints a line of 72 asterisks, since you need this twice.
- A function that takes the name and prints the centered middle line (the `***` + padding + name + padding + `***` line).

You're welcome to break these down further — e.g., a separate function that just computes the padding, or one that builds/returns the centered line as a string rather than printing it directly. More decomposition is fine as long as each function does one clear thing.

## Other requirements / hints

- Use `getline` rather than `cin >>` to read the name, since names can contain spaces.
- The name should be centered within the space between the two sets of three stars — not centered across the full 72-character line.
- If the padding doesn't divide evenly on both sides, it's fine to put the extra space on either side — just document which one you chose.
- Test with a short name, a long name, and a name close to the 66-character limit to make sure your padding logic doesn't produce a negative number of spaces.

## Stretch goal (optional)

Handle the case where the name is too long to fit in 66 characters — decide and document what your program should do (truncate? print an error? let the banner overflow?).

---

## Primer: `getline`

`cin >> variable` stops at the first whitespace, so `cin >> name` on input like `Ada Lovelace` only captures `Ada`. To read a full line, including spaces, use `getline` instead:

```cpp
string name;
cout << "Enter your name: ";
getline(cin, name);   // captures "Ada Lovelace", not just "Ada"
```

Note the syntax difference: `getline` is a function you call and pass `cin` into, not something you use with `>>`.

**Gotcha:** if a program mixes `cin >>` and `getline`, the `getline` call often appears to get skipped. This happens because `cin >>` leaves the trailing `\n` (from the user hitting Enter) sitting in the input buffer, and the next `getline` call reads that leftover newline as an empty line instead of waiting for new input. The simplest fix for this assignment: don't mix them — since you're only reading a name, just use `getline` throughout.
