Name: Ammaar Ahmad
Roll- 1801cs08
Lab3

In all the question,first create .sh file
then, run the command chmod u+rx filename.sh 

1. Argument 1: 1st number
   Argument 2: 2nd number
   Example:
   gcc Q1.c -o Q1
   ./Q1 1st_number 2nd_number
   Output: Sum followed by Product by Child processes
   	   Product/Sum = Divisob by Parent process
   	   2 Child processes were created	
   	   
   	   
   	   
2. No Arguments
   How to run
   Example:
   gcc Q2.c -o Q2
   ./Q2
   Output: Hello Hello Hello Hello Hello
   4 child processes and 1 Parent process each printing Hello
   
   
   
3. Argument 1: number of elements in array in task 1
   Argument 2 to n+1: All the n elements of array.
   Argument n+2 : Target element that I need to search.
   Argument n+3 : Input Number for task 2       
   Running command
   gcc Q3.c -o Q3
   ./Q3 2 3 4 4 6
   Output: 	Search found at index 1 of searched item 4 (Task1 Output)
		7200 (Task2 Output)
   To execute both task 1 child process is created. Child process is executing task1 and Parent process is executing task2

   Running Task 1 independently
   ./task1.bash 5 1 2 3 4 5 3
   5 - Number of elements, 1,2,3,4,5 are elements and 3=S -> element to be searched
   
   Running Task 2 independently
   ./task2.bash input_number
   
   Obseervation: Task2 takes longer time irrespective of execution in parent or child process
