#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<errno.h>

int pid;
static inline unsigned int randomnumber();
void sigalarm_handle();

int main(int argc, char *argv[]){
    signal(SIGALRM, sigalarm_handle); //handler for SIGALARM
    pid = atoi(argv[0]); //convert to int, ps1
    struct itimerval value;    
    value.it_value.tv_sec = 2; //seconds
    value.it_value.tv_usec = 0;  //microseconds
    value.it_interval = value.it_value;
    setitimer(ITIMER_REAL, &value, NULL); //sets value of an interval timer

    while(1);
}

static inline unsigned int randomnumber() {
    unsigned int r;
    asm volatile ("RDRAND %%rax" 
                            : "=r"(r)); // use assembly in your c code

    // printf("random number in SR: %i\n", r);                        
    return r;
}

void sigalarm_handle(int q) {
    
    union sigval x;
    x.sival_int = randomnumber(); //handler reads a random number
    
    int a=sigqueue(pid, SIGTERM, x);
     //queue the process and the data
    if(a==0){
        printf("sigqueue works\n");
    }
    if(a<0){
        printf("error in sigqueue\n");
        printf("Value of errno: %d\n", errno);
        printf("The error message is : %s\n", strerror(errno));
     }
    // kill(pid, SIGTERM);
}