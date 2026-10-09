#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid1 = fork();

    if (pid1 < 0) {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid1 == 0) {
        // First Child Process
        printf("\nFirst Child Process (PID: %d)\n", getpid());
        printf("Fibonacci Series: ");

        int a = 0, b = 1, c;
        for (int i = 0; i < n; i++) {
            printf("%d ", a);
            c = a + b;
            a = b;
            b = c;
        }
        printf("\n");

        // Create Second Child
        pid_t pid2 = fork();

        if (pid2 < 0) {
            printf("Second fork failed!\n");
            exit(1);
        }

        if (pid2 == 0) {
            // Second Child Process
            long long fact = 1;

            for (int i = 1; i <= n; i++) {
                fact *= i;
            }

            printf("\nSecond Child Process (PID: %d)\n", getpid());
            printf("Factorial of %d = %lld\n", n, fact);
            exit(0);
        } else {
            wait(NULL); // Wait for second child
            exit(0);
        }

    } else {
        // Original Parent Process
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        printf("\nOriginal Parent Process (PID: %d)\n", getpid());
        printf("Sum of first %d natural numbers = %d\n", n, sum);

        wait(NULL); // Wait for first child
    }

    return 0;
}