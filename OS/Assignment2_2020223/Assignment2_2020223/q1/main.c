#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>

void term_handle(int signum, siginfo_t *x, void *ptr){ // handler for SIGTERM
    printf("inside term handler\n");
    int y=x->si_value.sival_int;
    printf("value: [%d]\n",y);
}

int main(){
    pid_t ps1=fork(); //used to create a new process 
    if(ps1<0){
        printf("Error in creation of process\n");
    }else if(ps1==0){ //inside child process
        struct sigaction signal_reg; 
        // signal(SIGTERM, term_handle); //handler for SIGTERM
        memset(&signal_reg, 0, sizeof(signal_reg)); //fill memory
        signal_reg.sa_handler=term_handle; //tell which handler
        signal_reg.sa_flags=SA_SIGINFO;
        sigaction(SIGTERM, &signal_reg, NULL); 
    }else{ //inside parent process
        pid_t stpid=fork();
        if(stpid==0){ //child st
            // printf("st\n");
            char buffer[50];
            sprintf(buffer, "%d", ps1);
            char *arguments[]={buffer, NULL};
            int a=execv("./e2", arguments); // goes to e2
            if(a<0){
                printf("error in execv\n");
            }
        }else if(stpid<0){
            printf("error in creation of process (st)");
        }
        else{ //parent
            // printf("after st\n");
            pid_t srpid=fork();
            if(srpid==0){ //child sr
                // printf("sr\n"); 
                char buffer1[50];                
                sprintf(buffer1, "%d", ps1);
                char *arguments1[]={buffer1, NULL};
                int a1=execv("./e1", arguments1); //goes to e1
                if(a1<0){
                printf("error in execv\n");
            }
            }else if(srpid<0){
                printf("error in creation of process (sr)\n");
            }
            else{ //parent of sr
                // printf("last\n");
            }
        }
    }
    while(1);
}

