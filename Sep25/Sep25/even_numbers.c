/*

Write a C program to write all the even numbers into a file, pass the name of the file from the child process to the parent process, and print the contents of the file in the parent process.

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int fd;
    char filename[] = "even.txt";
    char buffer[100];

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child process\n");

        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd < 0)
        {
            printf("File could not be opened\n");
            exit(1);
        }

        for (int i = 1; i <= 20; i++)
        {
            if (i % 2 == 0)
            {
                char num[10];
                int n;

                n = sprintf(num, "%d\n", i);
                write(fd, num, n);
            }
        }

        close(fd);

        printf("Even numbers written to file\n");
        printf("File name: %s\n", filename);
    }
    else
    {
        wait(NULL);

        printf("\nParent process\n");
        printf("Reading file: %s\n", filename);

        fd = open(filename, O_RDONLY);

        if (fd < 0)
        {
            printf("File could not be opened\n");
            exit(1);
        }

        int n;

        while ((n = read(fd, buffer, sizeof(buffer) - 1)) > 0)
        {
            buffer[n] = '\0';
            printf("%s", buffer);
        }

        close(fd);
    }

    return 0;
}