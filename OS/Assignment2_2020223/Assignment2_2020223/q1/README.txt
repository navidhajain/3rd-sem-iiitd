Name: Navidha Jain
Roll Number: 2020223

main.c:
A signal handler is a function which is called by the target environment when the 
corresponding signal occurs. Here that signal is SIGTERM. 
Every process on the system has a unique process ID number, 
known as the pid which is simply an integer.
We call the fork system call to create a new process and store the value in the pid 
variable created.
3 values are possible:
Negative Value: creation of a child process was unsuccessful. Here an error message will be printed in this case.
Zero: Returned to the newly created child process (here, S1).
Positive value: Returned to parent or caller. The value contains process ID 
of newly created child process.

The body of process S1, registers a signal handler for SIGTERM.
The sigaction is used to change the action taken by a process on receipt of 
a specific signal. We make signal_reg to be able to use the actions provided by it. 

We then call memset which is used to fill a block of memory, parameters of memset are starting 
address of memory to be filled, the value which is to be filled and the size in byte to be filled.
sa_sigaction specifies the signal-handling function for signum. The sigaction function receives the number of the signal 
as its first argument, a pointer to a siginfo_t as its second argument and a pointer to a ucontext_t (cast to void *) 
as its third argument.

Now in the parent process we fork again to create the process ST as the child process
We call the system call execv(path, argv) to go to e2 file which contains the functionality of ST. 
The function call causes the current process to abandon the program that it is running and start running the program in file 
path which is given as one of the arguments in the caller.
In this parent process whose child process is ST, we fork once again to create the process SR as the child process.
We again call execv(path, argv) to go to the e1 file which has the functionality of SR.

----------------------------------------------------------------------------------------

e1.c:
We convert the 0th index of the argvs into an integer which is ps1. using atoi function, we received this via the execv call in the main filled.
We use itimerval which contains system calls which provide access to interval timers, these timers that will expire at some point in the future.
When it_value of itimerval is nonzero, it is used as the initial value to establish the timer with, that is, the time to the next timer expiration. 
If it_value is zero, the timer is immediately disabled. "tv_sec" and "tv_usec" are significant in determining the duration of a timer.
We use setitimer() sets the value of an interval timer. An interval timer is a timer which sends a signal after each repetition (interval) of time.
The first argument indicates what kind of time is being controlled(here, we use ITIMER_REAL which marks real clock time.).

The SIGLARM handler reads a random number from the CPU using the the RDRAND instruction (using inline assembly) using sig_val and sigqueue().
sigqueue() queues a signal and data to a process. 
The "asm" keyword allows you to embed assembler instructions within C code. "volatile" is a quanlifier. 
Inside the brackets we have the assembly instruction we wish to use.

----------------------------------------------------------------------------------------

e2.c:
We convert the 0th index of the argvs into an integer which is ps1. using atoi function, we received this via the execv call in the main filled.
We use itimerval which contains system calls which provide access to interval timers, these timers that will expire at some point in the future.
When it_value of itimerval is nonzero, it is used as the initial value to establish the timer with, that is, the time to the next timer expiration. 
If it_value is zero, the timer is immediately disabled. "tv_sec" and "tv_usec" are significant in determining the duration of a timer.
We use setitimer() sets the value of an interval timer. An interval timer is a timer which sends a signal after each repetition (interval) of time.
The first argument indicates what kind of time is being controlled(here, we use ITIMER_REAL which marks real clock time.).

The SIGLARM handler reads a CPU timestamp counter using the the rdtsc(read time stamp counter) instruction (using inline assembly) using sig_val and sigqueue().
sigqueue() queues a signal and data to a process. 
The "asm" keyword allows you to embed assembler instructions within C code. "volatile" is a quanlifier. 
Inside the brackets we have the assembly instruction we wish to use.

Since the rdtsc instruction returns it's results in edx and eax, instead of a straight 64-bit register on a 64-bit machine, the 2nd instruction shifts 
the rdx register to the left 32 bits so that edx will be on the upper 32 bits instead of the lower 32 bits.
"=a" (eax) will move the contents of eax into variable eax, i.e. into the lower 32 bits of it, so in total you have edx (higher 32 bits) and eax 
(lower 32 bits).











