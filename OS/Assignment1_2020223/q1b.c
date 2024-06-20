#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <fcntl.h> 
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

void printavg(char* line, char sec){
    char* t= strtok(line, ",");
    char *arr[8], *temp;
    float avg=0;
    for(int i=0; t!=NULL; i++){
        *(arr+i)=t;
        t=strtok(NULL, ",");
    }
    if(*arr[1]!=sec){
        return;
    }
    for(int i=2; i<8; i++){
        avg+=strtol(arr[i], &temp, 10);
    }
    avg=avg/6;
    printf("Id=%s sec=%s Average marks=%.2f \n", *arr[0], *arr[1], avg);
}

int main(){

}


