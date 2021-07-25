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
    }
	// 1st Child process 
	else
    {	
    	sleep(10);			//Child process goes to sleep for 10 seconds
        printf("1st Child turned orphan\n");
        pid_t child_pid = fork(); 
        // 1st Child as parent
		if(child_pid > 0)
		{
			printf("1st Child going in sleeping mode\n");
			sleep(5);		//Parent process goes to sleep for 5 seconds
			printf("1st Child executing....\n");
		}
		// 2nd Child (child of 1st child)
		else
		{
			printf("2nd child turned zombie\n");
			exit(0);
		}
    }
	return 0; 
} 