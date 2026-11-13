#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int fd[2], status;
    char message[] = "Graphic Era";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        return 1;
    }

    if (pid == 0) {
        close(fd[0]);
        if (write(fd[1], message, sizeof(message)) != sizeof(message)) {
            perror("write");
            close(fd[1]);
            return 1;
        }
        close(fd[1]);
        printf("Child wrote: %s\n", message);
        return 0;
    }

    close(fd[1]);
    ssize_t n = read(fd[0], buffer, sizeof(buffer) - 1);
    close(fd[0]);
    if (n == -1)
        perror("read");
    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        return 1;
    }
    if (n <= 0 || !WIFEXITED(status) || WEXITSTATUS(status) != 0)
        return 1;

    buffer[n] = '\0';
    printf("Parent read: %s\n", buffer);
    return 0;
}
