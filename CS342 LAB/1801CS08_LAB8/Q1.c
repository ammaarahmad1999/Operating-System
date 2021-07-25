#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter=0;
pthread_mutex_t lock;

void f()			//Dummy Function
{
	sleep(2);
}
void* thread_function(void* arg)		//Thread Function
{
	while(1)
	{
        	if(pthread_mutex_trylock(&lock) !=0)		//Trying to acquire Mutex Lock if available
        	{
            		printf("pthread2 cannot access function f() as lock acquired by pthread1\n",);
            		sleep(3);				//If Mutex not available go to sleep
        	}
        	else						//If Mutex is acquired
        	{
        		counter += 1;
            		printf("lock acquired by pthread%d\n",counter); 
            		printf("pthread%d is accessing function f()\n",counter);	
            		f();
            		printf("lock released by pthread%d\n",counter); 
            		pthread_mutex_unlock (&lock);		//Releasing Mutex Lock
            		break; 
        	} 
    }
}

int main(void)
{
	int error;
	if (pthread_mutex_init(&lock, NULL) != 0) 		//Initializing Mutex Lock
	{
		printf("Mutex init has failed\n");
		return 1;
	}

	for (int i=0; i<2; i++)				//Creating 2 Threads
	{
		error = pthread_create(&(tid[i]), NULL, &thread_function, NULL);
		if (error != 0)
			printf("Thread can't be created :[%s]", strerror(error));
	}

	pthread_join(tid[0], NULL);				//Joining 2 Threads
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);				//Destroying Mutex Locks

	return 0;
}

