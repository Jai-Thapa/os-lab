// write a program to check whether a number is prime or not in the child processs and the process calcualte factoial of a number in the parent process.


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n, i;
    pid_t pid;

    printf("Enter a number: ");
    scanf("%d", &n);

    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    // Child Process - Check Prime
    if (pid == 0) {
        int prime = 1;

        if (n <= 1)
            prime = 0;
        else {
            for (i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    prime = 0;
                    break;
                }
            }
        }

        if (prime)
            printf("Child Process: %d is a Prime Number.\n", n);
        else
            printf("Child Process: %d is Not a Prime Number.\n", n);
    }

    // Parent Process - Calculate Factorial
    else {
        long long factorial = 1;

        wait(NULL);   // Wait for child process to finish

        for (i = 1; i <= n; i++) {
            factorial *= i;
        }

        printf("Parent Process: Factorial of %d = %lld\n", n, factorial);
    }

    return 0;
}