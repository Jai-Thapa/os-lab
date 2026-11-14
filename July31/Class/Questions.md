Write a C program that creates one child process using fork() and prints the PID and PPID of both the parent and the child processes.
Write a C program that uses the return value of fork() to print "Parent Process" only in the parent process and "Child Process" only in the child process.
Write a C program in which the child process prints the numbers from 1 to 5, while the parent process waits for the child to finish using wait().
Write a C program in which the child process prints the Fibonacci series up to n, while the parent process calculates and prints the factorial of a given number.

Write a C program that uses fork() to create a child process. The child process prints the Fibonacci series and then creates another child process using fork(). This second child process prints the factorial of a given number, while the original parent process calculates and prints the sum of the first n natural numbers.