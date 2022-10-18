# Programming Lab 1 - C Programming

## Learning Outcomes

By the end of this activity, a student should be able to:

1. Gain experience in C programming
2. Use system calls to accomplish tasks
3. Use memory allocation
4. Implement a makefile to compile and link your program

## Introduction

This lab will require you to implement two C functions, `readString()`,  `mysteryExplode()`, and a Makefile. the `readString()` function reads a single line from a file and returns the string in dynamically allocated memory as a char pointer.  The `mysteryExplode()` function explodes the c-string as described below.  You will also need to include a makefile to compile and link your program into an executable called _explode_.

## Files

This lab is templated at

```
https://github.com/mrasamny/csci-320-lab1
```

Click the <span style="background-color:green;color:white;">Use as template</span> button to copy the repo to your Github account and **clone** your repo on **your VM**.  You should commit your code as you work on your program and push it systematically to your repo.  **Your finalized product should be on your Github repo**.

Included in the repo are,

- **lab1.h** - definitions relevant to this programming project. DO NOT MODIFY.
- **lab1.c** - this is where you implement the required functions.
- **main.c** - contains main function.  DO NOT MODIFY.
- **README.md** - this file.

## Mystery Explosion

A word explosion mystery has occurred. However, to figure out the mystery and how a word explodes into a reoccurring new one, you will only be provided an example with no context clues.

A non-empty string such as `"Code"` is turned into `"CCoCodCode"`.

Return a new string similar to the string given above. For example,

```
mysteryExplode("Code") --> "CCoCodCode"
mysteryExplode("abc") --> "aababc"
mysteryExplode("ab") --> "aab"
mysteryExplode(":-)") --> "::-:-)"
```

## Requirements

You are required to complete the following:

1. Implement the two functions in the **lab1.c** file as declared and commented in the **lab1.h** file.
2. Write a makefile that will compile and link your program into an executable called _explode_.

## Program Specifications

Your program must perform the following:

1. Dynamically allocates memory in which to store 99 characters plus a null character for a total of 100 characters.
2. Reads a line from a text file and stores it in the dynamically allocated memory.  
2. Dynamically allocates <span style="color:red; font-weight:bold;">the exact amount of memory</span> to fit the exploded string.


## Submission

Your are to submit your Github repo link on Blackboard.  Your repo should show no submissions after the submissions deadline.  Any submissions after the deadline will result in an immediate zero (0) on the assignment.  If your **program does not compile, you will receive a zero (0) on the assignment**.

