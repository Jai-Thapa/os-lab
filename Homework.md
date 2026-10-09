# Operating Systems Lab Programs (Process Management)

## 1. Parent Prints Even Numbers, Child Prints Odd Numbers

**Question:**

Write a C program in which:
- The **parent process** prints all even numbers from **1 to 20**.
- The **child process** prints all odd numbers from **1 to 20**.

---

## 2. Create Three Child Processes

**Question:**

Write a C program to create **three child processes** using `fork()`. Each child process should print:
- Its **Child Number** (Child 1, Child 2, Child 3)
- Its **Process ID (PID)**
- Its **Parent Process ID (PPID)**

---

## 3. Child Exit Status Using `wait()`

**Question:**

Write a C program where:
- The **child process** exits with **status code 10**.
- The **parent process** waits for the child using `wait()` and prints the child's exit status.

---

## 4. Demonstrate an Orphan Process

**Question:**

Write a C program to demonstrate an **orphan process**. The child process should print its:
- **Parent Process ID (PPID)** before the parent terminates.
- **Parent Process ID (PPID)** after the parent terminates.

Observe how the PPID changes after the parent exits.

---

## 5. Demonstrate a Zombie Process

**Question:**

Write a C program to demonstrate a **zombie process**. Observe the zombie process using the `ps` command before the parent calls `wait()`.

---

## 6. Execute the `date` Command Using `fork()`, `exec()`, and `wait()`

**Question:**

Write a C program using `fork()`, `exec()`, and `wait()` to execute the `date` command. The parent process should wait for the child process to complete before terminating.