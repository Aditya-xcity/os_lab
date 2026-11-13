#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct Message {
    long type;
    char text[100];
};

int main(void)
{
    struct Message message;
    key_t key = ftok(".", 'A');
    if (key == (key_t)-1) {
        perror("ftok");
        return 1;
    }

    int id = msgget(key, 0600);
    if (id == -1) {
        perror("msgget");
        return 1;
    }
    ssize_t n = msgrcv(id, &message, sizeof(message.text), 1, 0);
    if (n == -1) {
        perror("msgrcv");
        return 1;
    }

    if (msgctl(id, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Received: %.*s", (int)n, message.text);
    return 0;
}
