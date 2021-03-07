Name: Ammaar Ahmad
Roll- 1801cs08
Lab2

In all the question,first create .sh file
then, run the command chmod u+rx filename.sh 


1)Argument 1: n(length of array)
  Argument 2 to n+1: All the n elements of array.
  Argument n+2 : Target element that I need to search.
         
  Example:
 Input command: 
     ./example1.bash 5 1 2 3 4 5 3
  Output: Search found at index 2 of searched item 3.(0 based index).


2)Argument 1: n
  
  Example:
  Input Command:
    ./example2.bash 5
   Output :   1200
  


3)Argument 1  and Argument 2 are the two numbers whose xor I ndded to find.         
 
  Example-
   Input Command: 
     ./example3.bash 87 95
   
   Output :   In Decimal Format the answer is 8
	      In Binary Format the answer is 1000
	      Execution time was 5260344 nanoseconds

	Corresponding C file: gcc example3.c ./a.out
	Execution time was 41000.000000 nanoseconds

4)Argument 1: password string within quotes    

  Example-
   Input Command: 
         ./example3.bash "Abhishek1("
                   
    Output :  Valid Password
         
          ./example3.bash "Abhishek"
    Output: Invalid Password
