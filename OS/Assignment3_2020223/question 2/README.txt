Name: Navidha Jain
Roll number: 2020223

Sockets:
p1:
We use the socket address family for ipc. 
The socket() function shall create an unbound socket in a communications domain, and return a file descriptor that can be used in later function calls that operate on sockets.
The socket() function takes the following arguments:
domain
Specifies the communications domain in which a socket is to be created.
type
Specifies the type of socket to be created.
protocol
Specifies a particular protocol to be used with the socket. Specifying a protocol of 0 causes socket() to use an unspecified default protocol appropriate for the requested socket type.

We use the bind function and lisetn function to bind the socket and check for a pending connection.
We make a array of strings amd fill that with random strings generated using the rand function and a characte array of alphabets ordered.

We then run a while loop which first accepts the connections and then it send the strings one by one to p2 program
using the send() function.

Then we read the highest id of the strings and print it.

p2:
We first establish the connection using all the fucntions we used in p1.
We also use connect() for the initialisation of the connection.
We get the max id using a basic while loop in which we read the strings using the file descriptor.

After getting the max id, we send it to p1 and p1 prints it.

FIFO:
p1:
We first make the array of strings which are randomly generated using the rand() function.
Then we open fifo file using mkfifo().
We open it in the write only mode. Using a while loop we write to the file.
We open the file in read only mode after close it earlier and check for errors.
We receive the highest index using read and wee print it.
We close the file at the end.

p2:
We open fifo in read only mode. We run a while loop to print the received strings and to get the index
of the string.
We get the max and open the file in a write only mode.We write to the fifo and close it and open it for the next iteration.

Queue:
p1:
We make a struct of message buffer that will store the type of the message and
the message itself.
We make the keys and set the ids of the keys to use them.
The msgget() gives a System message queue identifier associated with the value of the key argument that we use later .
We fill the array of strings using the rand() function.

We run the while loop, in each iteration we copy our string to the char array of our struct  which is used to send the message using msgsnd().
We receive the message from p2 using msgrcv() that is the highest id and we print it.
The msgctl() function allows us to control the message queue specified by the msqid parameter.

p2:
We make a struct of message buffer that will store the type of the message and
the message itself.
We make the keys and set the ids of the keys to use them.

We receive the message from p1 using msgrcv() and print out what we have received.
We then get the id of the message and send it back to p1 using msgsnd.
The msgctl() function allows us to control the message queue specified by the msqid parameter.




