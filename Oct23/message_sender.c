#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct Message {
    long type;
    char text[100];
};

int main(void)
{
    struct Message message = {1, ""};

    printf("Enter message: ");
    if (fgets(message.text, sizeof(message.text), stdin) == NULL)
        return 1;

    key_t key = ftok(".", 'A');
    if (key == (key_t)-1) {
        perror("ftok");
        return 1;
    }

    int id = msgget(key, IPC_CREAT | IPC_EXCL | 0600);
    if (id == -1) {
        perror("msgget");
        return 1;
    }
    if (msgsnd(id, &message, strlen(message.text) + 1, 0) == -1) {
        perror("msgsnd");
        if (msgctl(id, IPC_RMID, NULL) == -1)
            perror("msgctl");
        return 1;
    }

    printf("Message sent.\n");
    return 0;
}
