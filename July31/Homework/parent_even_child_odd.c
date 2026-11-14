//1. Parent prints even numbers (1–20) and child prints odd numbers


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child
        for (int i = 1; i <= 20; i += 2)
            printf("Child (Odd): %d\n", i);
    }
    else
    {
        // Parent
        for (int i = 2; i <= 20; i += 2)
            printf("Parent (Even): %d\n", i);

        wait(NULL);
    }

    return 0;
}