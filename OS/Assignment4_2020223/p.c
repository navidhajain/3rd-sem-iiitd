#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<errno.h>

int main(){
    char string[8];
    FILE *fp;
    fp = fopen("/dev/urandom", "r");
    fread(&string, 1, 8, fp);
    fclose(fp);
    // char string[]="1234567";
    // printf(string);
    int xyz=syscall(449, string);
    if(xyz<0){
        printf("Value of errno: %d\n", errno);
        printf("The error message is : %s\n", strerror(errno));
    }
    printf("%d\n", xyz);

}