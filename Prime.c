// write a program to caluclatesum of array in parent process and then check the calculated sum is Prime or 
//not in child Process..

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = 5;
    int sum = 0;
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0)
    {
        // Parent process
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        printf("Parent Process\n");
        printf("Sum of array = %d\n", sum);

        // Send sum to child
        close(fd[0]);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);

        wait(NULL);
    }
    else
    {
        // Child process
        int received_sum;
        int isPrime = 1;

        close(fd[1]);

        read(fd[0], &received_sum, sizeof(received_sum));
        close(fd[0]);

        if (received_sum <= 1)
        {
            isPrime = 0;
        }
        else
        {
            for (int i = 2; i * i <= received_sum; i++)
            {
                if (received_sum % i == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
        }

        printf("Child Process\n");

        if (isPrime)
            printf("%d is Prime\n", received_sum);
        else
            printf("%d is Not Prime\n", received_sum);
    }

    return 0;
}