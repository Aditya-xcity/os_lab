#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    char text[1024];

    printf("Enter data: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    key_t key = ftok(".", 'S');
    if (key == (key_t)-1) {
        perror("ftok");
        return 1;
    }

    int id = shmget(key, sizeof(text), IPC_CREAT | IPC_EXCL | 0600);
    if (id == -1) {
        perror("shmget");
        return 1;
    }
    char *shared = shmat(id, NULL, 0);
    if (shared == (void *)-1) {
        perror("shmat");
        if (shmctl(id, IPC_RMID, NULL) == -1)
            perror("shmctl");
        return 1;
    }

    strcpy(shared, text);
    if (shmdt(shared) == -1) {
        perror("shmdt");
        if (shmctl(id, IPC_RMID, NULL) == -1)
            perror("shmctl");
        return 1;
    }

    printf("Data written to shared memory.\n");
    return 0;
}
