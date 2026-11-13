#include <stdio.h>

struct Process {
    int id;
    int burst;
};

int main(void)
{
    struct Process processes[20];
    int n;
    long long waiting = 0, totalWaiting = 0, totalTurnaround = 0;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 20)
        return 1;

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("P%d burst time: ", i + 1);
        if (scanf("%d", &processes[i].burst) != 1 || processes[i].burst <= 0)
            return 1;
    }

    printf("Process\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        long long turnaround = waiting + processes[i].burst;
        printf("P%d\t%d\t%lld\t%lld\n", processes[i].id,
               processes[i].burst, waiting, turnaround);
        totalWaiting += waiting;
        totalTurnaround += turnaround;
        waiting = turnaround;
    }

    printf("Average Waiting Time = %.2f\n", (double)totalWaiting / n);
    printf("Average Turnaround Time = %.2f\n", (double)totalTurnaround / n);
    return 0;
}
