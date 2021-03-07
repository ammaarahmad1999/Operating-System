#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global = 50;

void *my_thread(void *vargp)
{

    static int static_variable = 5;
    int local = 6;
    ++static_variable; 
    ++global;
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu, Static variable: %d, Global variable: %d, Local Non static variable %d\n", tid, static_variable, global, local);
    pthread_exit(NULL);		//terminating thread
}
int main(){

	pthread_t tid[10];
	int i;
	for(i=0;i<10;i++)
	{
		pthread_create(&tid[i],NULL,my_thread,NULL);
	}
	pthread_exit(NULL);	
	return 0;
}

static int varS = 0;
pthread_exit((void*)(&varS));
void* res;
pthread_join(Ts[i], &res);
int val = *(int *)res;
