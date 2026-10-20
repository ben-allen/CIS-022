# CIS 022 — Programming Using C++

**Solano Community College**
*Course schedule: Fall 2026*
*Instructor: Ben Allen*

---

## Crucial Details

- **Classroom:** 503
- **Credit hours:** 3
- **Meeting time:** 11:00 AM – 12:55 PM, Tuesdays and Thursdays
  > **Note:** This class follows the "Berkeley time" convention established at Cal — classes start 10 minutes after their listed time, with the ten minutes before used for informal question-answer. As such, lectures will start at **11:10 AM**.

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

I will respond to emails sent during the week within 24 hours of the time they're sent, and generally faster than that for emails sent during the work day. For emails sent over the weekend, I will respond on the following Monday. I encourage you to re-send emails if I haven't responded to them in a timely fashion — I do confess, I am very distractible and sometimes miss emails. I will give a small amount of extra credit if I haven't responded in 48 workweek-hours, and you remind me about it.

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

- An invite link to the class Discord is on Canvas.
- **Please do not share the invite link with anyone not in the class.**

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

- **Reasonable (and a good idea):** discussing your ideas and programs with classmates.
- **Not reasonable:** directly copying solutions from classmates.
  - To avoid accidentally triggering the plagiarism detector, avoid looking directly at each other's code. Talk about how the code works and ideas for improving it, but don't show the code itself.
- **Not reasonable:** copy-pasting code from StackOverflow or similar sites.
  - If you must use a short snippet (one or two lines at most) from the internet, **include a comment noting where it came from and how it works.** Be prepared to answer questions about code you've used.
  - New programmers generally shouldn't be using StackOverflow at all — the answers there tend to target working professionals and involve advanced concepts outside the scope of this class.
  - Likewise, LLM-generated code can contain very advanced concepts and constructs. AI tools aren't banned in this class, but when you use LLM code, **include a comment indicating that it's LLM-generated** that **explains in your own words how it works**.
- If another student pressures you to let them copy your code, let the instructor know.

---

## Let's talk about LLMs

There are some things LLMs are very good at, and some things they're much worse at. They are *very* good at certain types of student exercises -- anything that there's a large amount of publicly-available code for. They get noticeably less reliable when you're doing something that's:

- More complicated or more unusual than what's common on the internet
- In a less-commonly used programming language or library
- Dependent on details of a large codebase that they can't see all of at once

And when they fail in these situations, the failures are often *subtle*: code that looks right, runs, and is wrong in a way you won't catch unless you understand it.

**For my part:** I tend to use LLMs for certain rote/repetitive tasks -- I often use them to correct accessibility-related errors and formatting inconsistencies in slide decks. I've also used them for proofreading course materials, like this syllabus. 

As far as coding with them: I find them very useful for writing "boilerplate-heavy" code; for example, I "vibe-coded" the graphical user interface of the Karel the Robot tool that's on the class GitHub. Before this semester I used a text-based interface for this tool, because I could never quite find the time to write the JavaScript GUI. One reason I put it off until I could ask a machine to do it for me is that the part of the program that is the same in the text-based version as in the GUI version -- the code that actually interprets Karel commands -- is inherently interesting, and absolutely has to be 100% correct. On the other hand, I find the parts about getting (for example) the GUI text box pane to display in exactly the right place to be kind of boring, and it's okay if there are small problems with it. 

I am comfortable using the vibe-coded interface for the Karel tool, since it's not a huge disaster if there are glitches that I haven't noticed -- if they happen you can tell me about them and I can dive into the code to fix them. I wouldn't be nearly as comfortable trusting the vibe-coded interface if I intended other instructors to use it, since I'm certain it has meaningful errors that I haven't yet spotted.

Additionally: if I didn't understand JavaScript and its quirks, I would have had a much harder time with the vibe-coding itself -- getting good results from automated code generation tools requires being able to clearly and concisely describe the problem, and also describe what's important to get right. When you vibe-code with concepts you *don't* already understand, you'll often get something that works -- at first. The trouble starts when it stops working, or when it works on the inputs you tried but not on the ones you didn't, and you can't tell why or how to fix it. At that point you're asking a machine to fix code that neither of you really understands, and that loop can eat an enormous amount of time (and tokens).

This is to say: LLMs are good at the boring part, which is pretty cool, and they're good at getting things *almost* right, which is sometimes all you need, and they're good if you can describe *exactly* what you want them to do, which requires real knowledge.

One 2025 study (by the research group METR) found that experienced developers working on large projects they knew well were about 19% *slower* when using AI tools -- while believing they'd been about 20% *faster*. The tools have improved since then, and 2026-era industry estimates tend to find gains that are real -- but far more modest than expected. One big reason: reviewing generated code for subtle errors takes time, and it takes most of the same knowledge of computer science and computer engineering that writing the code yourself does.

Full disclosure: an LLM wrote the last paragraph.

In any case, it's a very, very good idea to learn the underlying concepts instead of just letting LLMs write code for you, because once you start writing programs above a certain level of complexity you will run into serious problems if you don't actually understand what the LLM generates. Although your grades are derived from your responses to assignments, this class isn't *about* the assignments. Instead, it's about the exercise you get while working on the assignments. A forklift can lift more weight than you can. However, getting a workout requires lifting things with your own muscles instead of with a forklift.
