
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main()
{
    int fd;
    char buffer[100];

    if (fork() == 0)
    {
        // Child process
        char filename[] = "even.txt";
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

        for (int i = 2; i <= 20; i += 2)
            dprintf(fd, "%d\n", i);

        close(fd);
        printf("Child: File created\n");
    }
    else
    {
        // Parent process
        wait(NULL);

        fd = open("even.txt", O_RDONLY);
        int n;

        printf("Parent: File contents:\n");

        while ((n = read(fd, buffer, 99)) > 0)
        {
            buffer[n] = '\0';
            printf("%s", buffer);
        }

        close(fd);
    }

    return 0;
}
