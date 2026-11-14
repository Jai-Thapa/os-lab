#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // Child Process
        printf("Child Process\n");
    } else if (pid > 0) {
        // Parent Process
        printf("Parent Process\n");
    } else {
        // Fork failed
        printf("Fork failed!\n");
    }

    return 0;
}