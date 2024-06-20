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
This is a bash script, we take input from the command line.
Input is in the for of dd-mm-yyyy.
We check whether the date is valid or not, if not then "invalid date" is printed, if yes 
then the month is printed.
We use a flag variable to do this.

Sample Input:
bash A3Q1.sh 24-06-2002

Sample Output:
     June 2002        
Su Mo Tu We Th Fr Sa  
                   1  
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30

QUESTION2:
This is a bash script, we take input from the command line.
We store the input in an array and proceed according to the input and choose one of the 5 functions.

Sample Input:
bash A3Q2.sh add 3 2 4 5

Sample Output:
14

QUESTION3;
I have divided the queston into 2 parts as per the data structures used:
BST: Binary Search Tree
AVL: Self balancing Tree
In the WSL/VirtualBox we pass the following commands to individually run the codes of the following parts:
make run1: BST
make run2: AVL
Each of these have a menu based input.
Firstly we enter the number of queries we have.
In both we have the option to add, delete, search, find minimum element and print inorderly.
If an input is wrong, it will inform the user and break out from the code.

Sample Input and Output:
BST:
8
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      1
enter element to be added:      2
1
enter element to be added:      1
1
enter element to be added:      3
1
enter element to be added:      4
5
1 2 3 4
4
1
3
enter element to search:      2
does exist
2
enter element to be deleted:      2

AVL:
9
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      1
enter element to be added:      1
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      1
enter element to be added:      2
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      1
enter element to be added:      3
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      1
enter element to be added:      4
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      5
1 2 3 4
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      2
enter element to be deleted:      2
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      5
1 3 4
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      3
enter element to search:      3
does exist
press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      4
1

QUESTION4:
In the WSL/VirtualBox we pass the "make run3" command to individually run the code of the fifth question.
We perform selection sort or bubble sort according to the user's choice.
If an input is wrong, it will inform the user and break out from the code.

Sample Input and Output:
press 1 for selections sort and 2 for bubble sort
1
5
4 3 6 5 1
1 3 4 5 6