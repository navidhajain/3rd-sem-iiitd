#include <errno.h>
#include <stdio.h>
#include<sys/un.h>
#include<sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BACKLOG 1
#define nameSocket "socket"
#define buffer_size 50

int main(int argc, char *argv[]) {
    int x;
    char letters[] = "abcdghiopquvwxyzABCHIJKLMNOPQRSTUVWXYZ12345690";
    struct sockaddr_un addr; //socket address family for ipc
    unlink(nameSocket); //to delete any pre existing
    int fd_p1;
    if((fd_p1 = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {  //create socket, returns fd
        perror("error");
    }
    printf("ID of Server socket is %d\n", fd_p1); 
    memset(&addr, 0, sizeof(struct sockaddr_un)); //fill addr
    addr.sun_family = AF_UNIX; //establish connection
    strncpy(addr.sun_path, nameSocket, sizeof(addr.sun_path)-1); //copy pathname

    if(bind(fd_p1, (struct sockaddr *) &addr, sizeof(addr.sun_path)) == -1) { //bind name to a socket, assigns the address
        perror("bind error");
    }

    if(listen(fd_p1, BACKLOG) == -1) { //check error for pending connection
        perror("listen");
    }

    char strings[50][10];

    // for (int i = 0; i < 50; i++)
    // {
    //     sprintf(id, "%d", i);
    //     char new[10]="\0";
    //     char word[50]="";
    //     for(int j=0; j<4; j++) {
    //         word[j] = letters[rand() % strlen(letters)];
    //     }
    //     // strcat(word, " at id ");
    //     // strcat(word, id);
    //     // strcat(word, new);
    //     // printf(word);
    //     sprintf(buf6, "%s at id %s", word, id);
    //     strcpy(strings[i], buf6);
        
    // }

    for(int i=0; i<50; i++) {
        memset(strings[i], 0, 10);
        char entry[10] = "";
        char idx[2];
        if(i < 10) {
            sprintf(idx, "%d", i);
            strcat(entry, idx);
        } else {
            sprintf(idx, "%d", (i/10)); //get the strings wali list
            strcat(entry, idx);
            sprintf(idx, "%d", (i%10));
            strcat(entry, idx);
        }
        strcat(entry, ": ");
        char word[5];
        for(int j=0; j<4; j++) {
            word[j] = letters[rand() % strlen(letters)];
        }
        strcat(entry, word);
        strcat(strings[i], entry); // eg "12:abcde"
    } //contains the list of strings

    char buffer[buffer_size];

    while(1) {
        int fd_p2 = accept(fd_p1, NULL, NULL); //accept single connection, returns new socket descriptor
        if(fd_p2 == -1) { //error for the new socket fd
            perror("accept");
        }
        int bufint = 0;
        while(bufint<50) {
            memset(buffer, 0, buffer_size);  
            char newLine[] = "\n";
            for(int i=bufint; i<bufint+5 && i<50; i++) {
                strcat(buffer, strings[i]);
                strcat(buffer, newLine); 
                //sprintf(buffer)
            }
            int len = strlen(buffer);
            buffer[len] = '\0';        
            x = send(fd_p2, buffer, buffer_size, 0); //send message to the socket
        
            
            x = read(fd_p2, buffer, buffer_size); //read from fd (client fd here)
           
            bufint = atoi(buffer); //string to int
            printf("highest id is %d\n", bufint);
            bufint++;
        }
        close(fd_p2);
        break;
    }

    close(fd_p1);
    unlink(nameSocket);    
}