#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    char message[100];

    printf("Enter message: ");
    if (fgets(message, sizeof(message), stdin) == NULL)
        return 1;

    if (mkfifo("myfifo", 0600) == -1) {
        perror("mkfifo");
        return 1;
    }

    int fd = open("myfifo", O_WRONLY);
    if (fd == -1) {
        perror("open");
        unlink("myfifo");
        return 1;
    }

    size_t length = strlen(message);
    ssize_t n = write(fd, message, length);
    if (n != (ssize_t)length)
        perror("write");

    close(fd);
    return n != (ssize_t)length;
}
