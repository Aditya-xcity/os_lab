#include <stdio.h>

int main(void)
{
    int pages[100], frames[20];
    int n, count, faults = 0;
    int lastUsed[20] = {0};

    printf("Enter length of reference string: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter page numbers: ");
    for (int i = 0; i < n; i++)
        if (scanf("%d", &pages[i]) != 1 || pages[i] < 0)
            return 1;

    printf("Enter number of frames: ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 20)
        return 1;
    for (int j = 0; j < count; j++)
        frames[j] = -1;

    printf("Page\tFrames\n");
    for (int i = 0; i < n; i++) {
        int slot = 0;
        while (slot < count && frames[slot] != pages[i])
            slot++;

        if (slot == count) {
            slot = 0;
            for (int j = 1; j < count; j++)
                if (lastUsed[j] < lastUsed[slot])
                    slot = j;
            frames[slot] = pages[i];
            faults++;
        }
        lastUsed[slot] = i + 1;

        printf("%d\t", pages[i]);
        for (int j = 0; j < count; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Hits = %d\n", n - faults);
    printf("Total Page Faults = %d\n", faults);
    return 0;
}
