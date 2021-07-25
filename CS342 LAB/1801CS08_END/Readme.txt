NAME: AMMAAR AHMAD
ROLL: 1801CS08

Question 1a:

Compile: gcc Q1a.c -o Q1a
Execute: ./Q1a

Example 1:
Enter the number of resources: 9
Enter the requirement for each process: 4
Maximum Number of process such that no deadlock occurs = 2
Example 2:
Enter the number of resources: 10
Enter the requirement for each process: 4
Maximum Number of process such that no deadlock occurs = 3
Example 3:
Enter the number of resources: 45
Enter the requirement for each process: 12 
Maximum Number of process such that no deadlock occurs = 4

Question 1b:

Compile: gcc Q1b.c -o Q1b
Execute: ./Q1b

Example 1:
Enter the number of process: 5
Enter the requirement for each process:
3 7 1 6 8
Maximum Number of resources such that deadlock  can occur = 20
Minimum Number of resources such that it is deadlock free = 21
Example 2:
Enter the number of process: 8
Enter the requirement for each process:
3 4 4 6 9 10 3 5
Maximum Number of resources such that deadlock  can occur = 36
Minimum Number of resources such that it is deadlock free = 37
Example 3:
Enter the number of process: 3
Enter the requirement for each process:
4 5 10
Maximum Number of resources such that deadlock  can occur = 16
Minimum Number of resources such that it is deadlock free = 17






Question 2:

Compile: g++ Q2.cpp -o Q2
Execute: ./Q2

Example:
2
6 50 
1 2 4 1 5 3 1 1 5 4 1 6 4 6 7 7 8 1 1 5 3 1 6 1 1 2 4 5 1 5 6 7 3 4 9 9 9 8 8 3 2 4 5 6 7 1 1 3 4 5
My Algorithm Page faults
1 2 4 5 3 6 7 8 3 2 4 7 3 9 8 2 6 7 3 
LRU Page faults
1 2 4 5 3 6 7 8 3 2 4 7 3 9 8 2 5 6 7 1 3 
FIFO Page faults
1 2 4 5 3 6 7 8 1 2 4 5 6 7 3 9 8 2 4 5 6 7 1 3 
0.000309	0.0001	7.1e-05
5 100
1 2 4 1 5 3 1 1 5 4 1 6 4 6 7 7 8 1 1 5 3 1 6 1 1 2 4 5 1 5 6 7 3 4 9 9 9 8 8 3 2 4 5 6 7 1 1 3 4 5 2 8 10 10 2 4 5 2 1 4 5 11 10 4 4 5 12 12 7 7 6 6 3 5 4 8 8 2 4 5 5 5 6 7 9 1 3 4 1 4 5 6 8 11 12 10 12 12 12 9 3 5 7
My Algorithm Page faults
1 2 4 5 3 6 7 8 5 3 6 2 4 5 7 3 4 9 8 3 2 6 7 3 2 8 10 2 11 10 12 7 6 3 8 2 6 7 9 1 3 4 5 6 8 11 12 10 12 9 
LRU Page faults
1 2 4 5 3 6 7 8 5 3 6 2 4 5 7 3 4 9 8 2 5 6 7 1 3 4 5 2 8 10 1 11 10 12 7 6 3 4 8 2 6 7 9 1 3 4 5 6 8 11 12 10 9 
FIFO Page faults
1 2 4 5 3 6 7 8 1 5 3 6 2 4 1 5 7 3 9 8 2 4 5 6 7 1 3 4 5 2 8 10 1 4 5 11 12 7 6 3 5 4 8 2 6 7 9 1 3 4 5 6 8 11 12 10 9 
0.000559	0.000183	0.000135


Conclusion: In both the cases No. of page faults in my algorithm is less which is significant improvement. Though required time is high due to overhead but when in real time accessing of pages this will be a big improvement

Motivation: This algorithm is based on statistical analysis that most of pages are accessed in order of their mean. That is most of pages in a particular interval will be accessed about Mean = m number of times with standard deviation of s. Here we don't have statistical data so we can't claim that but as in most cases of world. Everything in large dataset have some resemblence to Normal distribution. So to use that fact.

Frequency = (mean - sd, mean+sd) - Highest Priority (removed at last)
Frequency = (less than mean-sd) : Middle Priority (removed second)
Frequency = (greater than mean+sd) : Lowest Priority (removed at first)





Question 3:

Compile: g++ Q3.cpp -o Q3
Execute: ./Q3

Example:
5
10 
7
A 0 18
B 0 12
C 0 7
D 0 11
E 0 28
F 7 18
G 16 12

Enter the time instance for status
53
A	0	18	0	43	C
B	0	12	0	24	C
C	0	7	5	22	C
D	0	11	10	30	C
E	0	28	10		E
F	7	18	20	51	C
G	16	12	25	52	C




Question 4:

Compile: gcc Q4.c -o Q4
Execute: ./Q4

Example 1:
Enter the head position: 98
Enter the number of cylinders: 200
Enter the number of requests: 8
98 183 37 122 14 124 65 67
Head Movement
98---->67---->65---->37---->14---->122---->124---->183
Total Head Movement: 253
Seek Time: 1265

Example 2:
Enter the head position: 98
Enter the number of cylinders: 200
Enter the number of requests: 5
23 89 132 42 187
Head Movement
98---->89---->42---->23---->132---->187
Total Head Movement: 239
Seek Time: 1195
