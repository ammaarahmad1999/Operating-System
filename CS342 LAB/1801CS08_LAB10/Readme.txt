Name: Ammaar Ahmad
Roll No: 1801CS08

NOTE: Before running any of these 3 program, make sure there is a pages.txt file with the required input.


Problem 1

Compilation:  g++ Q1_1.cpp -o Q1_1
Execution Syntax: ./Q1_1

Example:

-------------------------------------------
TRY 1: 

FIFO:
4 7 6 1 7 6 1 2 7 2 
Frame content at each time step t
F1	F2	F3	
X	X	X	at t = 0
4	X	X	at t = 1
4	7	X	at t = 2
4	7	6	at t = 3
1	7	6	at t = 4
1	7	6	at t = 5
1	7	6	at t = 6
1	7	6	at t = 7
1	2	6	at t = 8
1	2	7	at t = 9
1	2	7	at t = 10

#Page Faults: 6
-------------------------------------------
-------------------------------------------
TRY 2: 

FIFO:
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5 
Frame content at each time step t
F1	F2	F3	F4	
X	X	X	X	at t = 0
1	X	X	X	at t = 1
1	2	X	X	at t = 2
1	2	3	X	at t = 3
1	2	3	4	at t = 4
1	2	3	4	at t = 5
7	2	3	4	at t = 6
7	5	3	4	at t = 7
7	5	1	4	at t = 8
7	5	1	4	at t = 9
7	5	1	6	at t = 10
4	5	1	6	at t = 11
4	7	1	6	at t = 12
4	7	2	6	at t = 13
4	7	2	1	at t = 14
4	7	2	1	at t = 15
5	7	2	1	at t = 16

#Page Faults: 13
-------------------------------------------





Problem 2

Compilation: g++ Q1_2.cpp -o Q1_2
Execution Syntax: ./Q1_2

Example:

-------------------------------------------
TRY 1: 

LRU:
4 7 6 1 7 6 1 2 7 2 
Frame content at each time step t
F1	F2	F3	
X	X	X	at t = 0
4	X	X	at t = 1
4	7	X	at t = 2
4	7	6	at t = 3
1	7	6	at t = 4
1	7	6	at t = 5
1	7	6	at t = 6
1	7	6	at t = 7
1	2	6	at t = 8
1	2	7	at t = 9
1	2	7	at t = 10

#Page Faults: 6
-------------------------------------------
-------------------------------------------
TRY 2: 

LRU:
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5 
Frame content at each time step t
F1	F2	F3	F4	
X	X	X	X	at t = 0
1	X	X	X	at t = 1
1	2	X	X	at t = 2
1	2	3	X	at t = 3
1	2	3	4	at t = 4
1	2	3	4	at t = 5
7	2	3	4	at t = 6
7	2	5	4	at t = 7
7	2	5	1	at t = 8
7	2	5	1	at t = 9
7	6	5	1	at t = 10
4	6	5	1	at t = 11
4	6	7	1	at t = 12
4	6	7	2	at t = 13
4	1	7	2	at t = 14
4	1	7	2	at t = 15
5	1	7	2	at t = 16

#Page Faults: 13
-------------------------------------------




Problem 3


Compilation: g++ Q1_3.cpp -o Q1_3
Execution Syntax: ./Q1_3

Example:

-------------------------------------------
TRY 1: 

Optimal:
4 7 6 1 7 6 1 2 7 2 
Frame content at each time step t
F1	F2	F3	
X	X	X	at t = 0
4	X	X	at t = 1
4	7	X	at t = 2
4	7	6	at t = 3
1	7	6	at t = 4
1	7	6	at t = 5
1	7	6	at t = 6
1	7	6	at t = 7
2	7	6	at t = 8
2	7	6	at t = 9
2	7	6	at t = 10

#Page Faults: 5
-------------------------------------------
-------------------------------------------
TRY 2: 

Optimal:
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5 
Frame content at each time step t
F1	F2	F3	F4	
X	X	X	X	at t = 0
1	X	X	X	at t = 1
1	2	X	X	at t = 2
1	2	3	X	at t = 3
1	2	3	4	at t = 4
1	2	3	4	at t = 5
1	2	7	4	at t = 6
1	5	7	4	at t = 7
1	5	7	4	at t = 8
1	5	7	4	at t = 9
1	6	7	4	at t = 10
1	6	7	4	at t = 11
1	6	7	4	at t = 12
1	2	7	4	at t = 13
1	2	7	4	at t = 14
1	2	7	4	at t = 15
5	2	7	4	at t = 16

#Page Faults: 9
-------------------------------------------
