#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char buffer[100];
    int fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    if (n == -1)
        perror("read");
    close(fd);

    if (unlink("myfifo") == -1) {
        perror("unlink");
        return 1;
    }
    if (n <= 0)
        return 1;

    buffer[n] = '\0';
    printf("Received: %s", buffer);
    return 0;
}
