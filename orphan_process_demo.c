//4. Demonstrate an Orphan Process


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Before Parent Exit\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());

        sleep(5);

        printf("\nAfter Parent Exit\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
    }
    else
    {
        printf("Parent terminating...\n");
        exit(0);
    }

    return 0;
}