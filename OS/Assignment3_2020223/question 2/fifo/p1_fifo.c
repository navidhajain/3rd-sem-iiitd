#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
    char letters[] = "abcghjklmnopquvwxyzABCHJKLMNOPQRSTUVWXYZ12345690";
    char strings[50][50];
    char id[10];
    char buf6[100];
    for (int i = 0; i < 50; i++)
    {
        sprintf(id, "%d", i);
        char new[10]="\0";
        char word[50]="";
        for(int j=0; j<4; j++) {
            word[j] = letters[rand() % strlen(letters)];
        }
        // strcat(word, " at id ");
        // strcat(word, id);
        // strcat(word, new);
        // printf(word);
        sprintf(buf6, "%s at id %s", word, id);
        strcpy(strings[i], buf6);
        
    }

    printf("created strings array\n");
    char fifo[]="fifo12";
    int a=mkfifo(fifo, 0666);
    if(a<0){
        perror("fifo");
    }

    printf("opening fifo\n");

    int fd=open(fifo, O_WRONLY);
    int i=0;
    while(1){
        write(fd, strings[i], sizeof(strings[i]));
        if((i+1)%5==0){
            close(fd);
            fd=open(fifo, O_RDONLY);
            if(fd<0){
                perror("fd in p2");
            }
            int highestid;
            char buffer2[5];
            // sprintf()
            read(fd, buffer2, sizeof(buffer2));
            printf("highest id is %s\n", buffer2);
            close(fd);
            fd=open(fifo, O_WRONLY);

        }
        if(i==49){break;}
        i++;
    }
    close(fd);
    remove(fifo);
}




