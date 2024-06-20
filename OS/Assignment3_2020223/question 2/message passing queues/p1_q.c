#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msg_buffer {
   long msg_type;
   char msg[100];
} msg1, msg2;


int main() {
   key_t key1;
   int id1;
   key1 = 1110;
   id1 = msgget(key1, 0666 | IPC_CREAT); 
   msg1.msg_type = 1;

   key_t key2;
   int id2;
   key2 = 1111;
   id2 = msgget(key2, 0666 | IPC_CREAT); 

    char letters[] = "abcghjklmnopquvwxyzABCHJKLMNOPQRSTUVWXYZ12345690";
    char strings[50][50];
    char id[10];
    char buf6[100];
    for (int i = 0; i < 50; i++)    {
        sprintf(id, "%d", i);
        char new[10]="\0";
        char word[50]="";
        for(int j=0; j<4; j++) {
            word[j] = letters[rand() % strlen(letters)];
        }
        sprintf(buf6, "%s at id %s", word, id);
        strcpy(strings[i], buf6);        
    }

    int i=0;
    while(1){            
        strcpy(msg1.msg, strings[i]);
       int s= msgsnd(id1, &msg1, sizeof(msg1), 0);
    //    printf("%d", s);
        if((i+1)%5==0){
            memset(msg1.msg, 0, 100);      
            // strcat(msg1.msg, "");      
            strcpy(msg1.msg, strings[i]);
            // printf(msg1.msg);
            // strcat(msg1.msg, new);
            sprintf(msg1.msg, strings[i]);
             
            msgrcv(id2, &msg2, sizeof(msg2), 2, 0);
            printf("highest id is %s\n", msg2.msg);     
        }
        if(i==49){break;}
        i++;
    }

    msgctl(id1, IPC_RMID, NULL); 
    msgctl(id2, IPC_RMID, NULL);
  
   
}