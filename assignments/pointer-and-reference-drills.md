# Pointers and references: practice sheet

Twenty-two short problems. Work through them in order. Write your answers on paper, or in a copy of this file under each **Answer:** line.

**Assume every snippet starts with:**

```cpp
#include <iostream>
using namespace std;
```

Snippets with no function around them are inside `main()`.

---

## Part A: Say it in English

Write each line as a plain-English sentence. Example: `int x = 5;` → "Make an `int` called `x` and store 5 in it."

**A1.** `int &r = x;`

**Answer:**

**A2.** `int *q = &x;`

**Answer:**

**A3.** `*q = 5;`

**Answer:**

---

## Part B: Which job?

`&` and `*` each have two jobs. In a **declaration**, they're part of the type. In an **expression**, they're operators. For every `&` and `*` in each line, say which job it's doing: *reference type*, *pointer type*, *address-of*, or *dereference*.

**B1.** `int *p = &x;`

**Answer:**

**B2.** `int &r = *p;`

**Answer:**

---

## Part C: What's the type?

**C1.** What are the types of `a` and `b`?

```cpp
int* a, b;
```

**Answer:**

---

## Part D: Predict the output

Write exactly what prints. Commit to an answer before you run anything!

**D1.**
```cpp
int x = 5;
int *p = &x;
*p = 10;
cout << x << endl;
```

**Answer:**

**D2.**
```cpp
int x = 5;
int &r = x;
r++;
cout << x << " " << r << endl;
```

**Answer:**

**D3.**
```cpp
int x = 5;
int y = 7;
int *p = &x;
p = &y;
*p = 1;
cout << x << " " << y << endl;
```

**Answer:**

**D4.**
```cpp
int x = 5;
int y = 7;
int &r = x;
r = y;
cout << x << " " << y << endl;
```

**Answer:**

**D5.**
```cpp
void bumpValue(int n) { n = n + 1; }
void bumpRef(int &n)  { n = n + 1; }
void bumpPtr(int *n)  { *n = *n + 1; }

int main() {
    int a = 0;
    bumpValue(a);
    bumpRef(a);
    bumpPtr(&a);
    cout << a << endl;
    return 0;
}
```

**Answer:**

**D6.** (Hint: when `main()` passes `q`, what does the function actually receive?)
```cpp
void moveAndWrite(int *p, int *target) {
    p = target;
    *p = 50;
}

int main() {
    int x = 1;
    int y = 2;
    int *q = &x;
    moveAndWrite(q, &y);
    cout << x << " " << y << " " << *q << endl;
    return 0;
}
```

**Answer:**

---

## Part E: Draw the memory

Draw memory **at the end of each snippet**. Draw each variable as a labeled box holding its value. Draw each pointer as a box with an arrow to whatever it points to. Put objects made with `new` in a separate area labeled "heap." If you'd rather not draw, describe it in words instead: list every variable, its value, and what each pointer points to.

**E1.**
```cpp
int a = 1;
int b = 2;
int *p = &a;
int *q = &b;
p = q;
*p = 9;
```

**Answer:**

**E2.** (One pointer, three stops. What's in `a`, `b`, and `c` at the end, and what does `p` point to?)
```cpp
int a = 1;
int b = 2;
int c = 3;
int *p = &a;
*p = 10;
p = &b;
*p = 20;
p = &c;
```

**Answer:**

**E3.** (Which object can never be `delete`d, and why?)
```cpp
int *p = new int(1);
int *q = new int(2);
p = q;
```

**Answer:**

---

## Part F: Will it work?

Classify each snippet as one of:

- **(a) Fine.** It compiles and runs correctly.
- **(b) Compile error.** Say why.
- **(c) Compiles, but undefined behavior.** It might crash, print garbage, or seem to work. Say what the mistake is.

**F1.** `int &r;`

**Answer:**

**F2.**
```cpp
int x = 5;
int *p = x;
```

**Answer:**

**F3.**
```cpp
int *p;
cout << *p << endl;
```

**Answer:**

**F4.**
```cpp
int *p = new int(5);
delete p;
cout << *p << endl;
```

**Answer:**

**F5.**
```cpp
int *p = new int(5);
delete p;
p = nullptr;
delete p;
```

**Answer:**

---

## Part G: Fix it

**G1.** This function is supposed to double the caller's variable, but it doesn't. Explain why. Then fix it two ways, once with a reference and once with a pointer, and show how `main()` calls each version.

```cpp
void doubleIt(int n) {
    n = n * 2;
}
```

**Answer:**

---

## Part H: Short answer

**H1.** Name two things a pointer can do that a reference can't.

**Answer:**
