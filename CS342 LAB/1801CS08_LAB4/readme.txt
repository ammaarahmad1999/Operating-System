Name: AMMAAR AHMAD
Roll: 1801CS08
Assignment 4

Question 1:

Commands:
1. gcc Q1.c -o Q1
2. ./Q1&

Show that the child process becomes a zombie process:

Output:

[1] 5840
ammaar@ammaar-Aspire-A715-75G:~/Desktop/1801CS08_LAB4$ Parent process
child turned zombie pstree -p 5840
Q1(5840)───Q1(5841)
ammaar@ammaar-Aspire-A715-75G:~/Desktop/1801CS08_LAB4$ ps aux | grep 5841
ammaar      5841  0.0  0.0      0     0 pts/0    Z    07:25   0:00 [Q1] <defunct>
ammaar      5846  0.0  0.0   8908   728 pts/0    S+   07:25   0:00 grep --color=auto 5841

Hence Z in second last line shows that proces becomes a zombie process




Question 2:

Commands:
1. gcc Q2.c -o Q2
2. ./Q2

Output:
in parent process
ammaar@ammaar-Aspire-A715-75G:~/Desktop/1801CS08_LAB4$ in child process

What is the significance of the orphan process?

Ans: Orphan process are still running even though their parent process has terminated or finished.




Question 3:

Commands:
1. gcc Q3.c -o Q3
2. ./Q3

Output:
In parent process
Enter length of Fibonacci array : 10
In child process
Fibonacci series upto n=10 is
0 1 1 2 3 5 8 13 21 34 55 
The prime numbers in this series are
index = 3, number= 2
index = 4, number= 3
index = 5, number= 5
index = 7, number= 13




Question 4:

Commands:

1. gcc Q4.c -o Q4
2. ./Q4 file1.txt file2.txt

Output:
First child process : 7941 to copy files.
Parent of 1st child process is : 7940.

Second child process : 7942 to display content of file2.
Parent of 2nd child process is : 7940.

The content of file2 are: 
21 3 23 4 5 363 434 54 65 757 676 76 

Third child process : 7940 to display content sorted of file2 in reverse.
Parent of 3rd child process is : 7301 

The file2 in desending sorted order is :
757 676 434 363 76 65 54 23 21 5 4 3 


