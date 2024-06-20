Name: Navidha Jain
Roll Number: 2020223

USING LINUX 5.14.6

We first run the vim ..build/linux-5.14.6/arch/x86/entry/syscalls/syscall-64.tbl command and add the syscall to be added which is 
kernel_2d_memcpy. Then we run vim ../build/linux-5.14.6/kernel/sys.c to write the functionality of the function.
In the function we simply run 2 sets of 2 for loops, one to get the matrix from the source and store it in a temporary 2d array and
the other to copy the 2d array from temp array to the destination.
We use __copy_from_user and __copy_to_user kernel functions to achieve the same. These take 3 arguments, the "to" in kernel space, 
the "from" in user space and number of bites which are required to copy. We use the for loops to copy the matrix element by element.

We then compile our kernel again just like we did in the Refresher module.
Then we test our system call with a test file.