#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <fcntl.h> 
#include<string.h>
#include<stdlib.h>

void getscores(char* line, char sec, long scores[][], int index){
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
    for(int i=2, k=0; i<8; i++, k++){
        scores[index][k]=strtol(arr[i], &temp, 10);
    }
}

void outavg(long scores[][]){
    int sum;
    float avg;
    for (int i = 0; i < 6; i++){
        sum=0;
        for (int j = 0; j < 26; j++){
            sum+=scores[j][i];
        }
        avg=sum/26;
        printf("Average of Assignment %d is %.5f\n", i, avg);
        // char *buff;
        // char *str1="Average of Assignment ";
        // itoa(i, buff, 10);
        // strcat(str1, buff);
        // strcat(str1, " is ");
        // gcvt(avg, 5, buff);
        // strcat(str1, buff); 
        // write(1, str1, len(str1));       
    }
    
}

void readit(char sec){
    int fd=open("student_record.csv", O_RDONLY | O_EXCL);
    char row[200];
    if(fd<0){
        printf("error");
        _exit(-1);
    }
    for (int i = 1; read(fd, &row[i++],1); i++){
        if(row[i-1]=="\n"){
            break;
        }
    }
    long scores[26][6];
    int i=1, m=0;
    while(read(fd, &row[i++], 1)){
        if(row[i-1]=='\n'){
            row[i-1]='\0';   
            printf("%s", row);  
            getscores(row, sec, scores, m);
            m++;
            i=1;
            row[0]='\0';     
        }
    }

    if(strcmp(row, "")!=0){
        row[i-1]="\0";
        getscores(row, sec, scores, m);
    }
    outavg(scores);
    close(fd);
}

int main(){
    // int fd= open("student_record.csv", O_RDONLY);
    // char row[200];
    // for (int i = 1; read(fd, &row[i++],1); i++){
    //     printf("%s", row[i]);
    // }

    // return 0;
    pid_t pid;
    int stat;
    pid=fork();
    if (pid<-1){
        printf("Cannot create process");
    }
    else if(pid==0){
        readit('A');
        printf("\n\n");
        _exit(0);
    }
    else {
        waitpid(pid, &stat, WUNTRACED);
        if(stat!=0){
            char *a="error";
            write(1, a, strlen(a));
            _exit(0);
        }
        readit('B');
    }
    return 0;  
    

}