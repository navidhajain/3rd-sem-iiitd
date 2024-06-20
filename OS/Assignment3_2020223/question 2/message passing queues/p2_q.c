#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msg_buffer
{
    long msg_type;
    char msg[100];
} msg1, msg2;

int main()
{
    key_t key1;
    int id1;
    key1 = 1110;
    id1 = msgget(key1, 0666 | IPC_CREAT);

    key_t key2;
    int id2;
    key2 = 1111;
    id2 = msgget(key2, 0666 | IPC_CREAT);
    msg2.msg_type = 2;
    int i = 1;

    while (1)
    {
        int x = msgrcv(id1, &msg1, sizeof(msg1), 1, 0);

        printf("received: %s\n", msg1.msg);
        if (i % 5 == 0)
        {
            char idx[5] = "10";
            sprintf(idx, "%s", &msg1.msg[11]);
            memset(msg2.msg, 0, 100);
            sprintf(msg2.msg, "%s", idx);
            msgsnd(id2, &msg2, sizeof(msg2), 0);
        }
        if (i == 50)
        {
            break;
        }
        i++;
    }
    msgctl(id1, IPC_RMID, NULL);
    msgctl(id2, IPC_RMID, NULL);

    return 0;
}