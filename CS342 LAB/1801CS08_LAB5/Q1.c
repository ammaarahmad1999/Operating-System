
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 
typedef void* address_t;

void* Fun(address_t args) 		//Function to be executed as a thread
{  
	int iter = *(int* ) args;
	printf("Hello from groot %lu - I was created in iteration %d\n", pthread_self(), iter); 
	return NULL; 
} 

int main(int argc, char **argv) 
{ 
	if (argc < 2)
	{
		printf("Running command: ./Q1 Num_of_threads\n");		//Incorrect Input
		exit(0);
	}
	int n = atoi(argv[1]);							//No. of threads
	pthread_t thread_id[n];
	int arg[n];
	for(int i=1; i<=n; i++)		
	{
	        arg[i] = i;
		pthread_create(&thread_id[i], NULL, Fun, (address_t) &arg[i] ); 	//Creation of thread
        	printf("I am groot %lu. Created new groot(%lu) in iteration %d\n", pthread_self(), thread_id[i], i);
        	if(i%5 == 0)
	            sleep(1);							//Sleep after 5 creation
	} 
	exit(0); 
}
