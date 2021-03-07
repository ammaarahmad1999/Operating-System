#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
void main(int argc, char **argv)
{
	char *file1 = "task1.bash";			//NAME OF 1ST TASK FILE
	char *file2 = "task2.bash";			//NAME OF 2ND TASK FILE
	char *arg1[argc+1];					//ARGUMENT FOR TASK 1
	arg1[0]="bash";						
	arg1[1]=file1;						
	for (int i=1; i<argc-1; i++)		//COPYING ALL ARGUMENTS FROM COMMAND LINE TO ARRAY FOR TASK 1
		arg1[i+1]=argv[i];
	arg1[argc]=NULL;			
	char *arg2[4];						//ARGUMENT FOR TASK 2
	arg2[0]="bash";						
	arg2[1]=file2;
	arg2[2]=argv[argc-1];				//COPYING ARGUMENT FOR TASK 2
	argv[3]=NULL;
	if (fork())							//IF IN PARENT PROCESS EXECUTE TASK 2
	{
		execv("/bin/bash", arg2);		//EXECUTE 2ND TASK
		exit(0);
	}
	else								//IF IN CHILD PROCESS EXECUTE TASK 1
	{
		execv("/bin/bash", arg1);		//EXECUTE 1ST TASK
		exit(0);
	}
}