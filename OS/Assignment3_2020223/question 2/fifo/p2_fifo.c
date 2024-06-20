#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
    char buffer[50];
    char fifo[]="fifo12";
    int i=1;
    int fd=open(fifo, O_RDONLY);
    if(fd<0){
        perror("fd in p2");
    }

    while(1){
        read(fd, buffer, sizeof(buffer));
        printf("received: %s\n", buffer);
        if((i%5)==0){
            close(fd);
            fd=open(fifo, O_WRONLY);
            if(fd<0){
                perror("fd in p2");
            }            
            // int idxint;
            char idx[5]="10";                        
            // for(int j=0; j<strlen(buffer)-3; j++){ //axfs at id 5
            //     if(buffer[i]=='i' && buffer[i+1]=='d'){
            //         strcat(idx, buffer[i+3]);
            //         if ((i+4)<strlen(buffer)){
            //             strcat(idx, buffer[i+4]);
            //         }
            //         // idxint=atoi(idx);
            //     }
            // }
            sprintf(idx, "%s" , &buffer[11]);
            // char buff3[50];
            // printf("%s\n", idx);
            // sprintf(buff3, i)
            write(fd, idx, strlen(idx));
            // printf("sent max\n");
            close(fd);
            fd=open(fifo, O_RDONLY);
            if(fd<0){
                perror("fd in p2");
            }
       }
        if(i==50){break;}
        i++;

    }
}