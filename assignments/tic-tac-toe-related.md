# Warm-Up Exercises: Getting Ready for Tic-Tac-Toe

These exercises practice the skills you'll need for the tic-tac-toe program: checking whether values match, working with 2D arrays, converting between numbers and grid positions, and validating input. Work through them in order.

---

## 1. All the Same (about 10 min)

Write a function that checks whether every element of an array is the same character:

```cpp
char allSame(const char arr[], int size)
```

- If every element is the same, return that character.
- Otherwise, return `'?'`.

**Examples**

| Array                 | Returns |
|-----------------------|---------|
| `{'X', 'X', 'X'}`     | `'X'`   |
| `{'X', 'O', 'X'}`     | `'?'`   |

**Finished early?** Think about this question, but don't answer it yet. We'll come back to it in Exercise 5:

> What would go wrong if you returned `' '` (a space) instead of `'?'`, and the array held three spaces?

---

## 2. Row and Column Checks (about 15 min)

We'll use a small pixel image stored as a 2D array:

```cpp
const int WIDTH = 5;
char image[4][WIDTH];
```

Each pixel is `'R'`, `'G'`, `'B'`, or `'.'` for blank.

**Part A (together):** We'll write this one as a class:

```cpp
char rowAllSame(const char image[][WIDTH], int row)
```

It returns the shared character if every pixel in the given row is the same, and `'?'` otherwise.

**Part B (on your own):** Write the column version:

```cpp
char columnAllSame(const char image[][WIDTH], int rows, int col)
```

It returns the shared character if every pixel in the given column is the same, and `'?'` otherwise.

> **Tip:** Be careful about which index is the row and which is the column. `image[r][c]` means row `r`, column `c`.

---

## 3. Theater Seats (about 15 min)

A theater has rows of **4 seats**. Seats are numbered 1, 2, 3, ... from left to right, then top to bottom:

```
Row 0:   1   2   3   4
Row 1:   5   6   7   8
Row 2:   9  10  11  12
 ...
```

**Part A (on paper, first 5 minutes):** Rows and columns are numbered starting from 0. Fill in the table:

| Seat | Row | Column |
|------|-----|--------|
| 1    |     |        |
| 4    |     |        |
| 5    |     |        |
| 10   |     |        |

Look for a pattern. How could you calculate the row and column from the seat number?

**Part B:** Write two functions, both returning 0-based values:

```cpp
int seatRow(int seat)
int seatCol(int seat)
```

**Stuck?** Try one hint at a time, and only open the next one if you need it.

<details>
<summary>Hint 1</summary>

Seats 1–4 are in row 0, seats 5–8 are in row 1, and seats 9–12 are in row 2. The seats come in groups of 4. Which C++ operator tells you how many whole groups of 4 fit into a number? Which one tells you what's left over?

</details>

<details>
<summary>Hint 2</summary>

Integer division (`/`) and remainder (`%`) are the tools you need. But try `seat / 4` on seats 1 through 8 and you'll see seat 4 lands in the wrong row. The problem is that the seats start at 1 while rows and columns start at 0.

</details>


**Finished early?** Write the reverse, which turns a row and column back into a seat number:

```cpp
int seatNumber(int row, int col)
```

---

## 4. Predict the Output (about 5 min, with the class)

Using your `seatRow` and `seatCol` functions from Exercise 3, predict:

- What does `seatRow(0)` return?
- What does `seatCol(0)` return?

Now suppose your program uses those results to look up a seat in an array called `seats`. What happens? Will the program crash? What should your code do *before* it looks in the array?

---

## 5. Spot the Bug (about 10 min, in pairs, on paper)

This function is supposed to find a row where every pixel is the same, and return that row's character. It returns `'?'` if no such row exists.

```cpp
char findUniformRow(const char image[][WIDTH], int rows) {
    for (int r = 0; r < rows; r++) {
        char result = rowAllSame(image, r);
        if (result != '?')
            return result;
    }
    return '?';
}
```

Trace it by hand using this image:

```
Row 0:  .  .  .  .  .
Row 1:  R  G  .  B  R
Row 2:  R  R  R  R  R
Row 3:  G  .  B  B  .
```

1. Row 2 is all `'R'`. What does the function actually return?
2. Why does that happen?
3. How would you fix it?
4. Look back at the question from Exercise 1. How is it related to this bug?

---

## 6. Bonus: Validation Loop (about 15 min, fine to leave unfinished)

Use the `readInt()` function you've been given to ask the user for a seat number. Your program should:

- Print one message if the number is **out of range** (not a real seat).
- Print a **different** message if the seat is **already taken**.
- Keep asking until the user enters a seat that is valid and available.

> **Think about it:** In what order should you do the two checks? (Exercise 4 is a hint.)
