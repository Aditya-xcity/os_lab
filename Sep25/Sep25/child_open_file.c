// Write a C program to open a file in the child process.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    pid_t pid;
    int fd;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child process\n");

        fd = open("sample.txt", O_RDONLY);

        if (fd < 0)
        {
            printf("File could not be opened\n");
            exit(1);
        }

        printf("File opened successfully by child process\n");

        close(fd);
    }
    else
    {
        printf("Parent process\n");
    }

    return 0;
}