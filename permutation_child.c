#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n, arr[100], sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0)
    {
        // Child process
        printf("\nChild Process\n");

        for (int i = 0; i < n; i++)
            sum += arr[i];

        printf("Sum = %d\n", sum);

        if (isPrime(sum))
            printf("The sum %d is Prime.\n", sum);
        else
            printf("The sum %d is Not Prime.\n", sum);

        exit(0);
    }
    else
    {
        // Parent process
        wait(NULL);
        printf("Parent process completed.\n");
    }

    return 0;
}