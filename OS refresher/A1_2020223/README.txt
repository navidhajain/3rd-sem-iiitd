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
We have to take command line input so to run the file we give the name of the input file and the output file as arguments in 
the command.
to execute the file.
In the code, the main function takes the arguments we have given and proceeds with the code. 
We open both of the files, input in read mode and outpput file in write mode, and copy the input file to the output file via 
a while loop.
The input already has some lines written, after we run the code we can see that the same lines are copies in the
output file.
In the WSL/VirtualBox we pass the "make run1" command to individually run the code of the first question.

QUESTION3:
In the WSL/VirtualBox we pass the "make run2" command to individually run the code of the third question.
We input the numbers and theyre swapped using a temp variable.
The numbers are swapped and printed.
Then we enter the length of the array and the elements of the 2 array.
Theyre swapped and are printed.

Sample Input:
3 2
4
1 2 3 4
8 7 6 5

Sample Output:
after swap first variable has: 2
after swap second variable has: 3
array 1: 8 7 6 5
array 2: 1 2 3 4

QUESTION4:
In the WSL/VirtualBox we pass the "make run3" command to individually run the code of the fourth question.
Then we input the string we want to reverse. For the length function we maintain a count variable which is 
incremented till we reach the null character.
Then using a for loop we reverse the string and the string is printed.

Sample Input:
hello im navidha jain

Sample Output:
niaj ahdivan mi olleh

QUESTION5:
In the WSL/VirtualBox we pass the "make run4" command to individually run the code of the fifth question.
We input the number of elements we wish to enter and the elements as well.
We use unsigned int to as we are given the elements will be unsigned integers.
While giving the input we assume to input the following numbers as well:
4294967290, 4294967295, 10400 as required to.
Then we input the target element ie, the element we want to search.
We use Bubble sort to sort the array and apply binary search.
Overflow is handled by using the formula: mid = start + (end-start)/2 as the end index will always be in 
range as told to us.
Either true or false is printed according to the input.

Sample Input:
5
1 3 4294967290 4294967295 10400
2

Sample Output:
false