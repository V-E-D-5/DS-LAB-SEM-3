# Data Structures & Algorithms Lab 🚀

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Status](https://img.shields.io/badge/Status-Exam%20Ready-success?style=for-the-badge)
![OS](https://img.shields.io/badge/OS-Ubuntu%20Linux-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)

A collection of C programs implementing fundamental Data Structures and Algorithms. These implementations are optimized for clarity and exam preparation.

## 📂 List of Programs

| #  | Program Name | File Name | Key Concepts |
|----|-------------|-----------|--------------|
| 1  | **Dynamic Array Manager** | `dynamic_array.c` | Pointers, `malloc`, `realloc` |
| 2  | **Matrix Operations** | `matrix_ops.c` | 2D Arrays, Pointers to Pointers |
| 3  | **Book Stack** | `book_stack.c` | Stack of Structures, `push`, `pop` |
| 4  | **Infix to Postfix** | `infix_to_postfix.c` | Stack, Shunting-yard Algorithm |
| 5  | **Postfix Evaluation** | `postfix_eval.c` | Stack, Math Logic (`-lm` required) |
| 6  | **Tower of Hanoi** | `hanoi.c` | Recursion |
| 7  | **Call Center Queue** | `circular_queue.c` | Circular Queue, Enqueue, Dequeue |
| 8  | **Music Playlist** | `playlist_linked_list.c` | Singly Linked List |
| 9  | **Browser History** | `browser_history.c` | Doubly Linked List |
| 10 | **Polynomial Solver** | `polynomial_circular.c` | Circular Linked List (`-lm` required) |
| 11 | **Simple Dictionary** | `bst_dictionary.c` | Binary Search Tree (BST), Recursion |

## 🐧 How to Run (Ubuntu Lab)

Use the following commands in your terminal to create, compile, and run the programs.

| Action | Command | Description |
| :--- | :--- | :--- |
| **Write Code** | `gedit filename.c` | Opens the text editor. |
| **Compile (Normal)** | `gcc filename.c` | Standard compilation. |
| **Compile (Math)** | `gcc filename.c -lm` | **Important:** Use this for **Program 5 & 10** (links math library). |
| **Run Code** | `./a.out` | Executes the compiled program. |

## 📝 Notes
* **Input Handling:** Most string inputs use simple `scanf` or `scanf(" %[^\n]")` to ensure reliability during exams.
* **Memory Management:** Some programs focus on logic implementation and may omit explicit `free()` calls to keep the code concise for lab examinations.
* **Associativity:** The Infix to Postfix converter handles the Right Associativity of the exponent operator (`^`).

---
*Maintained by Vedant*
