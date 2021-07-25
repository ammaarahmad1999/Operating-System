Name: AMMAAR AHMAD
Roll: 1801CS08
Assignment 4

Question 1:

Commands:
1. gcc Q1.c -o Q1
2. ./Q1


Output:

Parent process
1st Child turned orphan
1st Child going in sleeping mode
2nd child turned zombie
1st Child executing....



Question 2a:

Commands:
1. gcc Q2a.c -o Q2a
2. ./Q2a <any_number> 10

Output:

Final sum of the series upto 10 terms is: 0.645635

Question 2b:

Commands:
1. gcc Q2b.c -o Q2b
2. ./Q2b

Output:

Enter the 1st 2*2 matrix values
4 4
4 4
Enter the 2nd 2*2 matrix values
1 11
66 5 
Enter the 3rd 2*2 matrix values
7 8
7 8
It is Associative
It is Commutative
Additive Identity Exists
0 0 
0 0 
Additive Inverse exists
-4 -4 
-4 -4 


Question 3:

Commands:
1. g++ Q3.cpp -o Q3
2. ./Q3

5
4 2 6
5 1 3
5 3 1
1 4 2
3 5 4
Average Waiting Time: 3.00
Average Turnaround Time: 6.20
Order of Completion of process:
P4 P5 P3 P1 P2 

Question 4:

Note : Do not run this file on same directory. This might change other files and codes. Create a directory with other files.
chmod u+rx q4.sh
./q4.sh filename k
Example Input:
./q4.sh ex1.txt 2
   
Output:
All words with frequency >=k in ex1.txt will get replaced with MASK amd the word in all other files of that directory.
      
Also print list of ‘K’ file names of the directory (in descending order of no. of “MASKED” word), which contains at least K/2 “MASKED” words.

