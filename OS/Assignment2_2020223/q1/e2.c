#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>

pid_t pid;
void sigalarm_handle();
static inline unsigned long long cc(void);

int main(int argc, char *argv[]){
    signal(SIGALRM, sigalarm_handle); //handler for SIGALARM
    pid = atoi(argv[0]); //convert to integer, pid ps1
    struct itimerval value;    
    value.it_value.tv_sec = 2; //seconds
    value.it_value.tv_usec = 0;  //microseconds
    value.it_interval = value.it_value;
    setitimer(ITIMER_REAL, &value, NULL); //sets value of an interval timer

    while(1);
}

static inline unsigned long long cc(void) {
    unsigned eax, edx;
    asm volatile ("rdtsc" 
                        : "=a"(eax), 
                        "=d"(edx)); //uses inline assembly 
    int x = (unsigned long long)eax |((unsigned long long)edx)<<32; //lower has eax, upper has edx

    printf("timestamp in ST: %d\n", x);
    return x;
}

void sigalarm_handle() {
    union sigval a;
    a.sival_int = cc(); 
    sigqueue(pid, SIGTERM, a); //queue the process
}