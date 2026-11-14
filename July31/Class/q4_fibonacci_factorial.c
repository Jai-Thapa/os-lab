#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int n, num;
    long long fact = 1;

    printf("Enter the number of terms for Fibonacci: ");
    scanf("%d", &n);

    printf("Enter the number for Factorial: ");
    scanf("%d", &num);

    pid = fork();

    if (pid == 0) {
        // Child Process - Fibonacci
        int a = 0, b = 1, c;

        printf("Fibonacci Series:\n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", a);
            c = a + b;
            a = b;
            b = c;
        }
        printf("\n");
    } else if (pid > 0) {
        // Parent Process - Factorial
        for (int i = 1; i <= num; i++) {
            fact = fact * i;
        }

        printf("Factorial of %d = %lld\n", num, fact);
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}