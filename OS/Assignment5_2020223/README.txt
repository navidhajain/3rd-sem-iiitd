Name: Navidha Jain
Roll Number: 2020223

Question 1:
We make an array of mutex object for representing forks for later use in threading.
Mutex is a mutual exclusion object that synchronizes access to a resource. It is created with a 
unique name at the start of a program.
We make an array of threads representing the philosophers.
Inside the main function we initialiase the mutex objects in the array using the init function and 
a for loop. When the mutex is initialized, it is in an unlocked state. 
Then again using a for loop we create 5 threads, one each for each of the philosophers and we pass 
in the 'philosophers' function as one of the parameters.
Later, again using a for loop we join the threads.
Inside the philosophers function we run an infinite loop inside which each philosopher  picks up a 
fork, eats and then puts down the fork.
To avoid deadlock the even numbered philosophers pick up their right forks first and then their left forks and 
the odd numbered philosophers pick up their left forks first and then their right forks. By doing this we can 
ensure that the deadlock is prevented.
To 'pick up the fork', we call the pthread_mutex_lock function which locks a mutex object, which 
identifies a mutex. If the mutex is already locked by another thread, the thread waits for the mutex to 
become available. The thread that has locked a mutex becomes its current owner and remains the owner until 
the same thread has unlocked it.
To 'put down the fork ' we call the pthread_mutex_unlock function which releases a mutex object. If one 
or more threads are waiting to lock the mutex, pthread_mutex_unlock() causes one of those threads to 
return from pthread_mutex_lock() with the mutex object acquired. If no threads are waiting for the mutex, 
the mutex unlocks with no current owner.

Question 2:
YES A DEADLOCK IS POSSIBLE as there are only 4 sauce bowls and 5 philosophers.
We make an array of mutex object for representing forks and sauce bowls for later use in threading.
Mutex is a mutual exclusion object that synchronizes access to a resource. It is created with a 
unique name at the start of a program.
We make an array of threads representing the philosophers.
Inside the main function, philosopher function we did the same things we did in Question 1.
In the pick up function now we lock the sauce bowl as well as one fork.
In the put down function now we unlock the sauce bowl as well as the fork we locked.

Question 3:
We make an array of mutex object for representing forks and sauce bowls for later use in threading.
Mutex is a mutual exclusion object that synchronizes access to a resource. It is created with a 
unique name at the start of a program.
We make an array of threads representing the philosophers.
Inside the main function, philosopher function we did the same things we did in Question 1.
To avoid deadlock the even numbered philosophers pick up their right forks first and then their left forks and 
the odd numbered philosophers pick up their left forks first and then their right forks. By doing this we can 
ensure that the deadlock is prevented.
In the pick up function now we lock the sauce bowl as well as both of the forks.
In the put down function now we unlock the sauce bowl as well as both of the forks we locked.
