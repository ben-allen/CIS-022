# CIS022 Assignment: Building a Date

## Overview

You'll build a `Date` class that stores a calendar date, refuses to hold an impossible one, moves forward one day at a time, and prints itself five different ways.

In class we built a `Clock`. A `Date` has the same shape: three numbers that roll over into each other, and one stored value shown in several formats. But the rules are harder. A minute always has 60 seconds; a month can have 28, 29, 30 or 31 days. And this time, you'll use `private` and a constructor so that nobody can ever create a `Date` like February 30.

Parts 1 and 2 are due early, at an ungraded checkpoint, so you can get feedback before the final deadline. Both dates are on Canvas.

**By the end you should be able to:**

- Use `private` to protect an object's instance variables and helper functions
- Write a constructor that refuses invalid values
- Write member functions that call each other to handle rollovers
- Format output with `setw` and `setfill`
- Find bugs by testing edge cases before you run your code

## Starter code

The `public:` section of the class is given to you. Don't change it: I'll test your code with my own `main()`, and it calls exactly these functions. The `private:` section is yours to design. You decide which instance variables to store and which helper functions to hide.

```cpp
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
public:
    Date(int month, int day, int year);

    int getMonth();
    int getDay();
    int getYear();

    void incrementDay();

    void printUS();        // 10/15/2026
    void printISO();       // 2026-10-15
    void printLong();      // October 15, 2026
    void printJapanese();  // Reiwa 8, October 15
    void printMonth();     // a calendar grid for this date's month

private:
    // Your design goes here: instance variables and helper functions.
};
```

Notice what's missing:

- **There is no `Date()` with no arguments.** `Date d;` won't compile. Every `Date` has to be created with a month, day and year, so there's never a moment when a `Date` exists without a real date in it.
- **There are no setters.** Once a `Date` is created, the only way to change it is `incrementDay()`. That means once your constructor has checked a date, nothing can turn it into a bad one later. 
- **There is no `incrementMonth()` or `incrementYear()` in the public section.** You'll probably want them, but as private helpers (see Part 3).

## Part 1: The constructor and validation

Write the constructor and the three getters. The constructor's job is to make sure every `Date` that exists is a real date.

**What counts as a real date:**

- The year is 1 or later.
- The month is from 1 to 12.
- The day is from 1 to the number of days in that month.

The number of days in a month is where this project gets interesting:

| Month | Days |
| --- | --- |
| April, June, September, November | 30 |
| February | 28, or 29 in a leap year |
| Every other month | 31 |

**Leap years** follow three rules, checked in this order:

