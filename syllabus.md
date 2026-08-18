# CIS 022 — Programming Using C++

**Solano Community College**
*Course schedule: Fall 2026*
*Instructor: Ben Allen*

---

## Crucial Details

- **Classroom:** 503
- **Credit hours:** 3
- **Meeting time:** 11:00 AM – 12:50 PM, Tuesdays and Thursdays
  > **Note:** This class follows the "Berkeley time" convention established at Cal — classes start 10 minutes after their listed time, with the ten minutes before used for informal question-answer. As such, lectures will start at **11:00 AM**.

### Class Time Structure

- Although lecture and lab times are listed separately, there will tend to be more lecture time on Tuesdays and more lab time on Thursdays.
- **Lecture time** is typically devoted to introducing new material and doing short exercises based on that material.
- **Lab time** is typically devoted to working on larger assignments that let you demonstrate your ability to write complex, interesting programs.

### Office Hours

- **Office:** Room 516
- **Hours (subject to revision):** 1:30 – 2:30, Monday through Thursday

If you can't make it in person during office hours but would like to meet, let the instructor know and a Zoom meeting can be set up. If you need to meet outside these hours, send an email and something can be arranged.

### Email

**benjamin.allen@solano.edu**

Emails sent during the week will typically get a response within 24 hours; emails sent over the weekend will get a response the following Monday. Feel free to re-send emails that haven't been answered in a timely fashion — a small amount of extra credit is available if there's no response within 48 workweek-hours and you send a reminder.

---

## Course Overview

This is a rigorous course on the C++ programming language, focusing on object-oriented programming and modern C++ features, including the Standard Template Library (STL).

> **Note: This is *not* a first programming class.** There will be a fair amount of review in the first two weeks, and you're not expected to already know C++ — but some prior experience with C++, Java, Python, or a similar language is assumed.
>
> **Repeat: this is NOT a first programming class.** If you have little or no programming experience, consider taking CIS 1 first.

This class is homework-intensive by design — learning modern programming techniques requires a significant amount of practice. Expect to find some of it frustrating; that's normal, and the satisfaction of solving a hard problem more than makes up for it.

---

## Student Learning Outcomes

Upon completion of this class, students will be able to:

1. Implement object-oriented programs in C++
2. Understand the principles of object-oriented design
3. Demonstrate familiarity with key algorithms and data structures
4. Use function templates and class templates to work with generic types

## Detailed Course Objectives

- Design, implement, test, and debug programs using classes, inheritance, virtual classes, templates, and exception handling
- Write programs that use pointers to implement data structures
- Learn to use iterators and smart pointers
- Demonstrate understanding of late binding and polymorphism
- Understand memory management in C++, including the distinction between stack-allocated and heap-allocated memory
- Demonstrate understanding of the importance of types, type incompatibility, and type-checking in providing abstraction and safety

---

## Discord

