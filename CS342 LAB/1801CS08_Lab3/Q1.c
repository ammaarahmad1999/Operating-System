#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	int a = atoi(argv[1]);					//FIRST NUMBER
	int b = atoi(argv[2]);					//SECOND NUMBER
	int sum, mul, div;						//VARIABLES TO STORE SUM, PRODUCT AND DIVISON VALUE
	FILE *f;								//FILE POINTER TO STORE TEMPORARY FILE
	char *filename = "temp.txt";			//TEMPORARY FILE
	pid_t PID1 = fork();					//CALLING FORK TO CREATE CHILD PROCESS
	if(PID1 < 0)							//IF CHILD PROCESS CANNOT BE CREATED PRINT ERROR
		printf("Error: Unable to create child process\n");		
	else if (PID1)							//IF WE ARE IN PARENT PROCESS
	{
		wait(NULL);							//WAITING FOR CHILD PROCESS TO COMPLETE
		pid_t PID2 = fork();				//CREATING ANOTHER CHILD PROCESS
		if(PID2 < 0)						//IF CHILD PROCESS CANNOT BE CREATED PRINT ERROR			
			printf("Error: Unable to create child process\n");
		else if (PID2)						//IF WE ARE IN PARENT PROCESS	
		{
			wait(NULL);						//WAITING FOR CHILD PROCESS IS COMPLETE
			pid_t par = getpid();			//GET PROCESS ID OF CURRENT PROCESS	
			f=fopen(filename, "r");			//OPENING FILE TO READ SUM AND PRODUCT
			fscanf(f, "%d%d",&sum,&mul);	//READING SUM AND PRODUCT
			fclose(f);						//CLOSING FILE
			remove(filename);				//REMOVING TEMPORARY FILE FROM DISK
			//printf("%d %d\n",sum,mul);
			div = mul/sum;					//CALCULATING DIVISON OF PRODUCT BY SUM
			printf("Divison by parent %lld = %d\n",(long long int)par,div);
			exit(0);						//EXIT THE PROCESS
		}
		else
		{
			pid_t ch2 = getpid();			//GET PROCESS ID OF CURRENT PROCESS	
			mul = a*b;						//MULTIPLYING NUMBERS
			printf("Multiplication by child %lld = %d\n",(long long int)ch2,mul);
			f=fopen(filename, "a+");		//OPENING FILE TO WRITE PRODUCT
			fprintf(f, "%d\n",mul);			//WRITING PRODUCT INTO A FILE
			fclose(f);						//CLOSING FILE
			exit(0);						//EXIT THE PROCESS
		}
		
	}
	else
	{
		pid_t ch1 = getpid();				//GET PROCESS ID OF CURRENT PROCESS	
		sum = a+b;							//ADDING 2 NUMBERS
		printf("Sum by child %lld = %d\n",(long long int)ch1,sum);
		f=fopen(filename, "w+");			//OPENING FILE TO WRITE SUM INTO A FILE
		fprintf(f, "%d\n",sum);				//WRITING SUM INTO FILE 
		fclose(f);							//CLOSING FILE
		exit(0);							//EXIT FROM PROCESS
	}	
}
	