#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int n, numbers[100];
    long long sum = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &numbers[i]) != 1)
            return 1;

    fflush(stdout);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        for (int i = 0; i < n; i++)
            if (numbers[i] % 2 == 0)
                sum += numbers[i];
        printf("Child: Sum of even numbers = %lld\n", sum);
        return 0;
    }

    if (waitpid(pid, NULL, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    for (int i = 0; i < n; i++)
        if (numbers[i] % 2 != 0)
            sum += numbers[i];
    printf("Parent: Sum of odd numbers = %lld\n", sum);
    return 0;
}