1. A year divisible by 400 is a leap year (2000 was).
2. Otherwise, a year divisible by 100 is *not* a leap year (1900 wasn't).
3. Otherwise, a year divisible by 4 is a leap year (2028 will be).

Write these as two private helper functions, `isLeapYear()` and `daysInMonth()`. Why are they private? They're private because code outside the class has no reason to call them.

You'll use these functions again in Part 3. 

**What should happen with a bad date?** That's your decision. Pick one of these and write a comment above your constructor saying which you chose and why:

- Print an error message and end the program with `exit(1)`. You'll need `#include <cstdlib>`.
    - Note: `exit` is not the standard way in modern C++ to handle this. The standard way is to use "exceptions", which we won't get to until much later in the semester
- Print an error message and use a fixed fallback date instead.
- Quietly fix the date, such as changing February 30 to February 28. This is called "clamping" the date.

Whichever you choose, a `Date` must never end up holding an impossible date.

**Check your work.** This `main()` should compile and print `2 29 2028`:

```cpp
int main() {
    Date leapDay(2, 29, 2028);
    cout << leapDay.getMonth() << " " << leapDay.getDay() << " "
            << leapDay.getYear() << endl;
    return 0;
}
```

Each of these should be rejected: `Date(2, 29, 2027)`, `Date(2, 29, 1900)`, `Date(4, 31, 2026)`, `Date(13, 1, 2026)`, `Date(0, 10, 2026)`, `Date(6, 0, 2026)`. But `Date(2, 29, 2000)` is fine.

## Part 2: Four formats for printing a `Date`

Write `printUS()`, `printISO()`, `printLong()` and `printJapanese()`. Just like `print24()` and `print12()` on the `Clock`, these show one stored date in different formats, and each format has its own rules.

| Function | Example | Rules |
| --- | --- | --- |
| `printUS()` | `3/7/2026` | month/day/year, no padding |
| `printISO()` | `2026-03-07` | year-month-day; the year is always 4 digits, month and day always 2, padded with zeros |
| `printLong()` | `March 7, 2026` | full month name, no padding on the day |
| `printJapanese()` | `Reiwa 8, March 7` | era and year within the era, then the month name and day (see below) |

Why have more than one? Most of the world would read `3/7/2026` as July 3. The ISO format (from the international standard ISO 8601) puts the biggest unit first, so nobody can misread it. As a bonus, ISO dates sort correctly as plain text. The Japanese calendar is included to show how what looks like a relatively straightforward problem &mdash; "how do we represent a calendar date" &mdash; can actually be very complicated to solve. It is very common for software used globally to have to be able to correctly handle many different non-Gregorian calendars, and most useful software ends up being used globally.

Each function prints its date followed by `endl`.

**Leave `cout` the way you found it.** If you use `setfill('0')`, set it back to `setfill(' ')` before your function returns.

**Check your work:**

```cpp
int main() {
    Date today(10, 15, 2026);
    today.printUS();
    today.printISO();
    today.printLong();

    Date early(3, 7, 2026);
    early.printUS();
    early.printISO();
    early.printLong();

    cout << setw(6) << 42 << endl;
    return 0;
}
```

```text
$ ./date
10/15/2026
2026-10-15
October 15, 2026
3/7/2026
2026-03-07
March 7, 2026
    42
```

If the last line prints `000042`, your `printISO()` didn't put `cout` back the way it found it.

### The Japanese era calendar

Japan uses the same months and days as the US, but often counts years by imperial era. When a new emperor takes the throne, a new era begins, and its years are numbered from 1. October 15, 2026 is Reiwa 8.

`printJapanese()` prints the era, the year in that era, then the month name and day:

| Era | First day | Last day |
| --- | --- | --- |
| Reiwa | May 1, 2019 | (current) |
| Heisei | January 8, 1989 | April 30, 2019 |

Two edges to watch:

- **Eras change in the middle of a year.** April 30, 2019 is Heisei 31, but May 1, 2019 is Reiwa 1.
- **Year 1 of an era isn't written "1".** It's written *Gannen* (元年), meaning "first year." This is the same kind of rule as "hour 0 is written 12" on a 12-hour clock.

For dates before January 8, 1989, print `(era not supported)`.

**Check your work:**

```cpp
int main() {
    Date today(10, 15, 2026);
    today.printJapanese();

    Date lastHeisei(4, 30, 2019);
    lastHeisei.printJapanese();

    Date firstReiwa(5, 1, 2019);
    firstReiwa.printJapanese();

    Date firstHeisei(1, 8, 1989);
    firstHeisei.printJapanese();

    Date beforeHeisei(1, 7, 1989);
    beforeHeisei.printJapanese();

    return 0;
}
```

```text
$ ./date
Reiwa 8, October 15
Heisei 31, April 30
Reiwa Gannen, May 1
Heisei Gannen, January 8
(era not supported)
```

## Part 3: Moving forward one day

Write `incrementDay()`. Most of the time it just adds one to the day. But on the last day of a month, the day goes back to 1 and the month goes up, and on December 31, the year goes up too.

This is the same chain as `incrementSeconds()` → `incrementMinutes()` → `incrementHours()` on the `Clock`, with one big difference: the seconds always roll over after 59, but the last day of a month depends on the month and the year. Your `daysInMonth()` helper from Part 1 does the work here.

Write `incrementMonth()` and `incrementYear()` as **private** helpers that `incrementDay()` calls. They're private on purpose: if anyone could call `incrementMonth()` on January 31, there would be no good answer for what date comes next.

**Check your work:**

```cpp
int main() {
    Date newYear(12, 30, 2026);
    for (int i = 0; i < 3; i++) {
        newYear.printISO();
        newYear.incrementDay();
    }
    newYear.printISO();

    Date leap(2, 28, 2028);
    leap.incrementDay();
    leap.printISO();
    leap.incrementDay();
    leap.printISO();

    Date notLeap(2, 28, 2027);
    notLeap.incrementDay();
    notLeap.printISO();

    Date hundredDays(10, 15, 2026);
    for (int i = 0; i < 100; i++) {
        hundredDays.incrementDay();
    }
    hundredDays.printLong();

    return 0;
}
```

```text
$ ./date
2026-12-30
2026-12-31
2027-01-01
2027-01-02
2028-02-29
2028-03-01
2027-03-01
January 23, 2027
```

## Part 4: Printing a calendar

Write `printMonth()`, which prints a calendar for the whole month that the date falls in, like the one on a wall calendar.

To know which column the 1st goes in, you need its day of the week. That math isn't the point of this assignment, so here's a function that does it. Paste it above your class, and don't change it:

```cpp
// Returns the day of the week for a date:
// 0 for Sunday, 1 for Monday, ..., 6 for Saturday.
int dayOfWeek(int month, int day, int year) {
    int offsets[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) {
        year--;
    }
    return (year + year / 4 - year / 100 + year / 400
            + offsets[month - 1] + day) % 7;
}
```

**The format:**

- The first line is the month name and the year.
- The second line is the day names, exactly as shown below.
- Each day number is printed with `setw(3)`, the same trick as the multiplication table from class.
- Before the 1st, print 3 spaces for each empty day.
- After each Saturday, start a new line. The last week ends with a new line too, even if it's not full.

**Check your work:**

```cpp
int main() {
    Date today(10, 15, 2026);
    today.printMonth();

    Date february(2, 1, 2026);
    february.printMonth();

    return 0;
}
```

```text
$ ./date
October 2026
 Su Mo Tu We Th Fr Sa
              1  2  3
  4  5  6  7  8  9 10
 11 12 13 14 15 16 17
 18 19 20 21 22 23 24
 25 26 27 28 29 30 31
February 2026
 Su Mo Tu We Th Fr Sa
  1  2  3  4  5  6  7
  8  9 10 11 12 13 14
 15 16 17 18 19 20 21
 22 23 24 25 26 27 28
```

February 2026 is a good test case. It starts on a Sunday and ends on a Saturday, so there are no empty days at either end.

## Part 5: Test the edges

Write your own `main()` that tests your class. Remember the midnight and noon bugs in `print12()`: bugs hide at the edge cases, so that's what your tests should cover.

For each test, write the output you expect in a comment *before* you run it. If the real output doesn't match, either your code or your expectation is wrong. Figure out which, and fix it.

```cpp
Date leap(2, 28, 2028);
leap.incrementDay();
leap.printISO();    // expect: 2028-02-29
```

Your tests must include at least these cases:

- [ ] The last day of a 30-day month and of a 31-day month, incremented
- [ ] December 31, incremented
- [ ] February 28, incremented, in a leap year and in a year that isn't one
- [ ] February 28, incremented, in 1900 and in 2000
- [ ] A single-digit month and day in every print format
- [ ] `printJapanese()` on both sides of an era change, and on the first day of an era
- [ ] `printMonth()` for a month that starts on a Saturday
- [ ] At least one invalid date, in a comment explaining what your constructor will do with it

If you chose `exit(1)` for invalid dates, the program stops at the first bad one. Put that test last, or leave it commented out with a note saying what happens when you run it.

## Extra credit: The Ethiopian calendar (+4)

This part is optional. It adds a new class and a new function, so you won't need to change `Date` at all.

The Ethiopian calendar is the official calendar of Ethiopia, and it's a completely different calendar, not just a different way of numbering years. October 15, 2026 is Tikimt 5, 2019.

Its rules are surprisingly regular:

- There are 13 months. The first 12 always have exactly 30 days.
- The 13th month, Pagume, has 5 days, or 6 in a leap year. That 6th day is an *intercalary* day: a day inserted to keep the calendar in step with the seasons, like February 29.
- A year is a leap year when `year % 4 == 3`.

| # | Month | # | Month |
| --- | --- | --- | --- |
| 1 | Meskerem | 8 | Miyazya |
| 2 | Tikimt | 9 | Ginbot |
| 3 | Hidar | 10 | Sene |
| 4 | Tahsas | 11 | Hamle |
| 5 | Tir | 12 | Nehase |
| 6 | Yekatit | 13 | Pagume |
| 7 | Megabit |  |  |

**Step 1:** Write a new class, `EthiopianDate`, with a constructor that rejects impossible dates, getters, `incrementDay()`, and `printLong()` (which prints `Tikimt 5, 2019`).

**Step 2:** Convert dates. Write a regular (non-member) function:

```cpp
void printEthiopian(int month, int day, int year);
```

It takes a Gregorian date and prints the matching Ethiopian date. You don't need a formula. You know one pair of dates that match: **September 12, 1999 is Meskerem 1, 1992.** Create a `Date` and an `EthiopianDate` set to those, then call `incrementDay()` on both, together, until the `Date` reaches the one you were asked about. Your function only needs to handle dates on or after September 12, 1999.

```cpp
printEthiopian(10, 15, 2026);
printEthiopian(9, 11, 2026);
printEthiopian(9, 10, 2027);
printEthiopian(9, 11, 2027);
printEthiopian(9, 12, 2027);
```

```text
Tikimt 5, 2019
Meskerem 1, 2019
Pagume 5, 2019
Pagume 6, 2019
Meskerem 1, 2020
```

The Ethiopian New Year, Enkutatash, falls on September 11, except in the year before a Gregorian leap year, when it falls on September 12. In 2027 it moves to September 12 because 2019 has an intercalary Pagume 6.

## Reflection

Answer each question in a few sentences, in a comment at the top of your file.

1. What does your constructor do with `Date(2, 30, 2026)`, and why did you choose that over the other options?
2. Suppose `month`, `day` and `year` were public. Write two lines of code that would break a `Date`, and explain what would go wrong afterward. (Think back to the `Clock` that reached 09:76:00.)
3. Suppose `Date` had to print dates in five different calendars. Would you still store a month, day and year? If not, what would you store instead?

## Submitting

Submit one file, `date.cpp`, that contains:

- [ ] The `dayOfWeek()` function, unchanged
- [ ] Your `Date` class with every member function implemented
- [ ] Your Part 5 test `main()`
- [ ] Your reflection answers, in a comment at the top
- [ ] Extra credit, if you did it

Make sure it compiles with no warnings before you submit.

## Grading

| Part | Points |
| --- | --- |
| Part 1: Constructor, validation and getters | 5 |
| Part 2: Four print formats, including the Japanese era calendar | 5 |
| Part 3: `incrementDay()` and rollovers | 5 |
| Part 4: `printMonth()` | 3 |
| Part 5: Edge-case tests | 3 |
| Reflection | 2 |
| Style: names, indentation, comments, `private` used well | 2 |
| **Total** | **25** |
| Extra credit: Ethiopian calendar | +4 |

A program that doesn't compile can earn at most half credit.

