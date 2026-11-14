#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // Child Process
        printf("Child Process\n");
        printf("Child PID  : %d\n", getpid());
        printf("Child PPID : %d\n", getppid());
    } else if (pid > 0) {
        // Parent Process
        printf("Parent Process\n");
        printf("Parent PID  : %d\n", getpid());
        printf("Parent PPID : %d\n", getppid());
    } else {
        // Fork failed
        printf("Fork failed!\n");
    }

    return 0;
}