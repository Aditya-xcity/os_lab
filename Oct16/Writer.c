#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    int fd;
    char message[100];


    if (mkfifo("myfifo", 0666) == -1 && errno != EEXIST)
    {
        perror("mkfifo");
        return EXIT_FAILURE;
    }


    fd = open("myfifo", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    printf("Enter message: ");

    if (fgets(message, sizeof(message), stdin) == NULL)
    {
        perror("fgets");
        close(fd);
        return EXIT_FAILURE;
    }

  
    if (write(fd, message, strlen(message) + 1) == -1)
    {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    return EXIT_SUCCESS;
}