- [Invite link to the class Discord](https://discord.gg/TGukznhE)
- **This link expires August 28th — join ASAP.**
- **Please do not share this link with anyone not in the class.**

Send a direct message with your real name when you log in; anyone not recognized as a student will be kicked and banned.

Don't have Discord? [Download it here](https://discord.com/download).

The server is open 24/7 — feel free to discuss assignments and class material there. Please keep the on-topic channels on-topic; in-class questions are encouraged to go through Discord rather than the Zoom chat so you can refer back to them later.

Off-topic channels available:
- `#social` — general discussion
- `#pets` — pictures and discussion of adorable animals

---

## Recommended Text

*Starting Out with C++: from Control Structures to Objects* — Tony Gaddis

This text was chosen because it covers modern C++ features from the 2014 and 2017 revisions and has a useful index — one of the few programming textbooks worth keeping as a desk reference. It doesn't go as deep as ideal, though; the more advanced material doesn't show up until the last third of the book.

If this is your first time with C++, it's strongly recommended that you read the first half of the text (Chapters 1–10) at the start of the semester. That material will be reviewed in the first two or three weeks of class, but the course assumes prior exposure to concepts like variables, loops, if/else statements, and function declarations.

> **Please don't spend a lot of money on the textbook. There's no reason to buy it new — cheap used or digital copies should work fine.**

---

## Suggested Software

No particular development environment is required. If you've done C++ development before, use whatever tools you're comfortable with. If not, [OnlineGDB](https://www.onlinegdb.com) is recommended — a capable online C++ environment suitable for all assignments in this course.

### Using OnlineGDB

**Account setup**
1. Go to [onlinegdb.com](https://www.onlinegdb.com)
2. Set the language to C++ using the dropdown near the top of the editor
3. Create a free account (look for **Sign Up** in the top right) so your projects are saved
4. Start typing code in the main editor panel — that's it

**Writing/running code**
- Code gets automatic syntax highlighting for keywords, strings, and comments
- **Run** (green button) compiles and executes your program; output appears in the console panel
- Compiler errors show with line numbers — click an error to jump to that line

**Multi-file projects**
- Use the **Add File** / project panel on the left to add files once an assignment needs more than one (e.g., a `.h` and a `.cpp`)
- Keep filenames exactly as specified in the assignment — this matters for `#include` statements to resolve correctly

**Saving and submitting work**
1. **Save** your project via **File → Save**
2. **Download** your code via **File → Download** (single-file programs download as `.cpp`; multi-file projects download as `.zip`)
3. **Upload** the downloaded file to the assignment on the course LMS — this is your official submission

### Additional Useful Resources

Unlike some languages (notably Java), there's no single official online C++ reference. A few well-maintained unofficial ones used regularly:

- [cplusplus.com/reference](http://www.cplusplus.com/reference) — a comprehensive but terse reference; good for looking up how to use a specific function or class
- [C++ Language Reference | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/cpp-language-reference?view=msvc-160)
- [C++ Standard Library Overview | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/standard-library/cpp-standard-library-overview?view=msvc-160)

Microsoft's C++ language and standard library docs are a solid go-to for syntax and intended use of unfamiliar language features.

**A resource that's less useful than it seems:** relying on StackOverflow and similar Q&A sites isn't recommended for this class. Answers there are typically written by and for working professional programmers, who tend to reach for heavy-duty language constructs — you may find what you're looking for, but you're just as likely to end up confused by unreadable code.

---

## Grading

Roughly half of your grade comes from assignments, and half from two midterms plus one final exam. In-person exams are a practical necessity in the current environment.

### Functionality Grading and Style Grading

- **60%** of each assignment's grade is based on **functionality**. Matching the output of the reference implementation in all cases earns full credit; points are lost for crashes, invalid results, or other incorrect behavior.
- **40%** of each assignment's grade is based on adherence to the class **style guide**. Beyond the grade itself, consistent good style makes implementation and debugging on projects of this scope vastly easier.

### Feedback on Assignments

Written feedback on assignments will be relatively minimal — for more detail, talk to the instructor during lab or office hours.

### Late Policy

- Short exercises must be completed the day they're assigned.
- Other assignments turned in a day or more early get a **3% bonus**.
- Projects turned in up to 3 days late get a **10% penalty**.
- Projects turned in more than 3 days late get a **20% penalty**.

### Extensions

Extenuating circumstances happen — reach out to discuss your situation if something unforeseen comes up.

- **Ask for extensions in advance.** Requests made the day an assignment is due will not be answered.
- No extensions are given for short exercises, since solutions are generally given out the class session after they're due.

---

## Accommodations

Solano Community College is committed to providing equitable access to learning opportunities for all students. The Accessibility Services Center (ASC) works with students who have disabilities to determine and provide reasonable accommodations.

If you have, or think you may have, a disability and would like to request accommodations, contact the ASC at **(707) 864-7136** or **asc@solano.edu**. If accommodations are already established with the ASC, please share your accommodation letter and discuss your needs as early in the semester as possible.

---

## Academic Dishonesty and Cheating

- ✅ **Reasonable (and a good idea):** discussing your ideas and programs with classmates.
- ❌ **Not reasonable:** directly copying solutions from classmates.
  - To avoid accidentally triggering the plagiarism detector, avoid looking directly at each other's code. Talk about how the code works and ideas for improving it, but don't show the code itself.
- ❌ **Not reasonable:** copy-pasting code from StackOverflow or similar sites.
  - If you must use a short snippet (one or two lines at most) from the internet, **include a comment noting where it came from and how it works.** Be prepared to answer questions about code you've used.
  - New programmers generally shouldn't be using StackOverflow at all — the answers there tend to target working professionals and involve advanced concepts outside the scope of this class.
- If another student pressures you to let them copy your code, let the instructor or TAs know.
