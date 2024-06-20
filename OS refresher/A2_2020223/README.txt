Name: Navidha Jain
Roll number: 2020223

In Linux, the gcc stands for GNU Compiler Collection. 
It is a compiler system for the various programming languages. 
It is mainly used to compile the C programs. 
It takes the name of the source program as a necessary argument, 
rest arguments are optional such as debugging, warning, object file, and linking libraries.

a.out is an executable file.
While ./a.out is a terminal command to execute this exectable file.

QUESTION1:
PART A:
In the WSL/VirtualBox we pass the "make run1" command to individually run the code of the first question.
Then we enter the number of rows we want and the number of columsn in each respective row.
We use malloc() to create a block of memory for this process.
The matrix is printed.

PART B:
We enter the new number of columns in each respective row.
We use realloc() for this process.
The new matrix is printed.

Sample Input:
6
7 4 6 3 7 2
6 5 4 3 2 1

Sample Output(random elements in the matrix):
1 7 4 0 9 4 8 
8 2 4 5       
5 1 7 1 1 5   
2 7 6         
1 4 2 3 2 2 1 
6 8

5 7 6 1 8 9 
2 7 9 5 4
3 1 2 3
3 4 1
1 3
8

QUESTION2:
I have divided this question into 4 parts as per the data structures used:
Singly Linked List, Doubly Linked List, Stack, Queue.
In the WSL/VirtualBox we pass the following commands to individually run the codes of the following parts:
make run2: Singly Linked List
make run3: Doubly Linked List
make run4: Stack
make run5: Queue
Each of these have a menu based input.
Firstly we enter the number of queries we have.
In both Singly and Doubly Linked Lists, we have the option to add, search and print.
In both Stack and Queue we have the option to add, delete or print.
If an input is wrong, it will inform the user and break out from the code.

Sample Input and Output:
For Singly Linked List:
5
press 1 to add, 2 to search, 3 to print1
enter roll no 223
enter year of joining2020
enter branchcsam
enter name navidha
2
enter roll number222
does not exist
2
enter roll number223
exists
1
enter roll no 222
enter year of joining2020
enter branchcse
enter name jain
3
Roll number and branch of joining: 223,  2020
Name: navidha
Branch: csam
Roll number and branch of joining: 222,  2020
Name: jain
Branch: cse

Doubly Linked List:
5
press 1 to add, 2 to search, 3 to print1
enter roll no 223
enter year of joining20202
enter branchcsam
enter name navidha
2
enter roll number222
does not exist2
enter roll number223
exists1
enter roll no 222
enter year of joining2020
enter branchcse
enter name jain
3
Roll number and branch of joining: 223,  20202
Name: navidha
Branch: csam
Roll number and branch of joining: 222,  2020
Name: jain
Branch: cse

Stack:
5
press 1 to add, 2 to delete, 3 to print1
enter roll no 223
enter year of joining2020
enter branchcsam
enter name navidha
3
223 2020 navidha
 csam
1
enter roll no 222
enter year of joining2021
enter branchcse
enter name jain
2
3
223 2020 navidha
 csam

Queue:
 5
press 1 to add, 2 to delete, 3 to print1
enter roll no 223
enter year of joining2020 
enter branchcsam
enter name navidha
1
enter roll no 222
enter year of joining202
enter branchcse
enter name jain
2
3
222 202 jain
 cse
3
222 202 jain
 cse

QUESTION3:
In the WSL/VirtualBox we pass the "make run6" command to individually run the code of the third question.
We Create an array of (void * -type) pointers of length 5. Each of these pointers point to individual 
functions that perform operations: addition, subtraction, division, multiplication, exponentiation. 
This is also has a menu based input.
If an input is wrong, it will inform the user and break out from the code.

Sample Input and Output:
number of queries: 5
press 1 to add, 2 to subtract, 3 to multiply, 4 to divide, 5 for exponentiation:  1
enter 2 values: 2 3
Sum: 5
press 1 to add, 2 to subtract, 3 to multiply, 4 to divide, 5 for exponentiation:  2
enter 2 values: 3 2
Difference: 1
press 1 to add, 2 to subtract, 3 to multiply, 4 to divide, 5 for exponentiation:  3
enter 2 values: 4 4
Product: 16
press 1 to add, 2 to subtract, 3 to multiply, 4 to divide, 5 for exponentiation:  4
enter 2 values: 4 2
Quotient: 2.000000
press 1 to add, 2 to subtract, 3 to multiply, 4 to divide, 5 for exponentiation:  5
enter 2 values: 4 5
Value of a raised to the power b is  : 1024

QUESTION5:
In the WSL/VirtualBox we pass the "make run7" command to individually run the code of the fifth question.
We perform selection sort or bubble sort according to the user's choice.

Sample Input and Output:
press 1 for selections sort and 2 for bubble sort
1
5
4 3 6 5 1
1 3 4 5 6