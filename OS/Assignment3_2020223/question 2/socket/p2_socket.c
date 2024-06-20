#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>

#define BACKLOG 1
#define nameSocket "socket"
#define buffer_size 50

int main(int argc, char *argv[]) {
    int x;
    struct sockaddr_un addr; //socket address family for ipc
    int fd_p2 = socket(AF_UNIX, SOCK_STREAM, 0); //create socket, returns fd
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX; //establish connections
    strncpy(addr.sun_path, nameSocket, sizeof(addr.sun_path)-1);

    x = connect(fd_p2, (const struct sockaddr *) &addr, sizeof(struct sockaddr_un)); //initiation of a socket connection reffered by fd mentioned
    if(x == -1) {
        perror("connect");
    }    
    char buffer[buffer_size];
    while(1){
        memset(buffer, 0, buffer_size);
        x = read(fd_p2, buffer, buffer_size);  //read from fd (client fd here)
        if(x == -1) {
            perror("read");
        }

        printf(" received: %s\n", buffer); 
        // for(int j=0; j<strlen(buffer)-3; j++){ //axfs at id 5
        //     if(buffer[i]=='i' && buffer[i+1]=='d'){
        //         strcat(idx, buffer[i+3]);
        //         if ((i+4)<strlen(buffer)){
        //             strcat(idx, buffer[i+4]);
        //         }
        //         // idxint=atoi(idx);
        //     }
        // }       
        int max = -1;

        for(int i = 0; i < strlen(buffer); i++) {
            int buffernum = 0;
            if(buffer[i] == '\n') {
                i++;
                //number 
                buffernum += buffer[i] - '0';
                i++;
                //printf("")
                if(buffer[i] != ':') { //get the max id
                    buffernum *= 10;
                    buffernum += buffer[i] - '0';
                }
            }
            if(buffernum > max) { //compare 
                max = buffernum;
            }
        }

        memset(buffer, 0, buffer_size);
        sprintf(buffer, "%d", max);

        x = send(fd_p2, buffer, buffer_size, 0); 
        if(x == -1) {
            perror("send");
        }
        sleep(1);
    }
    close(fd_p2);
}