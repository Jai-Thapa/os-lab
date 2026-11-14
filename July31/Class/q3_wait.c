#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // Child Process
        printf("Child Process:\n");
        for (int i = 1; i <= 5; i++) {
            printf("%d\n", i);
        }
    } else if (pid > 0) {
        // Parent Process
        wait(NULL);   // Wait for child to finish
        printf("Parent Process: Child has finished.\n");
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}