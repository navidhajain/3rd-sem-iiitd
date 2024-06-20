#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/syscall.h>

int main(){
    char string1[8];
    int x=syscall(450, string1);
    printf(string1);
    return 0;
}