#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t p = getpid();		//PID of the parent process
	pid_t c1 = fork();		//Creating a child process	
	pid_t c2 = fork();		//Craeting a child process	
	if (p == getpid())		//Checking if we are in child process
		fork();				//Creating a child process
	printf("Hello ");		//Print Hello in each process
}
	
