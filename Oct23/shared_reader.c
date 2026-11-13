#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    key_t key = ftok(".", 'S');
    if (key == (key_t)-1) {
        perror("ftok");
        return 1;
    }

    int id = shmget(key, 1024, 0600);
    if (id == -1) {
        perror("shmget");
        return 1;
    }
    const char *shared = shmat(id, NULL, SHM_RDONLY);
    if (shared == (void *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Received: %.1024s", shared);
    int result = shmctl(id, IPC_RMID, NULL);
    if (result == -1)
        perror("shmctl");
    if (shmdt(shared) == -1) {
        perror("shmdt");
        return 1;
    }
    return result == -1;
}
