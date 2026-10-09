#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void permute(char s[], int l, int r)
{
    if (l == r)
        printf("%s\n", s);
    else
    {
        for (int i = l; i <= r; i++)
        {
            char temp = s[l];
            s[l] = s[i];
            s[i] = temp;

            permute(s, l + 1, r);

            temp = s[l];
            s[l] = s[i];
            s[i] = temp;
        }
    }
}

int main()
{
    if (fork() == 0)
    {
        char s[20];

        printf("Enter a string: ");
        scanf("%19s", s);

        printf("Permutations:\n");
        permute(s, 0, strlen(s) - 1);
    }
    else
        wait(NULL);

    return 0;
}
