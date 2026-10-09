//5. Demonstrate a Zombie Process


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child exits.\n");
        exit(0);
    }
    else
    {
        printf("Parent sleeping for 20 seconds.\n");
        printf("Run: ps -l\n");
        sleep(20);
    }

    return 0;
}




