#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void fibonacci(int n)
{
    int a = 0, b = 1, c;

    printf("Child Process (PID: %d)\n", getpid());
    printf("Fibonacci Series up to %d:\n", n);

    while (a <= n)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int isArmstrong(int num)
{
    int original = num, sum = 0, digit;

    while (original > 0)
    {
        digit = original % 10;
        sum += digit * digit * digit;
        original /= 10;
    }

    return (sum == num);
}

void armstrong(int n)
{
    int i;

    printf("Parent Process (PID: %d)\n", getpid());
    printf("Armstrong Numbers up to %d:\n", n);

    for (i = 1; i <= n; i++)
    {
        if (isArmstrong(i))
            printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int n;
    pid_t pid;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child Process
        fibonacci(n);
    }
    else
    {
        // Parent Process
        wait(NULL);
        armstrong(n);
    }

    return 0;
}