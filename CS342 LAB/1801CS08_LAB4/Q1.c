#include <stdlib.h> 
#include<stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	// Fork returns process id 
	// in parent process 
	pid_t child_pid = fork(); 
	// Parent process 
	if (child_pid > 0)
    	{
        	printf("Parent process\n");
		sleep(5); 
    	}
	// Child process 
	else
    	{	
        	printf("child turned zombie ");
		exit(0); 
    	}
	return 0; 
} 
