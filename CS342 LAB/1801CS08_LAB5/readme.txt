Name: AMMAAR AHMAD
Roll: 1801CS08
Assignment 4

Question 1:

Commands:
1. gcc Q1.c -o Q1 -lm -pthread
2. ./Q1 32(Any Number <=50)

Comment: The thread are created and executed at random



Question 2:

Commands:
1. gcc Q2.c -o Q2 -lm -pthread
2. ./Q2

Output:
Thread ID: 140042870220544, Static variable: 6, Global variable: 51, Local Non static variable 6
Thread ID: 140042845042432, Static variable: 9, Global variable: 54, Local Non static variable 6
Thread ID: 140042828257024, Static variable: 11, Global variable: 56, Local Non static variable 6
Thread ID: 140042861827840, Static variable: 7, Global variable: 52, Local Non static variable 6
Thread ID: 140042836649728, Static variable: 10, Global variable: 55, Local Non static variable 6
Thread ID: 140042853435136, Static variable: 8, Global variable: 53, Local Non static variable 6
Thread ID: 140042811361024, Static variable: 13, Global variable: 58, Local Non static variable 6
Thread ID: 140042819864320, Static variable: 12, Global variable: 57, Local Non static variable 6
Thread ID: 140042802968320, Static variable: 14, Global variable: 59, Local Non static variable 6
Thread ID: 140042794575616, Static variable: 15, Global variable: 60, Local Non static variable 6

Comment: There is a race condition between threads. Thread which uses CPU first may not use I/O first so order of output is jumbled
	 Local Non static variable are exclusive for each thread hence equal for all threads



Question 3:

Commands:
1. gcc Q3.c -o Q3 -lm -pthread
2. ./Q3

