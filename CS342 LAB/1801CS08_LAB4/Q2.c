#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	// Create a child process	
	if(fork())	//Parent Process
		printf("in parent process\n");
	else		//Child Process
	{
		sleep(5); 
		printf("in child process\n"); 
	}
	return 0; 
} 
