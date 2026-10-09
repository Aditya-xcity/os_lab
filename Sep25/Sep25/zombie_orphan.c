
//Write a c program to demonstrate zombie and orphan process 


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child process started\n");
        printf("Child PID: %d\n", getpid());

        sleep(5);

        printf("Child process completed\n");
    }
    else
    {
        printf("Parent process started\n");
        printf("Parent PID: %d\n", getpid());

        sleep(2);

        printf("Parent is waiting for child\n");
        wait(NULL);

        printf("Parent process completed\n");
    }

    return 0;
}