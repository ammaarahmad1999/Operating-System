#include <stdlib.h> 
#include<stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <pthread.h>
int A[2][2]; int B[2][2]; int C[2][2]; 			//Matrix
void* thread_1(void *param)						//1st Thread 
{
	int D[2][2]; int E[2][2];
	for (int i=0; i<2; i++)						//Addition of A,B,C
	{
		for(int j=0; j<2; j++)
		{
			D[i][j]=A[i][j]+B[i][j];
			D[i][j]=D[i][j]+C[i][j];
		}
	}
	for (int i=0; i<2; i++)						//Addition of A,B,C
	{
		for(int j=0; j<2; j++)
		{
			E[i][j]=B[i][j]+C[i][j];
			E[i][j]=A[i][j]+E[i][j];
		}	
	}
	int ch = 1;
	for (int i=0; i<2; i++)						//Addition of A,B,C
	{
		for (int j=0; j<2; j++)
		{
			ch = ch & (D[i][j]==E[i][j]);
		}
	}
	if(ch)
		printf("It is Associative\n");			//Associative
	else
		printf("It is not Associative\n");
	pthread_exit(NULL);
}
void* thread_2(void *param)						//2nd Thread
{
	int D[2][2]; int E[2][2];
	for (int i=0; i<2; i++)						//Addition of A,B
	{
		for(int j=0; j<2; j++)
		{
			D[i][j]=A[i][j]+B[i][j];
			E[i][j]=B[i][j]+A[i][j];
		}
	}
	int ch = 1;
	for (int i=0; i<2; i++)						//Addition of A,B
	{
		for (int j=0; j<2; j++)
		{
			ch = ch & (D[i][j]==E[i][j]);
		}
	}
	if(ch)
		printf("It is Commutative\n");			//Commutative
	else
		printf("It is not Commutative\n");
	pthread_exit(NULL);
}
void* thread_3(void *param)						//3rd THread
{
	int D[2][2]; int E[2][2];
	int I[2][2]={{0,0},{0,0}};
	for (int i=0; i<2; i++)						//Addition of A,I
	{
		for(int j=0; j<2; j++)
		{
			D[i][j]=A[i][j]+I[i][j];
			E[i][j]=I[i][j]+A[i][j];
		}
	}
	int ch = 1;
	for (int i=0; i<2; i++)						//Addition of A,I
	{
		for (int j=0; j<2; j++)
		{
			ch = ch & (D[i][j]==E[i][j]);
			ch = ch & (D[i][j]==A[i][j]);
		}
	}
	if(ch)
	{
		printf("Additive Identity Exists\n");	//Additive Identity
		for (int i=0; i<2; i++)
		{
			for (int j=0; j<2; j++)
			{
				printf("%d ",I[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("Additive Identity does not exists\n");
	pthread_exit(NULL);
}
void* thread_4(void *param)						//4th Thread
{
	int D[2][2]; int E[2][2];
	int R[2][2];
	for (int i=0; i<2; i++)						//Addition of A,R
	{
		for(int j=0; j<2; j++)
		{
			R[i][j]=-A[i][j];
			D[i][j]=A[i][j]+R[i][j];
			E[i][j]=R[i][j]+A[i][j];
		}
	}
	int ch = 1;
	for (int i=0; i<2; i++)						//Addition of A,R
	{
		for (int j=0; j<2; j++)
		{
			ch = ch & (D[i][j]==0);
			ch = ch & (E[i][j]==0);
		}
	}
	if(ch)
	{
		printf("Additive Inverse exists\n");	//Inverse Matrix
		for (int i=0; i<2; i++)
		{
			for (int j=0; j<2; j++)
			{
				printf("%d ",R[i][j]);
			}
			printf("\n");
		}
	}	
	else
		printf("Additive Inverse does not exists\n");		
	pthread_exit(NULL);
}
int main()
{
	pthread_t tid[4];					//4 Threads
	printf("Enter the 1st 2*2 matrix values\n");
	scanf("%d %d",&A[0][0], &A[0][1]);
	scanf("%d %d",&A[1][0], &A[1][1]);
	printf("Enter the 2nd 2*2 matrix values\n");
	scanf("%d %d",&B[0][0], &B[0][1]);
	scanf("%d %d",&B[1][0], &B[1][1]);
	printf("Enter the 3rd 2*2 matrix values\n");
	scanf("%d %d",&C[0][0], &C[0][1]);
	scanf("%d %d",&C[1][0], &C[1][1]);
	pthread_create(&tid[0],NULL,thread_1,NULL);			//Creating 1st Thread
	pthread_create(&tid[1],NULL,thread_2,NULL);			//Creating 2nd Thread
	pthread_create(&tid[2],NULL,thread_3,NULL);			//Creating 3rd Thread
	pthread_create(&tid[3],NULL,thread_4,NULL);			//Creating 4th Thread
	pthread_exit(NULL);
	return 0;
}
