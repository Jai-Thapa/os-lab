//2. Create three child processes. Each child prints its PID, PPID, and child number.


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            printf("Child %d\n", i);
            printf("PID  : %d\n", getpid());
            printf("PPID : %d\n\n", getppid());
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)
        wait(NULL);

    return 0;
}